#ifndef FDF_H
# define FDF_H

#include "../libft/includes/libft.h"
//#include "structs.h"
#include <math.h>
#include <mlx.h>

# define WIN_HEIGHT 1000
# define WIN_WIDTH  1000
# define EXIT_CODE    53
typedef struct  s_coord
{
    int         x;
    int         y;
}               t_coord;

typedef struct			s_image
{
	void				*ptr;
	int 				b;
	int 				size;
	int 				end;
	int 				*data;
}						t_image;

typedef struct s_line
{
    int         height;
    int         color
}               t_line;

typedef struct  s_fdf
{
    void        *win;
    void        *mlx;
    char        *line;
}               t_fdf;

int     exit_hook(int keycode, void *param);
int     validation(t_fdf *fdf);
#endif
