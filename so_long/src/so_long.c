#include "so_long.h"
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	// // char	*path = "banana.xpm";
	void	*img;
	// // t_data	img;

	int wd;
	int hh;

	printf("prinbtyedfsfssaaf");
	mlx = mlx_init();
	printf("prinbtyedfsfssaaf");
	mlx_win = mlx_new_window(mlx, 10 * IMG_SIZE, 10 * IMG_SIZE, "so_long");
	printf("prinbtyedfsfssaaf");
	img = mlx_xpm_file_to_image(mlx, "player.xpm", &wd, &hh);
	printf("prinbtyed");
	mlx_put_image_to_window(mlx, mlx_win, &img, 0 * IMG_SIZE, 0 * IMG_SIZE);
	printf("prinbtye3423424242d");
	mlx_loop(mlx_win);
	return (0);
}
