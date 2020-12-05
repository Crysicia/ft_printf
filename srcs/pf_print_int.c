/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:25:18 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/05 14:34:45 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nomallocs.h"
#include "../includes/ft_math.h"
#include "../includes/ft_string.h"
#include "../includes/ft_conversion.h"
#include "../includes/pf_parse_directive.h"

int	pf_print_field_width(t_directive *directive, int max, int *value)
{
	int		printed;
	char	padding_char;
	int		width;

	width = directive->field_width - max;
	if (width < 1)
		return (0);
	printed = 0;
	padding_char = ' ';
	if (directive->flags.zero == 1 && directive->precision == NOT_SET)
	{
		if (*value < 0)
		{
			*value = ft_abs(*value);
			printed += ft_putchar('-');
		}
		padding_char = '0';
	}
	printed += ft_putnchar(padding_char, width);
	return (printed);
}

int	pf_handle_zero(int precision, int field_width)
{
	if (precision == 0 && field_width == 0)
		return (0);
	if (precision == 0)
		return (ft_putchar(' '));
	ft_putchar('0');
	return (1);
}

int	pf_print_precision(t_directive *directive, int *value)
{
	int printed;

	printed = 0;
	if (*value < 0)
	{
		*value = ft_abs(*value);
		printed += ft_putchar('-');
	}
	printed += ft_putnchar('0', directive->precision - ft_int_size(*value));
	if (*value == 0)
		printed += pf_handle_zero(directive->precision, directive->field_width);
	else
		printed += ft_putstr(ft_itoa(*value));
	return (printed);
}

int	pf_print_int(t_directive *directive, va_list args)
{
	int size;
	int value;
	int printed;
	int max;
	int neg;

	printed = 0;
	value = va_arg(args, int);
	neg = (value < 0) ? 1 : 0;
	size = ft_int_size(value);
	max = ft_max(directive->precision + neg, size);
	if (directive->flags.minus == 1)
	{
		printed += pf_print_precision(directive, &value);
		printed += pf_print_field_width(directive, max, &value);
	}
	else
	{
		printed += pf_print_field_width(directive, max, &value);
		printed += pf_print_precision(directive, &value);
	}
	return (printed);
}
