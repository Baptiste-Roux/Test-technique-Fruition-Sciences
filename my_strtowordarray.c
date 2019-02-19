/*
** EPITECH PROJECT, 2019
** my_strtowordarray.c
** File description:
** strtowordarray
*/

#include "my.h"

int line_len(char *str, int i)
{
    for (; str[i] != '\n'; i++);
    return (i);
}

int count_lines(char *str)
{
    int lines = 0;
    int count = 0;
    while (str[count] != '\0') {
        if (str[count] == '\n')
            lines++;
        count++;
    }
    return (lines);
}

char **my_strtowordarray(char *str)
{
    char **map;
    int l = 0;
    int j = 0;
    int k = 0;
    map = malloc(sizeof(char *) * count_lines(str) + 1);

    for (; j <= count_lines(str); j++)
        map[j] = malloc(sizeof(char) * line_len(str, j) + 1);
    for (j = 0; j <= count_lines(str); j++) {
        for (; str[k] != '\n' && str[k] != '\0'; k++) {
            map[j][l] = str[k];
            l++;
        }
        l = 0;
        k++;
    }
    return (map);
}