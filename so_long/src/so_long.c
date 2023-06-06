#include "../so_long.h"
#include "../get_next_line/get_next_line.h"
#include <stdio.h>

void parse_map(int fd, t_data *game, int win_width, int win_height)
{
    int     wd;
    int     hh;
    int     i;
	int		w;
    int     line_count;
    char    *current_line;
	char	**map; //!!

    line_count = 0;
    while ((current_line = get_next_line(fd)))
    {
		i = 0;
        while (current_line[i] != '\0')
        {
            if (current_line[i] == '1')
                game->img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &wd, &hh);
            else if (current_line[i] == '0')
                game->img = mlx_xpm_file_to_image(game->mlx, "./textures/tile.xpm", &wd, &hh);
			else if (current_line[i] == 'C')
				game->img = mlx_xpm_file_to_image(game->mlx, "./textures/goblin.xpm", &wd, &hh);
			else if (current_line[i] == 'E')
				game->img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &wd, &hh);
			else if (current_line[i] == 'F')
				game->img = mlx_xpm_file_to_image(game->mlx, "./textures/exit_hero.xpm", &wd, &hh);
			else if (current_line[i] == 'P')
			{
				game->img = mlx_xpm_file_to_image(game->mlx, "./textures/hero.xpm", &wd, &hh);
				game->player.x = i;
				game->player.y = line_count;
				current_line[i] = '0';
			}
            mlx_put_image_to_window(game->mlx, game->win, game->img, (i * IMG_SIZE), (line_count * IMG_SIZE));
            i++;
        }
		w = i;
        line_count++;
    }
}

int main(int argc, char *argv[])
{
    t_data  game;
    int     fd;

    if (argc != 2)
        return 0;
    fd = open(argv[1], O_RDONLY);
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, (13*IMG_SIZE), (5*IMG_SIZE), "so_long");
	mlx_key_hook(game.win, key_hook, (void *)0);
	if (ft_strcmp(argv[1], "maps/small.ber"))
		parse_map(fd, game, 15, 5);
	else if (ft_strcmp(argv[1], "maps/medium.ber"))
		parse_map(fd, game, 30, 10);
	else if (ft_strcmp(argv[1], "maps/large.ber"))
		parse_map(fd, game, 60, 20);
	render_map(map, t_data *game, win_width, win_height);
    mlx_loop(game.mlx);
    return 0;
}
