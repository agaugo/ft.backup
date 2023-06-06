#include "../so_long.h"
#include "../get_next_line/get_next_line.h"
#include <stdio.h>


//because void param is unused we put __attribute__((unused))

int	key_hook(int keycode, void *param __attribute__((unused)))
{
	if (keycode == 53)
		exit(0);
	if (keycode == 119)		//up
		return (1);
	if (keycode == 97)		//left
		return (2);
	if (keycode == 115)		//down
		return (3);
	if (keycode == 100)		//right
		return (4);
	return (0);
}

// void player_move(int fd, t_data *game)
// {
// }
