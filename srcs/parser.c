/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:50:02 by lpassera          #+#    #+#             */
/*   Updated: 2020/11/28 20:30:34 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t index;
	size_t s_len;

	index = -1;
	s_len = 0;
	while (s[s_len])
		s_len++;
	while (++index <= s_len)
		if (s[index] == (char)c)
			return ((char *)&s[index]);
	return (NULL);
}

int				ft_atoi(const char *str)
{
	long	total;
	size_t	index;

	total = 0;
	index = 0;
	while (ft_strchr("0123456789", str[index]))
	{
		total *= 10;
		total += str[index] - '0';
		index++;
	}
	return (total * sign);
}

// void debug(t_conversion *conversion)
// {
//     printf("Field width: %i\nPrecision: %i\nType: %c", conversion->field_width, conversion->precision, conversion->type);
// }

t_conversion *ft_init_conversion(void)
{
	t_conversion	*conversion;
	t_flags			*flags;

	if (!(conversion = malloc(sizeof(t_conversion))))
		return (NULL);
	if (!(flags = malloc(sizeof(t_flags))))
	{
		free(conversion);
		return (NULL);
	}
	conversion->flags = flags;
	return (conversion);
}

/*
** TODO: Make flags a lookup struct to avoid hardcoding them in ifs
*/
int ft_flags_to_conversion(t_conversion **conversion, const char *str)
{
	int index;

	index = 0;
	while (str[index] && ft_strchr(FLAGS, str[index]))
	{
		if (str[index] == '0')
			*conversion->flags->zero = true;
		if (str[index] == '-')
			*conversion->flags->minus = true;
		index++;
	}
	if (*conversion->flags->minus)
		*conversion->flags->zero = false;
	return (index);
}

int ft_fw_to_conversion(t_conversion **conversion, const char *str)
{
	int index;

	index = 0;
	while (str[index] && ft_strchr(FLAGS, str[index]))
	{
		if (str[index] == '0')
			*conversion->flags->zero = true;
		if (str[index] == '-')
			*conversion->flags->minus = true;
		index++;
	}
	if (*conversion->flags->minus)
		*conversion->flags->zero = false;
	return (index);
}

/*
** TODO: May need to return directives length
** to increment the string pointer.
** TODO: Handle %
*/
t_conversion *ft_parse_directive(const char *str)
{
	t_conversion *conversion;

	if (!(conversion = ft_init_conversion()))
		return (NULL);
	str += ft_flags_to_conversion(&conversion, str);
	str += ft_fw_to_conversion(&conversion, str);
	str += ft_precision_to_conversion(&conversion, str);
	str += ft_type_to_conversion(&conversion, str);
}
