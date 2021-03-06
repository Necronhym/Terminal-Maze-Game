#ifndef INPUT_H
#define INPUT_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

struct termios orig_termios;

void reset_terminal_mode()
	{
		tcsetattr(0, TCSANOW, &orig_termios);
	}
void set_conio_terminal_mode()
	{
		struct termios new_termios;
		tcgetattr(0, &orig_termios);
		memcpy(&new_termios, &orig_termios, sizeof(new_termios));
		atexit(reset_terminal_mode);
		cfmakeraw(&new_termios);
		tcsetattr(0, TCSANOW, &new_termios);
	}
int input()
	{
		struct timeval tv = { 0L, 0L };
		fd_set fds;
		FD_ZERO(&fds);
		FD_SET(0, &fds);
		return select(1, &fds, NULL, NULL, &tv);
	}
char getInput()
	{
		int r;
		unsigned char c;
		if((r = read(0, &c, sizeof(c))) < 0) 
			{
				return r;
    			}
		else
			{
				return c;
			}
	}
void initInput()
	{
		set_conio_terminal_mode();
	}
void exitInput()
	{
		reset_terminal_mode();
		system("tput init");
	}
#endif
