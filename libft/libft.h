/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 14:44:46 by rarruda       #+#    #+#                 */
/*   Updated: 2021/10/06 13:50:08 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>

int		ft_power(int p);
void	ft_putchar(char c);
int		ft_puthex(int nb, char id);
void	ft_putnbr(int nb);
int		ft_putpoi(unsigned long long pointer);
void	ft_putstr(char *str);
int		ft_putunsnbr(int nb);

#endif
