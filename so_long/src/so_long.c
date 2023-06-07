#include "../get_next_line/get_next_line.h"
#include "../so_long.h"
#include <stdio.h>

void	render_map(t_data *game, int win_height)
{
	int	row_i;
	int	col_i;
	int	null_w;
	int	null_h;

	col_i = 0;
	while (col_i < win_height)
	{
		row_i = 0;
		while (game->map[col_i][row_i] != '\0')
		{
			if (game->map[col_i][row_i] == '1')
				game->img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &null_w, &null_h);
			else if (game->map[col_i][row_i] == '0')
				game->img = mlx_xpm_file_to_image(game->mlx, "./textures/tile.xpm", &null_w, &null_h);
			else if (game->map[col_i][row_i] == 'C')
				game->img = mlx_xpm_file_to_image(game->mlx, "./textures/goblin.xpm", &null_w, &null_h);
			else if (game->map[col_i][row_i] == 'E')
				game->img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &null_w, &null_h);
			else if (game->map[col_i][row_i] == 'P')
			{
				game->img = mlx_xpm_file_to_image(game->mlx, "./textures/hero.xpm", &null_w, &null_h);
				game->player.x = row_i;
				game->player.y = col_i;
				game->map[col_i][row_i] = '0';
			}
			mlx_put_image_to_window(game->mlx, game->win, game->img, (row_i * IMG_SIZE), (col_i * IMG_SIZE));
			row_i++;
		}
		col_i++;
	}
}

//cordinates go from top left to bottom right. i.e. (0, 0) is topmost left corner!!!!
void	parse_map(int fd, t_data *game, int win_width, int win_height)
{
	char	**map;
	char	*line;
	int		row_i;
	int		col_i;

	map = (char **)malloc(sizeof(char *) * win_height);
	col_i = 0;
	while ((line = get_next_line(fd)) && col_i < win_height)
	{
		row_i = 0;
		map[col_i] = (char *)malloc((sizeof(char) * win_width) + 1);
		while (line[row_i] != '\0')
		{
			map[col_i][row_i] = line[row_i];
			row_i++;
		}
		map[col_i][row_i] = '\0';
		col_i++;
	}
	game->map = map;
	render_map(game, win_height);
}

int	main(int argc, char *argv[])
{
	t_data	game;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (15 * IMG_SIZE), (5 * IMG_SIZE), "so_long");
	mlx_key_hook(game.win, key_hook, (void *)0);
	parse_map(fd, &game, 15, 5);
	mlx_loop(game.mlx);
	return (0);
}
