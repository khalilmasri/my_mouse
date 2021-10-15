#include "../include/list.h"

int main(int argc, char **argv)
{
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
            printf("Please input a correct map filename and/or path.\n");
            return 1;
        }
        
        if(check_valid_info(fd) != 0){
            printf("MAP ERROR: Non Valid Map Info\n");
            return 1;
        }
        char_map *map = malloc(sizeof(char_map));
        map = read_map_size(argv[1], map);
    
        if(check_valid_map(map, argv[1]) != 0){
            printf("MAP ERROR: Non Valid Map (Map doesnt match Map Info!)\n");
            return 1;
        }

        map = read_map_into_array(argv[1], map);

        if((map = my_mouse(map)) == NULL)
        {
            printf("MAP ERROR: No Path To Exit!\n");
            return 1;
        }
        else
        {
        print_char_map(map);
        printf("%d STEPS!\n", map->steps);
        free_char_map(map);
        }
    }
    return 0;
}