#include "numbers.h"

int main(int argc, char **argv)
{
    char *file;
    char *num_str;
    char cleaned[1024];

    if (argc < 2 || argc > 3)
        return (print_error("Error: Number of Arguments is Wrong\n"), 1);
    num_str = argv[argc - 1];
    file = (argc == 3) ? argv[1] : "numbers.dict";
    if (!is_valid_num(num_str))
        return (print_error("Error: The Input Number is Wrong\n"), 1);
    clean_num(num_str, cleaned);
    convert_num(file, cleaned);
    write(1, "\n", 1);
    return (0);
}