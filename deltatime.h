#ifndef DELTATIME_H
#define DELTATIME_H

#include <sys/time.h>

struct timeval old, new;
int fps = 15;

void initDeltaTime()
	{
		gettimeofday(&old, NULL);
		gettimeofday(&new, NULL);
	}
	
void updateDeltaTime()
	{
		gettimeofday(&new, NULL);
		usleep((1000000/fps) - ((new.tv_usec - old.tv_usec)/1000));	
		old = new;
	}
#endif
