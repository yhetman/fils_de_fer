#include "fdf.h"

static int	validation(t_fdf *fdf)
{
	t_coord	*c;

	c = (t_coord*)malloc(sizeof(t_coord));
	if ((c->y = save_ordinat(fdf->line)) < 0)
		return (ft_strerr("Error: Invalid name of file."));
	if ((c->x = save_absis(fdf->line)) <= 0)
		return (ft_strerr("Error: Invalid map."));
	*fdf = init_fdf(init_line(fdf, c), c);
	return (0);
}

int 		main(int argc, char **argv)
{
    t_fdf	fdf;

	if (argc != 2)
		return (ft_strerr("Usage: ./fdf <filename>"));
	fdf = (t_fdf)malloc(sizeof(t_fdf));
	fdf.line = argv[1];
	if (validation(&fdf))
		return (1);
	system("afplay -v &");
	mlx_win_manager(fdf);
	mlx_hook(fdf.win, WIN_HEIGHT, WIN_WIDTH,
				key_hook, fdf);
	mlx_hook(fdf.win, WIN_HEIGHT, WIN_WIDTH,
				exit_hook, (void *)0);
    mlx_loop(fdf.mlx);
    return (0);
}