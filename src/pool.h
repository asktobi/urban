#ifndef __POOL_H__
#define __POOL_H__

#include <pthread.h>


struct pool_t 
{	
	size_t            size;
	pthread_mutex_t **lock; 
	char            **name;
	void            **meta;
	void            **data;
};

struct pool_t * pool(size_t size);
void          * pool_add(char *name, void *data);
int             pool_ck(char *name);
void          * pool_get(char *name);
void            pool_del(char *name);




#endif
