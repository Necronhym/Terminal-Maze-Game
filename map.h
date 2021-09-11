#ifndef MAP_H
#define MAP_H

#include <time.h>
void shuffle(int *array, size_t n)
	{
		if (n > 1) 
			{
				size_t i;
				for (i = 0; i < n - 1; i++) 
					{
						size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
						int t = array[j];
						array[j] = array[i];
						array[i] = t;
					}
			}
	}
void makeEmptyMap(int w, int h, char map[w][h][3])
	{
		for(int j=0; j<h; j++)
			{
				for(int i=0; i<w; i++)
					{
						map[i][j][0] = '0';
						map[i][j][1] = 0;
						map[i][j][2] = 37;

						//Sets map borders
						if(i==0 || i==w-1)
							{
								map[i][j][0] = '#';
								map[i][j][1] = 47;
								map[i][j][2] = 37;
							}
						if(j==0 || j==h-1)
							{
								map[i][j][0] = '#';
								map[i][j][1] = 47;
								map[i][j][2] = 37;
							}
					}
			}
	}
void makeMap(int w, int h, char map[w][h][3], int x, int y)
	{
		map[x][y][0] = '.';
		int temp[4];
		int size=0;

		//	N = 1;
		if(map[x][y-2][0] == '0' && y-2 > 0)
			{
				temp[size] = 1;
				size++;
			}
		//	E = 2;
		if(map[x+2][y][0] == '0' && x+2 < w)
			{
				temp[size] = 2;
				size++;
			}
		//	S = 3;
		if(map[x][y+2][0] == '0' && y+2 < h)
			{
				temp[size] = 3;
				size++;
			}
		//	W = 4;
		if(map[x-2][y][0] == '0' && x-2 > 0)
			{
				temp[size] = 4;
				size++;
			}
		int arr[size];	
		for(int i=0; i<size; i++)
			{
				arr[i] = temp[i];
			}
		shuffle(arr, size);
		for(int i=0; i<size; i++)
			{
				switch(arr[i])
					{	
						case(1):
							map[x][y-1][0] = '.';
							makeMap(w, h, map, x, y-2);
						break;
						case(2):
							map[x+1][y][0] = '.';
							makeMap(w, h, map, x+2, y);
						break;
						case(3):
							map[x][y+1][0] = '.';
							makeMap(w, h, map, x, y+2);
						break;
						case(4):
							map[x-1][y][0] = '.';
							makeMap(w, h, map, x-2, y);
						break;
					}
				makeMap(w, h, map, x, y);
				break;
			}
	}
void initMapGenerator()
	{
		srand(time(NULL));
	}
void makeWalls(int w, int h, char map[w][h][3])
	{
		for(int j=0; j<h; j++)
			{
				for(int i=0; i<w; i++)
					{
						if(map[i][j][0] == '0')
							{
								map[i][j][0] = '#';
								map[i][j][1] = 47;
								map[i][j][2] = 37;
							}
					}
			}
	}
void generateMap(int w, int h, char map[w][h][3], int x, int y)
	{
		makeEmptyMap(w, h, map);
		makeMap(w, h, map, x, y);
		makeWalls(w, h, map);
	}

#endif
