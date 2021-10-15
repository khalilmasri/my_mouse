#include "../include/list.h"

int check_valid_info(int fd)
{
    int i = 0, number_y = 0, number_x = 0;
    char buffer[MAP_INFO];

    read(fd, buffer, MAP_INFO);
    buffer[14] = '\0';
    while(buffer[i] != 'x' && buffer[i] != '\0'){
            number_x = number_x * 10 + (buffer[i] - '0');
            i++;
    }
    if(buffer[i] != 'x') return 1;
    i++;
    while(buffer[i] != '*' && buffer[i] != '\0'){
            number_y = number_y * 10 + (buffer[i] - '0');
            i++;
    }
    if(number_y > 1000 || number_x > 1000 || buffer[i] != '*') return 1;
    i++;
    if(buffer[i] == ' ' && buffer[i+1] == 'o' && buffer[i+2] == '1' && buffer[i+3] == '2') return 0;

    return 1;
}

int check_valid_map(char_map *map, char* map_file)
{
    int fd = open(map_file, O_RDONLY);
    int info_size = strlen(get_info(map_file));
    char* info = malloc(info_size + 1);
    strcpy(info, get_info(map_file));
    int i = 0, j = 0, entry = 0, end = 0;
    char* buffer = malloc(map->y_size + 1);
    read(fd, info, info_size + 1); //bypass info 
    while((read(fd, buffer, map->y_size + 1) > 0))
    {
        j = 0;
        buffer[map->y_size] = '\0';
        while(j < map->y_size)
        {
            if(buffer[j] != ' ' && buffer[j] != '*' && buffer[j] != '1' && buffer[j] != '2')
                return 1; //if map not made up of valid characters
            if(buffer[j] == '1')
                entry++;
            if(buffer[j] == '2')
                end++;
            j++;
        }
        i++;
    }
    if (i > map->x_size || entry > 1 || end > 1)
        return 1; //if map not stated size or more than 1 entry or end point
    
    free(buffer);
    free(info);
    return 0;
}

char_map *read_map_size(char* map_file, char_map *map)
{
    
    int i = 0;
    char map_dims[MAP_DIMS] = "**********"; //cant fill with 0's because would y_size value
    int fd = open(map_file, O_RDONLY);
    read(fd, map_dims, MAP_DIMS);
    map->y_size = 0;
    map->x_size = 0;
    map_dims[strlen(map_dims) - 1] = '\0';
    //get x and y dimensions
    while(map_dims[i] != 'x')
    {
            map->x_size = map->x_size * 10 + (map_dims[i] - '0');
            i++;
    }
    i++;
    while(map_dims[i] != '*')
    {
            map->y_size = map->y_size * 10 + (map_dims[i] - '0');
            i++;
    }

    map->size = map->x_size * map->y_size;
    return map;
}

//function to read size of first line in file
char* get_info(char *map_file)
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
    close(fd);
    return line;
}

//read map into buffer then to the map struct
char_map *read_map_into_array(char* map_file, char_map *map)
{
    int size = map->size;
    int info_size = strlen(get_info(map_file));
    map->size = size;
    char* buffer = malloc(sizeof(char) * (map->y_size + 1));
    char* first_line = malloc(sizeof(char) * (info_size + 1));
    
    map->map = malloc(sizeof(char) * size);
    int i, j, k;
    int fd = open(map_file, O_RDONLY);
    read(fd, first_line, info_size + 1); //read the first line to bypass it
    for (i = 0; i < map->x_size; i++) //read the map into the array
    {   
        read(fd, buffer, (map->y_size + 1));
        k = 0;
        map->map[i] = malloc(sizeof(char) * (map->y_size));
        for (j = 0; j < map->y_size; j++)
        {
            if(buffer[k] == '\n')
                k++;
            map->map[i][j] = buffer[k];
            k++;
        }
    }
    close(fd);
    free(buffer);
    free(first_line);
    map = initialize_visited(map);
    return map;
}

char_map *initialize_visited(char_map *map)
{
    int i, j;
    map->visited = malloc(sizeof(int *) * map->x_size);
    for (i = 0; i < map->x_size; i++)
    {
        map->visited[i] = malloc(sizeof(int) * map->y_size);
        for (j = 0; j < map->y_size; j++)
        {
            map->visited[i][j] = 0;
        }
    }
    return map;
}