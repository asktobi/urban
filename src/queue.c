#ifndef __QUEUE_C__
#define __QUEUE_C__
// 1-to-1 queues

#include <pthread.h>
#include <stdlib.h>
#include "queue.h"

queue_e_t * new_queue_e(data_t * data)
{
	queue_e_t * new_q_e = (queue_e_t *) malloc(sizeof(queue_e_t));
	pthread_mutex_init( &new_q_e->lock, NULL);
	new_q_e->data       = data;
	new_q_e->next       = NULL;

	return new_q_e;
}


queue_t * new_queue()
{
	queue_t * new_q = (queue_t *) malloc(sizeof(queue_t));
	pthread_mutex_init(&new_q->lock, NULL);
	new_q->root = NULL;

	return new_q;
}

void push_queue(queue_t * q, data_t * data)
{
	pthread_mutex_lock(&q->lock);


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
