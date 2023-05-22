#include "../so_long.h"
#include <stdio.h>

int	main(void)
{
	t_data	game;
	int wd;
	int hh;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (10*IMG_SIZE), (10*IMG_SIZE), "TEST");
	game.img = mlx_xpm_file_to_image(game.mlx, "./test.xpm", &wd, &hh);
	mlx_put_image_to_window(game.mlx, game.win, game.img, (0 * IMG_SIZE), (0 * IMG_SIZE));
	mlx_loop(game.mlx);
	return (0);
}