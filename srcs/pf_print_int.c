/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:25:18 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 18:52:15 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_math.h"
#include "../includes/ft_string.h"
#include "../includes/ft_conversion.h"
#include "../includes/pf_parse_directive.h"

int	pfi_print_field_width(t_directive *directive, int max, long *value)
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
			*value = -*value;
			printed += ft_putchar('-');
		}
		padding_char = '0';
	}
	printed += ft_putnchar(padding_char, width);
	return (printed);
}

int	pfi_handle_zero(int precision, int field_width)
{
	if (precision == 0 && field_width == 0)
		return (0);
	if (precision == 0)
		return (ft_putchar(' '));
	ft_putchar('0');
	return (1);
}

int	pfi_print_precision(t_directive *d, long *v)
{
	int		printed;
	char	*number;

	printed = 0;
	if (*v < 0)
	{
		*v = -*v;
		printed += ft_putchar('-');
	}
	printed += ft_putnchar('0', d->precision - ft_int_size(*v, DECIMAL_BASE));
	if (*v == 0)
		printed += pfi_handle_zero(d->precision, d->field_width);
	else
	{
		number = ft_itoa(*v);
		printed += ft_putstr(number);
		free(number);
	}
	return (printed);
}

int	pf_print_int(t_directive *directive, va_list args)
{
	int		size;
	long	value;
	int		printed;
	int		max;
	int		neg;

	printed = 0;
	value = va_arg(args, int);
	neg = (value < 0) ? 1 : 0;
	size = ft_int_size(value, DECIMAL_BASE);
	max = ft_max(directive->precision + neg, size);
	if (directive->flags.minus == 1)
	{
		printed += pfi_print_precision(directive, &value);
		printed += pfi_print_field_width(directive, max, &value);
	}
	else
	{
		printed += pfi_print_field_width(directive, max, &value);
		printed += pfi_print_precision(directive, &value);
	}
	return (printed);
}
