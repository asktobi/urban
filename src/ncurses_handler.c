#include <ncurses.h>
#include "queue.h"


void * ncurses_handler( void * args )
{
	initscr();
	noecho();
	raw();
	
	char * buffer = NULL;
	printw("Testing");
	queue_t * ui_in = args;
	do
	{
		ui_in = get_queue(ui_in, buffer);
		printw("got : \"%s\"\n",buffer);
		getch();
	}while (1);

	endwin();
	return NULL;
}

