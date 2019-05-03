                                                                                                        #ifndef FDF_H
# define FDF_H

#include "../libft/includes/libft.h"
#include "mlx.h"
#include "structs.h"

# define WIN_HEIGHT 1000
# define WIN_WIDTH  1000

void	mlx_error(void);
void	map_error(void);
void	mal_error(void);
void	arg_error(void);
void	file_error(void);

void	display_menu(t_fdf *fdf, char *name);
void	init_image(void *mlx, t_image *image);

void	draw(t_fdf *f, t_algo first, t_algo second);

void	using_algo(t_fdf *f, int x, int y, t_color **p);

void	rotation(int keycode, t_fdf *fdf);
void	movement(int keycode, t_fdf *fdf);
void	change_height(int keycode, t_fdf *fdf);
void	zoom(int keycode, t_fdf *fdf);
void	refreshing(t_fdf *fdf);

int		exit_hook(int keycode, void *ptr);
int		define_hook(int keycode, t_fdf *fdf);

int		is_valid(t_fdf **fdf, char *str);

t_line 	**init_line(t_coord *c, char *line);

t_fdf	*init_fdf(t_line **l, t_coord *c);

t_color	counting_rotation(t_fdf *fdf, double x,
		double y, double z);
#endif
