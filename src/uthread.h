#ifndef __UTHREAD_H
#define __UTHREAD_H

typedef struct u_thread 
{
	char * name;
	void *(service)(void *);

} uthread_t;


#endif
