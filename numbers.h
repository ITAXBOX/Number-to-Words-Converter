#ifndef NUMBERS_H
# define NUMBERS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int ft_strlen(char *str);
void print_error(char *str);
int is_valid_num(char *str);
void clean_num(char *src, char *dest);
long long ft_atoi(char *str);
void find_in_dict(char *file, long long target);
void process_remainder(char *file, int remainder, int hundreds);
void process_scale(char *file, int scale_power);
void process_group(char *file, int num, int scale_power);
void init_groups(int *groups, int total_groups, char *cleaned, int padding);
void convert_num(char *file, char *cleaned);

#endif