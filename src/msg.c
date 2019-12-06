#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include "msg.h"


msg_buffer_t * init_msg_buffer(unsigned int buffersize)
{
	msg_buffer_t * msg_buffer = (msg_buffer_t *) malloc(sizeof(msg_buffer_t));

	msg_buffer->consumer_n = 0;
	msg_buffer->buffersize = buffersize;
	msg_buffer->next       = 0;
	msg_buffer->last       = 0;
	msg_buffer->consumed   = (unsigned int *) malloc(sizeof(unsigned int) * buffersize);
	msg_buffer->size       = (size_t *)       malloc(sizeof(size_t)       * buffersize);
	msg_buffer->msg        = (void **)        malloc(sizeof(void *)       * buffersize);

	pthread_rwlock_init(&msg_buffer->subscribe_lock, NULL);
	pthread_rwlock_init(&msg_buffer->next_lock,      NULL);

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

	msg_buffer->next++;
	pthread_rwlock_unlock(&msg_buffer->next_lock);

	return;
}

msg_t * pull_msg(unsigned int * current)
{}

