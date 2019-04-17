#ifndef FDF_H
# define FDF_H

#include "../libft/includes/libft.h"
//#include "structs.h"
#include <math.h>
#include "mlx.h"

# define WIN_HEIGHT 1000
# define WIN_WIDTH  1000
# define EXIT_CODE	53


typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

/*typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				decimal;
}					t_point;*/

typedef struct		s_rotation
{
	double			x;
	double			y;
	double			z;
}					t_rot;

typedef struct		s_line
{
	int				height;
	int				color;
}			 		t_line;

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				size;
	int				end;
}					t_image;

typedef struct		s_palette
{
	t_color			*c_1;
	t_color			*c_2;
	t_color			*c_3;
	t_color			*c_4;
	t_color			*c_5;
}					t_palette;

typedef struct		s_bresenham
{
	t_coord			*coord;
	t_coord			*dot_coor;
	int				color_dec;
	int				d;
	t_coord			dots; //x = dot1, y = dot2;
}					t_algo;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	char			*name;
	t_image			image;
	t_line			**line;
	t_color			**points;
	t_coord			*coord;
	t_palette		*palette;
	t_rot			rot;
	double			x;
	double			y;
	double			zoom;
	double			height;
	int				info;
	int				music;
	t_palette		*palette;
}					t_fdf;


int		define_hook(int keycode, t_fdf *fdf);
int		exit_hook(int keycode, void *param);
void	mlx_error(void);
void	map_error(void);
void	mal_error(void);
void	arg_error(void);
void	file_error(void);
int		is_valid(t_fdf **fdf, char *str);
t_line 	**init_line(t_coord *c, char *line);
t_image	*init_image(void *mlx, t_image *image);
t_fdf	*init_fdf(t_line **l, t_coord *c);
t_color	counting_rotation(t_fdf *fdf, double x,
		double y, double z);
#endif
