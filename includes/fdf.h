#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include <math.h>
#include <mlx.h>

# define WIN_HEIGHT 1000
# define WIN_WIDTH  1000

typedef struct  s_coord
{
    int         x;
    int         y;
}               t_coord;

typedef struct  s_fdf
{
    void        *win;
    void        *mlx;
    char        *line;
}               t_fdf;
#endif
