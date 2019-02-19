#include "my.h"

int *ints_size(char *size)
{
    int index = 0;
    int index2 = 0;
    char *width_str = malloc(sizeof(int) + 1);
    char *height_str = malloc(sizeof(int) + 1);
    int *map = malloc(sizeof(int) * 3);
    for (; size[index] != ' '; index++)
        width_str[index] = size[index];
    index++;
    for (; size[index] != '\0'; index++, index2++)
        height_str[index2] = size[index];
    map[0] = my_getnbr(width_str) - 1;
    map[1] = my_getnbr(height_str) - 1;
    return (map);
}

int *ints_pos(char *pos)
{
    int index = 0;
    int index2 = 0;
    char *x_str = malloc(sizeof(int) + 1);
    char *y_str = malloc(sizeof(int) + 1);
    int *coords = malloc(sizeof(int) * 3);
    for (; pos[index] != ' '; index++)
        x_str[index] = pos[index];
    index++;
    for (; pos[index] != ' '; index++, index2++)
        y_str[index2] = pos[index];
    coords[0] = my_getnbr(x_str);
    coords[1] = my_getnbr(y_str);
    return (coords);
}

char find_face(char *pos)
{
    int index = 0;
    for (; pos[index] != ' '; index++);
    index++;
    for (; pos[index] != ' '; index++);
    index++;
    return (pos[index]);
}

int main(int ac, char **av)
{
    struct stat file;
    int open_file = open(av[1], O_RDONLY);
    if (open_file == -1)
        exit(84);
    stat(av[1], &file);
    char *buffer = malloc(sizeof(char) * file.st_size + 1);
    read(open_file, buffer, file.st_size + 1);
    char **infos = my_strtowordarray(buffer);
    int *map = ints_size(infos[0]);
    int *pos = ints_pos(infos[1]);
    char facing = find_face(infos[1]);
    for (int i = 0; infos[2][i] != '\0' && infos[2][i] != '\n'; i++) {
        if (infos[2][i] == 'D') {
            if (facing == 'N')
                facing = 'E';
            else if (facing == 'E')
                facing = 'S';
            else if (facing == 'W')
                facing = 'N';
            else if (facing == 'S')
                facing = 'W';
        } else if (infos[2][i] == 'G') {
            if (facing == 'N')
                facing = 'W';
            else if (facing == 'E')
                facing = 'N';
            else if (facing == 'W')
                facing = 'S';
            else if (facing == 'S')
                facing = 'E';
        } else if (infos[2][i] == 'A') {
            if (facing == 'N') {
                if (pos[1] > 0)
                    pos[1]++;
            } else if (facing == 'E') {
                if (pos[0] < map[0])
                    pos[0]++;
            } else if (facing == 'W') {
                if (pos[0] > 0)
                    pos[0]--;
            } else if (facing == 'S') {
                if (pos[1] < map[1])
                    pos[1]--;
            }
        } else {
            write(2, "Invalid operation detected\n", 28);
            exit(84);
        }
    }
    char *x = malloc(sizeof(int) * 3);
    char *y = malloc(sizeof(int) * 3);
    sprintf(x, "%d", pos[0]);
    sprintf(y, "%d", pos[1]);
    printf("%s %s %c\n", x, y, facing);
}