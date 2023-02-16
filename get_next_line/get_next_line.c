/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:12:58 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 15:17:13 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
- Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
- Your function should return the line that was read.
- If there is nothing else to read or if an error occurred, it should return NULL.
- Make sure that your function works as expected both when reading a file and when reading from the standard input.
- Please note that the returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.
- Your header file get_next_line.h must at least contain the prototype of the get_next_line() function.
- Add all the helper functions you need in the get_next_line_utils.c file
*/


// THE BUFFER SIZE IS DECLARED WHEN COMPILING THE PROGRAM. AKA gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*BUFFER;
	char		*line;
	int 		line_size;
	int			bytes_read;

	line_size = 0;
	//Allocating memory for the buffer according do the BUFFER_SIZE defined when compiling the program.
	BUFFER = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!BUFFER)
		return (NULL);
	//Reading the file and storing it in the bytes_read variable.
	bytes_read = read(fd, BUFFER, BUFFER_SIZE);
	if (bytes_read == 0)
		return (NULL);
	//Checking if the BUFFER contains a new line character at the index.
	while (BUFFER[line_size] != '\n' && BUFFER[line_size] != '\0')
		line_size++;
	//Allocating memory for the line string.
	line = malloc(sizeof(char) * line_size + 1);
	if (!line)
		return (NULL);
	//Copying the BUFFER, aka the line, into the line string.
	ft_strlcpy(line, BUFFER, line_size + 1);	
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	//open the file.txt file and store the file descriptor in the fd variable.
	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	//Calling the get_next_line function and storing the line in the line variable.
	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	//closing the file.
	close(fd);
	return (0);
}
