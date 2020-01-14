#ifndef __UALLOC_H__
#define __UALLOC_H__


#include <stdlib.h>
#include <pthread.h>


struct page_t
{
	size_t  size;
	pthread_mutex_t used_lock;
	size_t  used;
	pthread_rwlock_t using;
	uint8_t data[0];
};




#endif
