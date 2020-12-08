/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:54:18 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 16:01:41 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nomallocs.h"
#include "../includes/ft_math.h"
#include "../includes/ft_string.h"
#include "../includes/pf_parse_directive.h"

int	pf_putnstr(const char *str, int limit)
{
	int index;

	index = 0;
	while (str[index] && index < limit)
	{
		write(1, &str[index], 1);
		index++;
	}
	return (index);
}

int	pf_print_string(t_directive *directive, va_list args)
{
	const char	*str;
	int			printed;
	int			min;
	char		padding_char;

	printed = 0;
	if (!(str = va_arg(args, const char *)))
		str = "(null)";
	if (directive->precision == NOT_SET)
		directive->precision = ft_strlen(str);
	min = ft_min(ft_strlen(str), directive->precision);
	padding_char = ' ';
	if (directive->flags.zero == 1)
		padding_char = '0';
	if (directive->flags.minus == 1)
	{
		printed += pf_putnstr(str, directive->precision);
		printed += ft_putnchar(padding_char, directive->field_width - min);
	}
	else
	{
		printed += ft_putnchar(padding_char, directive->field_width - min);
		printed += pf_putnstr(str, directive->precision);
	}
	return (printed);
}
