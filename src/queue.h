#ifndef __QUEUE_H__
#define __QUEUE_H__
// 1-to-1 queues

#include <pthread.h>

#include <data.h>

// Structs

typedef struct QUEUE_ELEMENT_T
{
	data_t                 * data;
	pthread_mutex_t          lock;
	struct QUEUE_ELEMENT_T * next;

} queue_e_t;


typedef struct QUEUE_T
{
	pthread_mutex_t          lock;
	struct QUEUE_ELEMENT_T * root;

} queue_t;

// Functions

queue_e_t * new_queue_e(data_t * data);
queue_t   * new_queue();

void   push_queue(queue_t * q, data_t * data);
void * pull_queue(queue_t * q);

#endif
