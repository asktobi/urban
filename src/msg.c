#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include "msg.h"


msg_buffer_t * init_msg_buffer(unsigned int buffersize)
{
	int i;
	msg_buffer_t * msg_buffer = (msg_buffer_t *) malloc(sizeof(msg_buffer_t));

	msg_buffer->consumer_n = 0;
	msg_buffer->buffersize = buffersize;
	msg_buffer->next       = 0;
	msg_buffer->last       = 0;
	msg_buffer->poped_lock = (pthread_rwlock_t *)  malloc(sizeof(pthread_rwlock_t) * buffersize);
	msg_buffer->poped      = (unsigned int *)      malloc(sizeof(unsigned int)     * buffersize);
	msg_buffer->size       = (size_t *)            malloc(sizeof(size_t)           * buffersize);
	msg_buffer->msg        = (void **)             malloc(sizeof(void *)           * buffersize);


	pthread_cond_init(&msg_buffer->wait_last, NULL);
	pthread_mutex_init(&msg_buffer->wait_q,   NULL);

	pthread_rwlock_init(&msg_buffer->subscribe_lock, NULL);
	pthread_rwlock_init(&msg_buffer->next_lock,      NULL);
	pthread_rwlock_init(&msg_buffer->last_lock,      NULL);

	for (i = 0; i < buffersize; i++)
	{
		pthread_rwlock_init(&msg_buffer->poped[i], NULL);
	}


	return msg_buffer;
}


void push_msg(msg_buffer_t * msg_buffer, void * new_msg, size_t msg_size)
{
	void * msg = malloc(msg_size);
	memcpy(msg, new_msg, msg_size);
	
	pthread_rwlock_wrlock(&msg_buffer->next_lock);
	
	msg_buffer->consumed[msg_buffer->next] = 0;
	msg_buffer->size[msg_buffer->next] = msg_size;
	msg_buffer->msg[msg_buffer->next] = msg;

	msg_buffer->next = (msg_buffer->next + 1) % buffersize;
	
	pthread_rwlock_rdlock(&msg_buffer->last_lock);
	if (msg_buffer->next == msg_buffer->last);
	{
		pthread_rwlock_unlock(&msg_buffer->last_lock);
		pthread_cond_wait(&msg_buffer->wait_last, &msg_buffer->wait_q);

	}
	pthread_rwlock_unlock(&msg_buffer->next_lock);

	return;
}

msg_t * pop_msg(msg_buffer_t * msg_buffer, unsigned int * current)
{
	msg_t * msg;

	pthread_rwlock_rdlock(&msg_buffer->next_lock);
	if (current != msg_buffer->next)
	{
		pthread_rwlock_unlock(&msg_buffer->next_lock);
		
		msg = new_msg(msg_buffer->msg[current], msg_buffer->size[current]);
		
		pthread_rwlock_wrlock(&msg_buffer->poped_lock[current]);
		msg_buffer->poped[current]++;
		pthread_rwlock_unlock(&msg_buffer->poped_lock[current]);
		
		*current = (*current + 1 ) % msg_buffer->buffersize;


		return msg;

	}
	else if (current == msg_buffer->next)
	{
		return NULL; // Up to date !
	}

}

