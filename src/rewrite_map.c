#include "../include/list.h"

/* int check_closest(char_map *map, int x, int y){ */

/*     int counter = 0, */
/*         default_y = y, */
/*         flag_y; */

/*     while(counter != 2){ */
/*         if(map->visited[x][y] == 1){ */
/*             if(counter == 0) */
/*                 flag_y = y; */
/*             counter++; */
/*         } */
/*         if(counter == 0) */
/*             y++; */
/*         else if(counter == 1) */
/*             y--; */
/*     } */

/*     if((flag_y -default_y) < (default_y - y+1)) */
/*         return flag_y; */
/*     else */ 
/*         return y; */
/* } */

/* char_map *modify_visited(char_map *map){ */
        
/*     int x = 1, */ 
/*         y = map->start[1], */
/*         prev_y; */

/*     while(x < map->x_size){ */
/*         switch(map->visited[x][y]){ */
/*             case 1: */
/*                 map->visited[x][y] = 2; */
/*                 break; */
/*             case 0: */
/*                 prev_y = y; */
/*                 y = check_closest(map, x, y); */
/*                 map->visited[x][y] = 2; */
/*                 while(y != prev_y){ */
/*                     if(y > prev_y){ */
/*                         map->visited[x-1][y] = 2; */
/*                         prev_y++; */
/*                     }else{ */
/*                         map->visited[x-1][y] = 2; */
/*                         prev_y--; */
/*                     } */
/*                 } */
/*                 break; */
/*         } */
/*         x++; */
/*     } */

/*     /1* return map; *1/ */
/* } */

bool check_surround(char_map *map, int x, int y){

    if(map->visited[x][y] == 0 || map->visited[x+1][y] == 0 || map->visited[x-1][y] == 0 || map->visited[x][y+1] == 0 || map->visited[x][y-1] == 0)
        return true;
    else 
        return false;
}

void rewrite_map(char_map *map, int x, int y){

    printf("x: %d y: %d\n", x,y);

    while(x != 0){
        if(check_surround(map, x,y) == true){

        }
    }
    /* print_char_map(map); */
}
