#include "../include/list.h"

int main(int argc, char **argv)
{
    //write code here
    if (argc < 2)
    {
        printf("Usage: ./my_mouse <map file>\n");
        return 1;
    }
    else
    {
        char_map *map = malloc(sizeof(char_map));
        map = read_map_size(argv[1], map);
        map = read_map_into_array(argv[1], map);

        //print input map
        printf("input map\n");
        print_char_map(map);
        //run algorithm
        map = my_mouse(map);
        //print map with path
        printf("shortest path:\n");
        print_char_map(map);
        //print_visited_map(map);
        free_char_map(map);
    }

    return 0;
}
