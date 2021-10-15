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

steps* add_node(steps* head, int x_curr, int y_curr, int x_prev, int y_prev)
{
    //add node to end of linked list
    steps *new_node = (steps*)malloc(sizeof(steps));
    new_node->x_curr = x_curr;
    new_node->y_curr = y_curr;
    new_node->x_prev = x_prev;
    new_node->y_prev = y_prev;
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

steps* check_available(char_map *map, steps *head, int x, int y)
{

    int added = 0;
    //check below
    if(map->map[x+1][y] != '*' && map->visited[x+1][y] == 0){
        map->visited[x+1][y] = 1;
        head = add_node(head, x+1, y, x, y); 
        added++;
    }
    //check left
    if(map->map[x][y-1] != '*' && map->visited[x][y-1] == 0){
        map->visited[x][y-1] = 1;
        head = add_node(head, x, y-1, x, y); 
        added++;
    }
    //check right
    if(map->map[x][y+1] != '*' && map->visited[x][y+1] == 0){
        map->visited[x][y+1] = 1;
        head = add_node(head, x, y+1, x, y); 
        added++;
    }
    //check above
    if(map->map[x-1][y] != '*' && map->visited[x-1][y] == 0){
        map->visited[x-1][y] = 1;
        head = add_node(head, x-1, y, x, y); 
        added++;
    }
    return head;
}

steps *reverse_list(steps *head) 
{
    steps *new_head = NULL, *current = head;

    // Reverse the link list O(n) time O(1) space
    while(current)
    {
        head = head->next;
        current->next = new_head;
        new_head = current;
        current = head;
    }

    return new_head;
}

char_map *draw_path(char_map *map, steps *head, int x, int y)
{
    steps *temp = head;

    int counter = 0;

    while(temp)
    {
        if(temp->x_curr == x && temp->y_curr == y)
        {
            if(map->map[x][y] != '2')
            {
                map->map[x][y] = 'o';
                counter++;
            }
            x = temp->x_prev;
            y = temp->y_prev;
            temp = temp->next;
        }
        else
        {
            temp = temp->next;
        }
    }

    map->steps = counter;

    return map;
}

//function to find shortest path through map
char_map *my_mouse(char_map *map)
{
    steps *head = NULL;
    steps *temp = NULL;
    
    get_start(map);
    int x_prev = map->start[0];
    int y_prev = map->start[1];
    int x_curr = x_prev + 1;
    int y_curr = y_prev;

    map->visited[x_curr][y_curr] = 1; //set as visited & add start node to linked list
    head = add_node(head, x_curr, y_curr, x_prev, y_prev);
    temp = head;
    
    while(map->map[temp->x_curr][temp->y_curr] != '2' && temp != NULL)
    {
        x_curr = temp->x_curr;
        y_curr = temp->y_curr;
        head = check_available(map, head, x_curr, y_curr);
        temp = temp->next;
        if(temp == NULL)
        {
            break;
        }
    }
    if(temp != NULL)
    {   
        head = reverse_list(head); 
        map = draw_path(map, head, temp->x_curr, temp->y_curr); 
        free_list(head);
        return map;
    }
    free_char_map(map); //free map before returning it as NULL!
    free_list(head);    //free linked list in both cases!!
    return NULL;
}
