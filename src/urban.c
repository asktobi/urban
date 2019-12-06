#include <pthread.h>
#include <stdlib.h>

#include "queue.h"
#include "uthreads.h"


int main(int argc, char **argv)
{
	pthread_t ncurses_thread;
	pthread_t ui_collector_thread;

	queue_t * ui_q = new_queue(NULL);

	pthread_create(&ncurses_thread, NULL, ncurses_handler, ui_q);
	pthread_create(&ui_collector_thread, NULL, ui_collector, ui_q);

	pthread_join(ncurses_thread, NULL);
	pthread_join(ui_collector_thread, NULL);

	return 0;
}
