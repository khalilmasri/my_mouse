#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#define MAP_DIMS 10 //1000x1000* would be max dimensions
#define MAP_INFO 14 //1000x1000* o12 would be max first line

//-----------------------------------------------------------------------------------------------

#ifndef STRUCT_H
#define STRUCT_H

typedef struct map_s 
{
    char **map; // 2D array of chars
    int **visited; // 2D array of ints
    int x_size; // x_size of the map
    int y_size; // y_size of the map
    int size; // size of the map
} char_map;

#endif
//-----------------------------------------------------------------------------------------------
	
#ifndef MY_MOUSE_H
#define MY_MOUSE_H


#endif
//-----------------------------------------------------------------------------------------------
	
#ifndef READ_MAP_H
#define READ_MAP_H

char_map read_map_size(char*);
int get_info_size(char*);
char_map read_map_into_array(char*, char_map);
char_map initialize_visited(char_map);

#endif
//-----------------------------------------------------------------------------------------------
	
#ifndef UTILITY_H
#define UTILITY_H

long my_atoi(char*, int);
void free_char_map(char_map);
void print_char_map(char_map);
void print_visited_map(char_map);

#endif
