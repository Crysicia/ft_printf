/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:13:22 by lpassera          #+#    #+#             */
/*   Updated: 2020/11/28 20:20:51 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define FLAGS "0-"

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef struct 	s_flags
{
	t_bool		zero;
	t_bool		minus;
}				t_flags;

typedef struct	s_conversion
{
	t_flags 	*flags;
	int			field_width;
	int			precision;
	int			type;
	void 		*value;
}				t_conversion;

/*
** UTILS
*/
void	ft_putchar(char c);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);

int ft_printf(const char *format_string, ...);
#endif
