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

bool check_valid_info(int fd){
    int i = 0,
        number_y = 0,
        number_x = 0;
    char buffer[MAP_INFO];

    read(fd, buffer, MAP_INFO);
    buffer[14] = '\0';

    while(buffer[i] != 'x' && buffer[i] != '\0'){
            number_x = number_x * 10 + (buffer[i] - '0');
            i++;
    }
    if(buffer[i] != 'x') return false;
    i++;
    while(buffer[i] != '*' && buffer[i] != '\0'){
            number_y = number_y * 10 + (buffer[i] - '0');
            i++;
    }

    if(number_y >= 1000 || number_x >= 1000 || buffer[i] != '*') return false;

    if(buffer[i] == ' ' && buffer[i+1] == 'o' && buffer[i+2] == '1' && buffer[i+3] == '2') return false;

    return true;
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
