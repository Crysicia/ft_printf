/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:25:18 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/04 18:02:47 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nomallocs.h"
#include "../includes/ft_math.h"
#include "../includes/ft_string.h"
#include "../includes/ft_conversion.h"
#include "../includes/pf_parse_directive.h"

int pf_print_field_width(t_directive *directive, int max, int *value)
{
	int printed_chars;
	char padding_char;
	int width;

	width = directive->field_width - max;

	//write(1, "\n-- Print field width\n", 22);
	if (width < 1)
		return (0);
	printed_chars = 0;	
	padding_char = ' ';
	if (directive->flags.zero == 1 && directive->precision == NOT_SET)
	{
		if (*value < 0)
		{
			*value = ft_abs(*value);
			printed_chars += ft_putchar('-');
		}
		padding_char = '0';
	}
	printed_chars += ft_putnchar(padding_char, width);
	return (printed_chars);
}

int pf_handle_zero(int precision, int field_width)
{
	if (precision == 0 && field_width == 0)
		return (0);
	if (precision == 0)
		return (ft_putchar(' '));
	ft_putchar('0');
	return (1);
}

int pf_print_precision(t_directive *directive, int *value)
{
	int printed_chars;
	printed_chars = 0;
	if (*value < 0)
	{
		*value = ft_abs(*value);
		printed_chars += ft_putchar('-');
	}
	printed_chars += ft_putnchar('0', directive->precision - ft_int_size(*value));
	if (*value == 0)
		printed_chars += pf_handle_zero(directive->precision, directive->field_width);
	else
		printed_chars += ft_putstr(ft_itoa(*value));
	return (printed_chars);
}

int pf_print_int(t_directive *directive, va_list args)
{
	int size;
	int value;
	int printed_chars;
	int max;
	int neg;

	printed_chars = 0;
	value = va_arg(args, int);
	neg = (value < 0) ? 1 : 0;
	size = ft_int_size(value);
	max = ft_max(directive->precision + neg, size);
	// if (precision == 4 && field_width == 5)
	// 	printf("\n\n\n\n----- Flags -----\n-- Flag: %s\n-- Precision: %d\n-- Field width: %d\n\n\n\n", (flag == FLAG_MINUS) ? "Minus" : (flag == FLAG_ZERO) ? "Zero" : "None", precision, field_width);
	if (directive->flags.minus == 1)
	{
		printed_chars += pf_print_precision(directive, &value);
		printed_chars += pf_print_field_width(directive, max, &value);
	}
	else
	{
		printed_chars += pf_print_field_width(directive, max, &value);
		printed_chars += pf_print_precision(directive, &value);
	}
	return (printed_chars);
}
