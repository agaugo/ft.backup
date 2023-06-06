#include "../so_long.h"
#include "../get_next_line/get_next_line.h"
#include <stdio.h>

void parse_map(int fd, t_data *game)
{
    int     wd;
    int     hh;
    int     i;
    int     line_count;
    char    *current_line;

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
			else if (current_line[i] == 'P')
				game->img = mlx_xpm_file_to_image(game->mlx, "./textures/hero.xpm", &wd, &hh);
			else if (current_line[i] == 'E')
				game->img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &wd, &hh);
			else if (current_line[i] == 'F')
				game->img = mlx_xpm_file_to_image(game->mlx, "./textures/exit_hero.xpm", &wd, &hh);
            mlx_put_image_to_window(game->mlx, game->win, game->img, (i * IMG_SIZE), (line_count * IMG_SIZE));
            i++;
        }
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
    parse_map(fd, &game);
	// player_move(fd, &game);
    mlx_loop(game.mlx);
    return 0;
}
