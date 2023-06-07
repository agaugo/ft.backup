#ifndef SO_LONG_H
# define SO_LONG_H


# include "mlx/mlx.h"
# include <fcntl.h>

// **** STRUCTS **** //

# define IMG_SIZE 32

typedef struct s_player {
	int	x;
	int	y;
} t_player;

typedef	struct	s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		**map;
	t_player	player;
}	t_data;

//  **** CORE **** //

int		main(int argc, char *argv[]);
void	parse_map(int fd, t_data *game, int win_width, int win_height);
void	player_move(int fd, t_data *game);
int		key_hook(int keycode, void *p);
int		ft_strcmp(const char *str1, const char *str2);


#endif