#ifndef __QUEUE_H__
#define __QUEUE_H__
// 1-to-1 queues

#include <pthread.h>

typedef struct QUEUE_T
{
	void * data;
	pthread_mutex_t lock;
	struct QUEUE_T * next;
} queue_t;

// Functions

queue_t * new_queue(void * data);
void free_queue(queue_t * queue);
queue_t * push_queue(queue_t * queue, void * data);
queue_t * get_queue(queue_t * queue, void * data);


#endif
