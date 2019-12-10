#ifndef __TS_BUFFER__
#define __TS_BUFFER__

#include <stdint.h>

// Threadsafe 



typedef struct MSG_T
{
	size_t  size;
	uint8_t msg[0];
	
} msg_t;

typedef struct MSG_BUFFER_T
{
	pthread_rwlock_t subscribe_lock;
	unsigned int     consumer_n; // The number of consumers
	unsigned int     buffersize; // The number of slots
	
	// This is for making a pushing thread wait till msg[last]
	// was cleared by the last thread accessing it
	pthread_cond_t   wait_last; 
	pthread_mutex_t  wait_q;

	pthread_rwlock_t next_lock;
	unsigned int     next; // The next element to push to
	pthread_rwlock_t last_lock;
	unsigned int     last; // The last element not consumed by all

	pthread_rwlock_t * poped_lock;
	unsigned int     * poped; // The number of consumers that got the msg
	size_t           * size; // The size of the data
	uint8_t         ** msg; // The pointer to the data
} msg_buffer_t;

msg_buffer_t * init_msg_buffer(unsigned int buffersize);
msg_t * new_msg(void * msg, size_t msg_size);
void push_msg(msg_buffer_t * msg_buffer, void * msg, size_t msg_size);
msg_t * pop_msg(msg_buffer_t * msg_buffer, unsigned int * current);



#endif
