/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hflohil- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 15:12:58 by hflohil-      #+#    #+#                 */
/*   Updated: 2022/10/06 15:17:13 by hflohil-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include "libft/libft.h"

int		ft_printf(const char *, ...);
char	*reverse_string(char *buffer, int size);
char	*itohex(int convert);
char	*sitohex(int convert);
int		chars(unsigned int n);
char	*fill_string(unsigned int n, char *buffer, int ri, int i);
char	*itou(unsigned int n);
char	*print_ptr(void	*arg);

#endif