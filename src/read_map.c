#include "../include/list.h"

char_map read_map_size(char* map_file)
{
    int i = 0;
    char_map char_map;
    char map_dims[MAP_DIMS] = "**********"; //cant fill with 0's because would y_size value
    int fd = open(map_file, O_RDONLY);
    read(fd, map_dims, MAP_DIMS);
    map_dims[strlen(map_dims) - 1] = '\0';
    //get x and y dimensions
    while(map_dims[i] != 'x')
    {
            char_map.x_size = char_map.x_size * 10 + (map_dims[i] - '0');
            i++;
    }
    i++;
    while(map_dims[i] != '*')
    {
            char_map.y_size = char_map.y_size * 10 + (map_dims[i] - '0');
            i++;
    }
    char_map.size = char_map.x_size * char_map.y_size;
    printf("Map dims = x: %d y: %d, size: %d\n", char_map.x_size, char_map.y_size, char_map.size);
    return char_map;
}

//function to read size of first line in file
int get_info_size(char *map_file)
{
    int i = 0;
    int fd = open(map_file, O_RDONLY);
    char* line = malloc(sizeof(char) * MAP_INFO);
    read(fd, line, MAP_INFO);
    while (line[i] != '\n')
    {
        i++;
    }
    line[i] = '\0';
    //printf("firstline: %s\n", line);
    close(fd);
    //printf("first line size: %lu\n", strlen(line));
    return strlen(line);
}

//read map into buffer then to the map struct
char_map read_map_into_array(char* map_file, char_map map)
{
    int size = map.size;
    int info_size = get_info_size(map_file);
    map.size = size;
    char* buffer = malloc(sizeof(char) * (map.y_size + 1));
    char* first_line = malloc(sizeof(char) * (info_size + 1));
    
    map.map = malloc(sizeof(char) * size);
    int i, j, k;
    int fd = open(map_file, O_RDONLY);
    read(fd, first_line, info_size + 1); //read the first line to bypass it
    for (i = 0; i < map.x_size; i++) //read the map into the array
    {   
        read(fd, buffer, (map.y_size + 1));
        k = 0;
        map.map[i] = malloc(sizeof(char) * (map.y_size));
        for (j = 0; j < map.y_size; j++)
        {
            if(buffer[k] == '\n')
                k++;
            map.map[i][j] = buffer[k];
            k++;
        }
    }
    close(fd);
    free(buffer);
    free(first_line);
    //initialize_visited(map);
    return map;
}

char_map initialize_visited(char_map map)
{
    int i, j;
    map.visited = malloc(sizeof(int *) * map.x_size);
    for (i = 0; i < map.x_size; i++)
    {
        map.visited[i] = malloc(sizeof(int *) * map.y_size);
        for (j = 0; j < map.y_size; j++)
        {
            map.visited[i][j] = 0;
        }
    }
    return map;
}










