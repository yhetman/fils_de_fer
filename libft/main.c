#include "includes/libft.h"

int main(int argc, char **argv) {
    int fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
    while (get_next_line(fd, &line))
    {
        ft_printf("%s", line);
        free(line);
    }
    system("leaks a.out");
    return (0);
}