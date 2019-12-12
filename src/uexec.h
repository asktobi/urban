#ifndef __UEXEC_H__
#define __UEXEC_H__

#include <sys/types.h>
#include <unistd.h>

typedef struct uchild_t 
{
	pid_t pid;
	int argc;
	char **argv;


} uchild_t;

// Functions
uchild_t * uexec(uchild_t * child);






// spawns new children with a context and changes the 
uchild_t

#endif
