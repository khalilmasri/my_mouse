#include "../include/list.h"

char_map *get_start(char_map *map)
{
    int index = 0;

    while(map->map[0][index] != '1')
        index++;

    map->start[0] = 0;
    map->start[1] = index;

    map->visited[map->start[0]][map->start[1]] = 1;

    return map;
}

steps* add_node(steps* head, int x_curr, int y_curr, int x_prev, int y_prev, int layer)
{
    //add node to end of linked list
    steps *new_node = (steps*)malloc(sizeof(steps));
    new_node->x_curr = x_curr;
    new_node->y_curr = y_curr;
    new_node->x_prev = x_prev;
    new_node->y_prev = y_prev;
    new_node->layer = layer;
    new_node->next = NULL;

    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        steps *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

steps* check_available(char_map *map, steps *head, int x, int y, int layer)
{

    int added = 0;
    if(map->map[x+1][y] != '*' && map->visited[x+1][y] == 0){
        map->visited[x+1][y] = 1;
        head = add_node(head, x+1, y, x, y, layer); 
        added++;
   }
    if(map->map[x-1][y] != '*' && map->visited[x-1][y] == 0){
        map->visited[x-1][y] = 1;
        head = add_node(head, x-1, y, x, y, layer); 
        added++;
    }
    if(map->map[x][y+1] != '*' && map->visited[x][y+1] == 0){
        map->visited[x][y+1] = 1;
        head = add_node(head, x, y+1, x, y, layer); 
        added++;
    }
    if(map->map[x][y-1] != '*' && map->visited[x][y-1] == 0){
        map->visited[x][y-1] = 1;
        head = add_node(head, x, y-1, x, y, layer); 
        added++;
    }
    printf("added node: %d\n", added);
    return head;
}

//function to find shortest path through map
char_map *my_mouse(char_map *map)
{
    //get pointer to head of linked list
    steps *head = NULL;
    get_start(map);
    int x_prev = map->start[0];
    int y_prev = map->start[1];
    int layer = 0;
    //int ret = 0;
    int x_curr = x_prev + 1;
    int y_curr = y_prev;

    //add start node to linked list
    head = add_node(head, x_curr, y_curr, x_prev, y_prev, layer);
    head = check_available(map, head, x_curr, y_curr, layer + 1);



    //get start node
    map = get_start(map);
    //condition
    // check_avaiable(map, list, x, y);
    print_list(head);
    free_list(head);
    return map;
}
