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
    //check below
    if(map->map[x+1][y] != '*' && map->visited[x+1][y] == 0){
        map->visited[x+1][y] = 1;
        head = add_node(head, x+1, y, x, y, layer); 
        added++;
    }
    //check above
    if(map->map[x-1][y] != '*' && map->visited[x-1][y] == 0){
        map->visited[x-1][y] = 1;
        head = add_node(head, x-1, y, x, y, layer); 
        added++;
    }
    //check right
    if(map->map[x][y+1] != '*' && map->visited[x][y+1] == 0){
        map->visited[x][y+1] = 1;
        head = add_node(head, x, y+1, x, y, layer); 
        added++;
    }
    //check left
    if(map->map[x][y-1] != '*' && map->visited[x][y-1] == 0){
        map->visited[x][y-1] = 1;
        head = add_node(head, x, y-1, x, y, layer); 
        added++;
    }
    printf("count of nodes added to list at check: %d\n", added);
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
    int x_curr = x_prev + 1;
    int y_curr = y_prev;

    //set as visited & add start node to linked list
    map->visited[x_curr][y_curr] = 1;
    head = add_node(head, x_curr, y_curr, x_prev, y_prev, layer);
    
    //NEED TO FIGURE LOOP LOGIC FOR CHECKING AVAILABLE NODES FROM HERE

    //a test of checking available around the first node
    head = check_available(map, head, x_curr, y_curr, layer + 1);
    
    printf("linked list contents:\n");
    print_list(head);
    //check if visited has been altered after checking node
    printf("visited array contents:\n");
    print_visited_map(map);
    free_list(head);
    return map;
}
