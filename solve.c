#include "numbers.h"

void process_dict_line(char *line)
{
    char *ptr;
    char *end;

    ptr = line;
    while (*ptr != ':' && *ptr)
        ptr++;
    if (*ptr == ':')
    {
        ptr++;
        while (*ptr == ' ')
            ptr++;
        end = ptr + ft_strlen(ptr) - 1;
        while (end > ptr && *end == ' ')
            end--;
        *(end + 1) = '\0';
        write(1, ptr, ft_strlen(ptr));
        write(1, " ", 1);
    }
}

void read_dict_line(int fd, long long target)
{
    char buf[1024];
    char line[1024];
    int bytes_read;
    int i;
    int line_pos;

    bytes_read = 0;
    i = 0;
    line_pos = 0;
    while ((bytes_read = read(fd, buf, 1024)) > 0)
    {
        i = 0;
        while (i < bytes_read)
        {
            if (buf[i] == '\n')
            {
                line[line_pos] = '\0';
                if (ft_atoi(line) == target)
                {
                    process_dict_line(line);
                    return;
                }
                line_pos = 0;
            }
            else
            {
                line[line_pos] = buf[i];
                line_pos++;
            }
            i++;
        }
    }
}

void find_in_dict(char *file, long long target)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return;
    read_dict_line(fd, target);
    close(fd);
}