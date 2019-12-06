#ifndef __QUEUE_C__
#define __QUEUE_C__
// 1-to-1 queues

#include <pthread.h>
#include <stdlib.h>
#include "queue.h"

queue_t * new_queue(void * data)
{
	queue_t * new_queue = (queue_t *) malloc(sizeof(queue_t));
	new_queue->data = data;
	pthread_mutex_init(&new_queue->lock, NULL);
	new_queue->next = NULL;

	return new_queue;
}

void free_queue(queue_t * queue)
{
	pthread_mutex_destroy( &queue->lock );
	free(queue);
}

queue_t * push_queue(queue_t * queue, void * data)
{
	pthread_mutex_lock(   &queue->lock );
	queue->next = new_queue(data);
	pthread_mutex_unlock( &queue->lock );

	return queue->next;
}

queue_t * get_queue(queue_t * queue, void * data)
{
	pthread_mutex_lock(&queue->lock);
	
	if (queue->next != NULL)
	{
		queue_t * new_queue = queue->next;
		free_queue(queue);
		data = new_queue->data;
		return new_queue;
	}
	
	pthread_mutex_unlock(&queue->lock);
	return queue;
}


#endif
