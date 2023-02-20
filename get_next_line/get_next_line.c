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

char	*get_full_line(int fd, char *previous_read, char	*chunk_buffer)
{
	ssize_t bytes_read;
	char 	*temp_buffer;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, chunk_buffer, BUFFER_SIZE); 	//Read BUFFER_SIZE bytes into chunk_buffer from the file descriptor fd
		if (bytes_read == -1)
			return (0);
		else if (bytes_read == 0)
			break ;
		chunk_buffer[bytes_read] = '\0';							//Null terminating chunk_buffer
		if (!previous_read)
			previous_read = ft_strdup("");							//If previous_read is empty (i.e., this is the first call), duplicate an empty string into it
		temp_buffer = previous_read;								//Store the previous_read value in temp so that the original memory can be freed 				
		previous_read = ft_strjoin(temp_buffer, chunk_buffer);		//Join the previous_read value with the chunk_buffer value
		free(temp_buffer);
		temp_buffer = NULL;											//Set temp to NULL because good practice
		if (ft_strchr(chunk_buffer, '\n'))
			break ;
	}
	return (previous_read);
}

char	*trim_line_buffer(char *line_buffer)
{
	size_t		index;
	size_t		buffer_len;
	char		*temp_buffer;

	index = 0;
	buffer_len = ft_strlen(line_buffer) - index;
	while (line_buffer[index] != '\0' && line_buffer[index] != '\n')
		index++;
	if (line_buffer[index] == '\0' || line_buffer[1] == '\0')
		return (0);
	temp_buffer = ft_substr(line_buffer, index + 1, buffer_len);
	if (*temp_buffer == '\0')
	{
		free(temp_buffer);
		temp_buffer = NULL;
	}
	line_buffer[index + 1] = '\0';
	return (temp_buffer);
}

char	*get_next_line(int fd)
{
	static char	*previous_read; //will store the remaining chars of the previous read after \n
	char		*chunk_buffer; 	//will store the whole chunk of the read value of size BUFFER_SIZE
	char		*line_buffer; 	//will store the value of the line read and wil be reurned

	if (fd < 0 || BUFFER_SIZE <= 0) //ERROR HANDLING // if fd or buffer size is invalid
		return (0);
	chunk_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!chunk_buffer) //ERROR HANDLING // if malloc fails
		return (0);
	line_buffer = get_full_line(fd, previous_read, chunk_buffer);
	free(chunk_buffer);
	chunk_buffer = NULL;
	if (!line_buffer)
	{
		free(previous_read);			//Static must be cleared when line_buffer == NULL. Consider what happens if read returns -1 in get_full_line
		previous_read = NULL;
		return (NULL);
	}
	previous_read = trim_line_buffer(line_buffer);	//Trim the line_buffer value so that it stops at the \n character, saves the remaining values to previous_read for next call.
	return (line_buffer);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("file.txt", O_RDONLY);
	
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);
	
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);

// 	return (0);
// }
