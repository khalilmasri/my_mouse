#include "../include/list.h"

long my_atoi(char *number_string, int size)
{
    int index = 0;
    long res = 0;
    while (index < size && number_string[index])
    {
        if (number_string[index] >= '0' && number_string[index] <= '9')
        {
            res *= 10;
            res += number_string[index] - '0';
        }
        index++;
    }
    return res;
}

void free_char_map(char_map map)
{
    int i;
    for (i = 0; i < map.x_size; i++)
    {
        free(map.map[i]);
        //free(map.visited[i]);
    }
    free(map.map);
    //free(map.visited);
}

void print_char_map(char_map map)
{
    int i, j;
    for (i = 0; i < map.x_size; i++)
    {
        for (j = 0; j < map.y_size; j++)
        {
            printf("%c", map.map[i][j]);
        }
        printf("\n");
    }
}

void print_visited_map(char_map map)
{
    int i, j;
    for (i = 0; i < map.x_size; i++)
    {
        for (j = 0; j < map.y_size; j++)
        {
            printf("%d", map.visited[i][j]);
        }
        printf("\n");
    }
}