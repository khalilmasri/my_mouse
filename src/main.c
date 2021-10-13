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
            printf("Please input a correct map name and/or path.\n");
            return 1;
        }

        if(check_valid_info(fd) != true){
            printf("MAP ERROR: Non valid Map\n");
            return 1;
        }
        char_map *map = malloc(sizeof(char_map));
        map = read_map_size(argv[1], map);
        map = read_map_into_array(argv[1], map);

        map = my_mouse(map);
        print_char_map(map);
        printf("%d STEPS!\n", map->steps);
        free_char_map(map);
    }

    return 0;
}
