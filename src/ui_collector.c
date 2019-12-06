#include "queue.h"

void * ui_collector(void * args)
{
	queue_t * ui_out = args;

	char * buffer = "Blah Blah";
	char * buffer2 = "Test 2";
	ui_out = push_queue(ui_out,buffer);
	ui_out = push_queue(ui_out,buffer2);
}

