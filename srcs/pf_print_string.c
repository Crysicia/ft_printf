/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:54:18 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/05 19:10:34 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nomallocs.h"
#include "../includes/ft_math.h"
#include "../includes/ft_string.h"
#include "../includes/pf_parse_directive.h"

int pf_putnstr(const char *str, int limit)
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

int pf_print_string(t_directive *directive, va_list args)
{
	const char *str;
	int printed;
	int min;
	int precision;

	printed = 0;
	str = va_arg(args, const char *);
	precision = directive->precision;
	if (directive->precision == NOT_SET || directive->precision == 0)
		precision = ft_strlen(str);
	min = ft_min(ft_strlen(str), precision);
	if (directive->flags.minus == 1)
	{
		printed += pf_putnstr(str, precision);
		printed += ft_putnchar(' ', directive->field_width - min);
	}
	else
	{
		printed += ft_putnchar(' ', directive->field_width - min);
		printed += pf_putnstr(str, precision);
	}
	return (printed);
}
