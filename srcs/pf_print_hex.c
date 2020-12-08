/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:25:18 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 18:52:16 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_math.h"
#include "../includes/ft_string.h"
#include "../includes/ft_conversion.h"
#include "../includes/pf_parse_directive.h"

int	pfh_print_field_width(t_directive *directive, int max)
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
		padding_char = '0';
	printed += ft_putnchar(padding_char, width);
	return (printed);
}

int	pfh_handle_zero(int precision, int field_width)
{
	if (precision == 0 && field_width == 0)
		return (0);
	if (precision == 0)
		return (ft_putchar(' '));
	ft_putchar('0');
	return (1);
}

int	pfh_print_precision(t_directive *d, char *charset, unsigned int *value)
{
	int		printed;
	char	*number;

	printed = 0;
	printed += ft_putnchar('0', d->precision - ft_int_size(*value, HEX_BASE));
	if (*value == 0)
		printed += pfh_handle_zero(d->precision, d->field_width);
	else
	{
		number = ft_utoa_base(*value, charset);
		printed += ft_putstr(number);
		free(number);
	}
	return (printed);
}

int	pf_print_hex(t_directive *directive, char *charset, va_list args)
{
	int				size;
	unsigned int	value;
	int				printed;
	int				max;

	printed = 0;
	value = va_arg(args, unsigned int);
	size = ft_int_size(value, HEX_BASE);
	max = ft_max(directive->precision, size);
	if (directive->flags.minus == 1)
	{
		printed += pfh_print_precision(directive, charset, &value);
		printed += pfh_print_field_width(directive, max);
	}
	else
	{
		printed += pfh_print_field_width(directive, max);
		printed += pfh_print_precision(directive, charset, &value);
	}
	return (printed);
}
