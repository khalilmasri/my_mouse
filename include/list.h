#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#define MAP_DIMS 10 //1000x1000* would be max dimensions
#define MAP_INFO 15 //1000x1000* o12 would be max first line

//-----------------------------------------------------------------------------------------------

#ifndef STRUCT_H
#define STRUCT_H

typedef struct map_s 
{
    char **map; // 2D array of chars
    int **visited; // 2D array of ints
    int x_size; // x_size of the map
    int y_size; // y_size of the map
    int start[2];
    int steps;
    int size; // size of the map
} char_map;

typedef struct steps_l{
    int x_curr;
    int y_curr;
    int y_prev;
    int x_prev;
    //int layer;
    struct steps_l *next;
} steps;

#endif
//-----------------------------------------------------------------------------------------------
	
#ifndef MY_MOUSE_H
#define MY_MOUSE_H

char_map *get_start(char_map*);
steps* add_node(steps*, int, int, int, int); 
steps* check_available(char_map*, steps*, int, int);
steps *reverse_list(steps*);
char_map *draw_path(char_map*, steps*, int, int);
char_map *my_mouse(char_map*);

#endif
//-----------------------------------------------------------------------------------------------
	
#ifndef READ_MAP_H
#define READ_MAP_H

int check_valid_info(int);
int check_valid_map(char_map*, char*);
char_map *read_map_size(char*, char_map*);
char* get_info(char*);
char_map *read_map_into_array(char*, char_map*);
char_map *initialize_visited(char_map*);

#endif
//-----------------------------------------------------------------------------------------------
	
#ifndef UTILITY_H
#define UTILITY_H

void free_char_map(char_map*);
void print_char_map(char_map*);
void print_visited_map(char_map*);
void print_list(steps*);
void free_list(steps*);

#endif
//-----------------------------------------------------------------------------------------------
	
#ifndef REWRITE_H
#define REWRITE_H

void rewrite_map(char_map*, int, int);

#endif
