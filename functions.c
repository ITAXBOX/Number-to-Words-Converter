#include "numbers.h"

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

void print_error(char *str)
{
    write(2, str, ft_strlen(str));
}

int is_valid_num(char *str)
{
    int i = 0;
    while (str[i])
        if (str[i++] < '0' || str[i - 1] > '9')
            return (0);
    return (1);
}

void clean_num(char *src, char *dest)
{
    int i = 0;
    int j = 0;
    while (src[i] == '0')
        i++;
    while (src[i])
        if (src[i] >= '0' && src[i] <= '9')
            dest[j++] = src[i++];
    if (j == 0)
        dest[j++] = '0';
    dest[j] = '\0';
}

long long ft_atoi(char *str)
{
    long long res = 0;
    while (*str >= '0' && *str <= '9')
        res = res * 10 + (*str++ - '0');
    return (res);
}