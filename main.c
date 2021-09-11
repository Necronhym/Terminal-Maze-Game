#include "graphics.h"
#include "input.h"
#include "deltatime.h"
#include "map.h"
int main(int argc, char* argv[])
	{
		int w=80;
	       	int h=24;
		//Map variables:
		if(argc == 3)
			{
				w = atoi(argv[1]);
				h = atoi(argv[2]);
			}
		char map[w][h][3];
		//Player Variables	
		int px = w/2;
		int py = h/2;	
		//Input Variable
		char in = '\0';
		//generate Map
		//Initialization:
		initDeltaTime();
		initInput();
		initMapGenerator();
		while(1)
			{
				generateMap(w, h, map, px, py);	
				int xx = (rand()%(w/2 -1) + 1) * 2;
				int xy = (rand()%(h/2 -1) + 1) * 2;
				map[xx][xy][0] = 'X';
				map[xx][xy][1] = 31;
				map[xx][xy][2] = 0;
				while(1)
					{
						//get user input:
 						while(!input()) 	
							{
								//phisics/game logic:
								
								clear();
								//Store previous map item
								char T[3] = 
									{	
										map[px][py][0],
										map[px][py][1],
										map[px][py][2]
									};	
								//Show player
								map[px][py][0] = 'P';
								map[px][py][1] = 40;
								map[px][py][2] = 36;
						
								render(w, h, map);
								//Put back previous map object
								map[px][py][0] = T[0];
								map[px][py][1] = T[1];
								map[px][py][2] = T[2];
    						
								//delta time:
								updateDeltaTime();
							}

						in = getInput();
						//Process input
						switch(in)
							{
								case('w'):
									if(map[px][py-1][0] != '#')
										{
											py--;
										}
								break;
								case('s'):
									if(map[px][py+1][0] != '#')
										{
											py++;
										}
								break;
								case('a'):
									if(map[px-1][py][0] != '#')
										{
											px--;
										}
								break;
								case('d'):
									if(map[px+1][py][0] != '#')
										{
											px++;
										}
								break;
								case('q'):
									exitInput();
									exit(0);
								break;
							}
						if(xx == px && py == xy)
							{
								break;
							}
					}
			}
		return 0;
	}
