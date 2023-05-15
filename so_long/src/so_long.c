#include <mlx.h>
#include "so_long.h"


void	my_mlx_pixel_put(t_data	*data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	char	*path;
	int 	img_width;
	int		img_height;
	void	*img;

	mlx = mlx_init();
	path = "../frog.png";
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Test");
	// img.img = mlx_new_image(mlx, 500, 500);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 250, 250, 0x00FF0001);
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}