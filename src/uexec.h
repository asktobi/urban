#ifndef __UEXEC_H__
#define __UEXEC_H__

#include <sys/types.h>
#include <unistd.h>

// std_t-> 
struct std_t
{
	unsigned int open_io;
	sturct **io_t;

}


typedef struct uchild_t 
{
	pid_t pid;
	int argc;
	char **argv;
	struct std_t 

} uchild_t;

// Functions
uchild_t * uexec(uchild_t * child);






// spawns new children with a context and changes the 


#endif
