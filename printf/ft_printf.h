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
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include "libft/libft.h"

int		ft_printf(const char *flag_string, ...);
int     ft_int (int arg);
int     ft_str(char *arg);
int     itoptr(uintptr_t convert);
void	fill_string(unsigned int arg, char *buffer, int rev_index);
int     itou(unsigned int);
int     itohex(unsigned int convert, int uppercase);
char    *ft_strrev(char *buffer, int size);
int     chars(int n);

#endif

