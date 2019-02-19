/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char *str)
{
    int result = 0;
    int i = 0;
    int a = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            a++;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        result = result * 10;
        result = result + str[i++] - '0';
    }
    if (result < -2147483647 || result > 2147483647)
        return (0);
    return ((a%2 == 1) ? result * (-1) : result);
}