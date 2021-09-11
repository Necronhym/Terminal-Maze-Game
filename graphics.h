#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

void render(int x, int y, char arr[x][y][3])
	{
		for(int j=0; j<y; j++)
			{
				for(int i=0; i<x; i++)
					{
						//Set color
						printf("\033[%i;%im", (int)arr[i][j][1], (int)arr[i][j][2]);
						printf("%c", arr[i][j][0]);
					}
				printf("\r\n");
			}
		//Reset Colors
		printf("\e[m");
	}
void clear()
	{    
		printf("\e[1;1H\e[2J");
	}
#endif
