#include "fdf.h"

int main (int argc, char **argv)
{
    t_fdf	*fdf;

	if (argc != 2)
		return (error("Usage: ./fdf <filename>"));
	if (read_file(&fdf, argv[1]))
		return (1);
	system("afplay -v 0.8 ./music/Ludovico_Einaudi_-_Indaco.mp3 &");
	ft_show_intro(fdf);
	mlx_hook(fdf->win, 2, 0, key_mapping, fdf);
	mlx_hook(fdf->win, 17, 0, ft_exit, (void *)0);
    mlx_loop(fdf->mlx);
    return (0);
}