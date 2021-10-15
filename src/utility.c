#include "../include/list.h"

void free_char_map(char_map *map)
{
    int i;
    for (i = 0; i < map->x_size; i++)
    {
        free(map->map[i]);
        free(map->visited[i]);
    }
    free(map->map);
    free(map->visited);
}

void print_char_map(char_map *map)
{
    int i, j;
    for (i = 0; i < map->x_size; i++)
    {
        for (j = 0; j < map->y_size; j++)
        {
            printf("%c", map->map[i][j]);
        }
        printf("\n");
    }
}

void print_visited_map(char_map *map)
{
    int i, j;
    for (i = 0; i < map->x_size; i++)
    {
        for (j = 0; j < map->y_size; j++)
        {
            printf("%d", map->visited[i][j]);
        }
        printf("\n");
    }
}

void print_list(steps *ptr)
{
    steps *temp = ptr;

    if (!temp)
        printf("list is empty");
    while (temp)
    {
        printf("x_curr: %d, ", temp->x_curr);
        printf("y_curr: %d, ", temp->y_curr);
        printf("x_prev: %d, ", temp->x_prev);
        printf("y_prev: %d\n", temp->y_prev);
        temp = temp->next;
    }
    printf("\n");
}

void free_list(steps *ptr)
{
    steps *temp;

    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}
