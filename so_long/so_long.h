#ifndef SO_LONG_H
# define SO_LONG_H


# include "mlx/mlx.h"
# include <fcntl.h>

// **** STRUCTS **** //

# define IMG_SIZE 32

typedef	struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
}	t_data;

//  **** CORE **** //

int		main(int argc, char *argv[]);
void	parse_map(int fd, t_data *game);
void	player_move(int fd, t_data *game);
int		key_hook(int keycode, void *p);


#endif