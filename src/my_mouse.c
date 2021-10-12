#include "../include/list.h"

char_map *get_start(char_map *map){

    int index = 0;

    while(map->map[0][index] != '1')
        index++;

    map->start[0] = 0;
    map->start[1] = index;

    map->visited[map->start[0]][map->start[1]] = 1;

    return map;
}

steps *add_avaiable(int x_cur, int y_cur, int x_prev, int y_prev, int layer, steps *head){

    steps *list = head;

        while(list->next){
            list= list->next;
        }

        list->layer = layer;
        list->x_curr = x_cur;
        list->y_curr = y_cur;
        list->x_prev = x_prev;
        list->y_prev = y_prev;
        list->next = NULL;

        return head;
}


steps *check_avaiable(char_map *map, steps *head, int x, int y){

    static int layer = 1;

    if(x != 0){
    if(map->map[x+1][y] != '*' && map->visited[x+1][y] == 0){
        map->visited[x+1][y] = 1;
        head = add_avaiable(x+1,y,x,y,layer,head); 
        layer++;
    }
    if(map->map[x-1][y] != '*' && map->visited[x-1][y] == 0){
        map->visited[x-1][y] = 1;
        head = add_avaiable(x-1,y,x,y,layer,head); 
        layer++;
    }
    }
    if(y != 0){
    if(map->map[x][y+1] != '*' && map->visited[x][y+1] == 0){
        map->visited[x][y+1] = 1;
        head = add_avaiable(x,y+1,x,y,layer,head); 
        layer++;
    }
    if(map->map[x][y-1] != '*' && map->visited[x][y-1] == 0){
        map->visited[x][y-1] = 1;
        head = add_avaiable(x,y-1,x,y,layer,head); 
        layer++;
    }
    }

    return head;
}
//function to find shortest path through map
char_map *my_mouse(char_map *map)
{

    steps *list = malloc(sizeof(steps));
    map = get_start(map);

    int x = map->start[1],
        y = 0,
        i = 0;

    while(i != 30){
        list = check_avaiable(map, list, x, y);
        x = list->x_curr;
        y = list->y_curr;
        printf("x: %d y: %d\n", x,y);
        i++;
    }

    /* print_list(list); */
    printf("Start: {%d,%d}\n", map->start[0], map->start[1]);
    return map;
}
