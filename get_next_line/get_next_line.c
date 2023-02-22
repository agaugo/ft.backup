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

char	*get_full_line(int fd, char *previous_read, char *chunk_buffer)
{
	ssize_t bytes_read;
	char 	*temp_buffer;

	bytes_read = 1;														//Set bytes_read to 1 so that the loop will run at least once
	while (bytes_read != 0)
	{
		bytes_read = read(fd, chunk_buffer, BUFFER_SIZE); 				//Read BUFFER_SIZE bytes into chunk_buffer from the file descriptor fd
		if (bytes_read == -1)											//If read returns -1, return 0, read return -1 when read fails
			return (0);
		else if (bytes_read == 0)										//If read returns 0, it means that the end of file has been reached
			break ;
		chunk_buffer[bytes_read] = '\0';								//Null terminating chunk_buffer so that it can be used as a string
		if (!previous_read)
			previous_read = ft_strdup("");
			if (!previous_read)
				return (NULL);												//If previous_read is empty (i.e., this is the first call), duplicate an empty string into it, aka a malloced one character string
		temp_buffer = previous_read;									//Store the previous_read value in temp so that the original memory can be freed 				
		previous_read = ft_strjoin(temp_buffer, chunk_buffer);			//Join the previous_read value with the chunk_buffer value
		free(temp_buffer);												//Free the temp_buffer value
		temp_buffer = NULL;												//Set temp to NULL because good practice
		if (ft_strchr(chunk_buffer, '\n'))								//check if the buffer already contains a newline character
			break ;														//if it does, break out of the loop, as we have a full line
	}
	return (previous_read);												//return the full line, including potential extra chraacters after the newline character
}

char	*trim_line_buffer(char *line_buffer)
{
	size_t		index;													//index will be used to iterate through the line_buffer value
	size_t		buffer_len;												//buffer_len will be used to store the length of the whole line_buffer value				
	char		*temp_buffer;											//temp_buffer will be used to store the value of the line_buffer after the newline character

	index = 0;
	buffer_len = ft_strlen(line_buffer);                    			//Get the length of the line_buffer value
	while (line_buffer[index] != '\0' && line_buffer[index] != '\n')	//Iterate through the line_buffer value until the newline character is found, or the end of the string is reached
		index++;
	if (line_buffer[index] == '\0' || line_buffer[1] == '\0')			//If the newline character is not found, or if the newline character is the last character in the line_buffer value, return NULL. why line_buffer[1] == '\0'? because if the newline character is the last character in the line_buffer value, the line_buffer value will be a one character string, aka a newline character, but null is always the last character in a string
		return (0);
	index++;
	temp_buffer = ft_substr(line_buffer, index, buffer_len);		//Get the values of the line_buffer after the newline character
	if (*temp_buffer == '\0')											//If the temp_buffer value is an empty string, free it and set it to NULL. Aka when the line_buffer value is a one line file or if the newline character is the last character in the line_buffer value
	{
		free(temp_buffer);
		temp_buffer = NULL;
	}
	line_buffer[index] = '\0';										//Null terminate the line_buffer value after the newline character so that it can be returned
	return (temp_buffer);												//
}

char	*get_next_line(int fd)
{
	static char	*previous_read; 										//will store the remaining chars of the previous read after \n
	char		*chunk_buffer; 											//will store the whole chunk of the read value of size BUFFER_SIZE
	char		*line_buffer; 											//will store the value of the line read and wil be reurned

	if (fd < 0 || BUFFER_SIZE <= 0) 									//ERROR HANDLING // if fd or buffer size is invalid
		return (0);
	chunk_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!chunk_buffer) 													//ERROR HANDLING // if malloc fails
		return (0);
	line_buffer = get_full_line(fd, previous_read, chunk_buffer);		//Get the full chunk of size BUFFER_SIZE, or a multiple of BUFFER_SIZE, that contains a new line character or the whole line if it is a one line file, from the file descriptor
	free(chunk_buffer);													//Free the chunk_buffer value as it has been assigned to line_buffer
	chunk_buffer = NULL;												//Set chunk_buffer to NULL because good practice
	if (!line_buffer)		
	{
		free(previous_read);
		previous_read = NULL;												//Set chunk_buffer to NULL because good practice
		return (0);																	//If line_buffer is NULL, return NULL. When would line_buffer be NULL? When the file is empty, or when the file only contains a newline character
	}																	//Static must be cleared when line_buffer == NULL. Consider what happens if read returns -1 in get_full_line. This is get_next_line's way of handling that.
	previous_read = trim_line_buffer(line_buffer);						//Trim the line_buffer value so that it stops at the \n character, saves the remaining values to previous_read for next call.
	return (line_buffer);
}

// int	main(void)															//sample main for testing
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("file.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while(line)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 		{
// 			break ;
// 			free(line);
// 		}
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
