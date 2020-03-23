#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>

typedef struct file_t
{
	char path;
	char ***file;


} file_t;

typedef struct line_t 
{
	char  * str_buffer;
	char ** line_buffer;
	
	size_t str_max    
	size_t line_max; 
	size_t str_length;
	size_t line_length;

} line_t;

line_t * new_line(size_t line_max, size_t str_max)
{
	line_t * line = (line_t *) malloc(sizeof(line_t));
	line->str_max     = 256;
	line->line_max     = 256;
	line->str_length  = 0;
	line->line_length  = 0;

	line->line_buffer = malloc

	return line;
}

int main(int argc,char ** argv)
{
	WINDOW * win;

	int in;
	char * str_buffer;
	char ** line_buffer;
	
	size_t str_max     = 256, line_max     = 256;
	size_t str_current = 0,   line_current = 0;
	size_t str_length  = 0,   line_length  = 0;

	win = initscr();
	noecho();
	raw();
	
	str_buffer  = (char *)  malloc(sizeof(char  ) * str_max );
	line_buffer = (char **) malloc(sizeof(char *) * line_max);


	while(1)
	{
		in = getch();
		
		if (in > 41 && in < 126) 
		{
			str_buffer[str_current]   = (char) in;
			printw("%c", str_buffer[str_current]);

		} else
		{
			switch(in)
			{
				case '\n': //Enter
					
					if (line_buffer[line_current] == NULL)
					{
						str_length = strlen(str_buffer);
						line_buffer[line_current] = (char *) malloc(sizeof(char) * str_length);
						memcpy(line_buffer[line_current], str_buffer, str_length);
						
						line_current++;
						printw("\n");

					} else
					{
						printw("TODO: implement word shifting \n");

					}
					break;

				case ' ': //New word

					if (line_buffer[line_current] == NULL)
					{
						str_length = strlen(str_buffer);
						line_buffer[line_current] = (char *) malloc(sizeof(char) * str_length);
						memcpy(line_buffer[line_current], str_buffer, str_length);

						line_current++;
						printw(" ");

					} else
					{
						printw("TODO: implement word shifting \n");

					}
					break;
				case 3: //STRG-C
					echo();
					endwin;
					return 0;
					
				default:
						
					printw("\n[%s] Cant interprete : %d -> '%c'\n", argv[0], in, (char) in );
					break;
			}
		}
		
	}
}
