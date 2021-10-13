#include "../include/list.h"

int main(int argc, char **argv)
{
    //write code here
    if (argc != 2)
    {
        printf("Usage: ./my_mouse <map file>\n");
        return 1;
    }
    else
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
            printf("Please input a correct a map name and path.\n");
            return 1;
        }
        char_map *map = malloc(sizeof(char_map));
        map = read_map_size(argv[1], map);
        map = read_map_into_array(argv[1], map);

        map = my_mouse(map);
        //print map with path
        printf("shortest path:\n");
        print_char_map(map);
        //print_visited_map(map);
        free_char_map(map);
    }

    return 0;
}
