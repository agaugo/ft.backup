#include "mlx.h"

// **** STRUCTS **** //

# define IMG_SIZE 32

typedef	struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
}	t_data;

//  **** CORE **** //

int		main(void);
void	pixel_put(t_data	*data, int x, int y, int color);
