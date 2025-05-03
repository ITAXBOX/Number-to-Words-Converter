#include "numbers.h"

void process_remainder(char *file, int remainder, int hundreds)
{
    if (remainder >= 20)
    {
        find_in_dict(file, (remainder / 10) * 10);
        if (remainder % 10 > 0)
            find_in_dict(file, remainder % 10);
    }
    else if (remainder >= 10)
        find_in_dict(file, remainder);
    else if (remainder > 0 || (hundreds == 0 && remainder == 0))
        find_in_dict(file, remainder);
}

void process_scale(char *file, int scale_power)
{
    long long scale_num = 1;
    while (scale_power-- > 0)
        scale_num *= 1000;
    find_in_dict(file, scale_num);
}

void process_group(char *file, int num, int scale_power)
{
    int hundreds = num / 100;
    int remainder = num % 100;

    if (num == 0)
        return ;
    if (hundreds > 0)
    {
        find_in_dict(file, hundreds);
        find_in_dict(file, 100);
    }
    process_remainder(file, remainder, hundreds);
    if (scale_power > 0)
        process_scale(file, scale_power);
}