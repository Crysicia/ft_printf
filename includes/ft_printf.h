/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:13:22 by lpassera          #+#    #+#             */
/*   Updated: 2020/11/27 16:22:58 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/*
** UTILS
*/
void	ft_putchar(char c);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);

int ft_printf(const char *format_string, ...);
#endif
