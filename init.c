#include "numbers.h"

void init_groups(int *groups, int total_groups, char *cleaned, int padding)
{
    int i = 0;
    int j;

    while (i < total_groups)
    {
        groups[i] = 0;
        j = 0;
        while (j < 3)
        {
            if (i * 3 + j - padding >= 0)
                groups[i] = groups[i] * 10 + (cleaned[i * 3 + j - padding] - '0');
            else if (i * 3 + j - padding < 0)
                groups[i] = groups[i] * 10;
            j++;
        }
        i++;
    }
}

void convert_num(char *file, char *cleaned)
{
    int len = ft_strlen(cleaned);
    int padding = (3 - (len % 3)) % 3;
    int total_groups = (len + padding) / 3;
    int *groups = malloc(total_groups * sizeof(int));
    int i = 0;
    int all_zero = 1;

    if (!groups)
        return (print_error("Error: Malloc failed\n"));
    init_groups(groups, total_groups, cleaned, padding);
    while (i < total_groups)
        if (groups[i++] != 0)
            all_zero = 0;
    if (all_zero)
        find_in_dict(file, 0);
    else
    {
        i = 0;
        while (i < total_groups)
        {
            if (groups[i] != 0)
                process_group(file, groups[i], total_groups - i - 1);
            i++;
        }
    }
    free(groups);
}