#include "../inc/libmx.h"

char *mx_file_to_str(const char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        return NULL;
    }

    char c;
    int length = 0;

    while (read(fd, &c, 1) != -1) {
        length++;
    }

    close(fd);
    char *result = mx_strnew(length + 1);
    int i = 0;
    fd = open(file, O_RDONLY);

    while (read(fd, &c, 1) != -1) {
        result[i] = c;
        i++;
    }

    result[i] = '\0';
    close(fd);

    return result;
}
