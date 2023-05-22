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

int		main(void);
void	pixel_put(t_data	*data, int x, int y, int color);

#endif