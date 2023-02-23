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
// check leaks ✗ leaks --atExit --list -- ./a.out
#include "get_next_line.h"
#include <fcntl.h>

ssize_t	find_new_line(char	*source)
{
	ssize_t	index;

	index = 0;
	while (source[index] != '\0' && source[index] != '\n')
		index++;
	if (source[index] == '\n')
		return (index);
	return (-1);
}

char	*trim_line_buffer(char	*line_buffer)
{
	ssize_t	end_of_line;
	size_t	total_buffer_len;
	char	*temp_buffer;

	end_of_line = find_new_line(line_buffer);
	total_buffer_len = ft_strlen(line_buffer);
	if (end_of_line == -1)
		return (0);
	end_of_line++;
	temp_buffer = ft_substr(line_buffer, end_of_line, total_buffer_len);
	if (*temp_buffer == '\0')
	{
		free(temp_buffer);
		temp_buffer = NULL;
	}
	line_buffer[end_of_line] = '\0';
	return (temp_buffer);
}

char	*get_full_chunk(int fd, char *previous_read, char *chunk_buffer)
{
	char	*temp_buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, chunk_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		chunk_buffer[bytes_read] = '\0';
		if (!previous_read)
			previous_read = ft_empty_string();
		temp_buffer = previous_read;
		previous_read = ft_strjoin(temp_buffer, chunk_buffer);
		free(temp_buffer);
		temp_buffer = NULL;
		if (ft_strchr(chunk_buffer, '\n'))
			break ;
	}
	return (previous_read);
}

char	*get_next_line(int fd)
{
	static char	*previous_read;
	char		*chunk_buffer;
	char		*line_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chunk_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!chunk_buffer)
		return (NULL);
	line_buffer = get_full_chunk(fd, previous_read, chunk_buffer);
	free(chunk_buffer);
	chunk_buffer = NULL;
	if (!line_buffer)
	{
		free(previous_read);
		previous_read = NULL;
		return (NULL);
	}
	previous_read = trim_line_buffer(line_buffer);
	return (line_buffer);
}
