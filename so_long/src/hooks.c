#include "../so_long.h"
#include "../get_next_line/get_next_line.h"
#include <stdio.h>


//because void param is unused we put __attribute__((unused))

int	key_hook(int keycode, void *param __attribute__((unused)))
{
	if (keycode == 53)
		exit(0);
	return (0);
}

// void player_move(int fd, t_data *game)
// {
// }
