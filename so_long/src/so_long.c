#include "../so_long.h"
#include "../get_next_line/get_next_line.h"
#include <stdio.h>

void parse_map(int fd, t_data *game)
{
    int     wd;
    int     hh;
    char    *current_line;
    int     i;
    int     x;

    x = 0;
    while ((current_line = get_next_line(fd)))
    {
        if (current_line == NULL)
        {
            printf("Error: get_next_line returned NULL.\n");
            return;
        }
        i = 0;
        while (current_line[i] != '\0')
        {
            if (current_line[i] == '1')
            {
                game->img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &wd, &hh);
                if (game->img == NULL)
                {
                    printf("Error: mlx_xpm_file_to_image for wall texture returned NULL.\n");
                    return;
                }
                mlx_put_image_to_window(game->mlx, game->win, game->img, (i * IMG_SIZE), (x * IMG_SIZE));
            }
            if (current_line[i] == '0')
            {
                game->img = mlx_xpm_file_to_image(game->mlx, "./textures/tile.xpm", &wd, &hh);
                if (game->img == NULL)
                {
                    printf("Error: mlx_xpm_file_to_image for floor texture returned NULL.\n");
                    return;
                }
                mlx_put_image_to_window(game->mlx, game->win, game->img, (i * IMG_SIZE), (x * IMG_SIZE));
            }
            i++;
        }
        x++;
    }
}

int main(int argc, char *argv[])
{
    t_data  game;
    int     fd;

    if (argc != 2)
        return 0;
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return -1;
    }
    game.mlx = mlx_init();
    if (game.mlx == NULL)
    {
        printf("Error: mlx_init returned NULL.\n");
        return -1;
    }
    game.win = mlx_new_window(game.mlx, (30*IMG_SIZE), (15*IMG_SIZE), "so_long");
    if (game.win == NULL)
    {
        printf("Error: mlx_new_window returned NULL.\n");
        return -1;
    }
    parse_map(fd, &game);
    mlx_loop(game.mlx);
    return 0;
}