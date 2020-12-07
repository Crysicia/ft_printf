/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nomallocs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 09:50:55 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/07 17:59:19 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nomallocs.h"
#include "../includes/ft_math.h"
#include "../includes/ft_string.h"
#include "../includes/ft_conversion.h"
#include "../includes/pf_parse_directive.h"

void ft_display(int flags, int field_width, int precision, int conversion)
{
	if (flags == ERROR || field_width == ERROR || precision == ERROR || conversion == ERROR)
		return ;
	printf("\n----- FLAGS -----\nFlag: %d\nField width: %d\nPrecision: %d\nConversion: %c\n-----------------\n",
		flags, field_width, precision, conversion);
}

int ft_convert(t_directive *directive, va_list args)
{
	if (directive->type == 'c')
		return (pf_print_char(directive, args));
	else if (directive->type == 's')
		return (pf_print_string(directive, args));
	else if (directive->type == 'p')
		return (pf_print_addr(directive, args));
	else if (directive->type == 'd' || directive->type == 'i')
		return (pf_print_int(directive, args));
	else if (directive->type == 'u')
		return (pf_print_unsigned(directive, args));
	else if (directive->type == 'x')
		return (pf_print_hex(directive, HEX_CHARSET, args));
	else if (directive->type == 'X')
		return (pf_print_hex(directive, HEX_UPPER_CHARSET, args));
	else if (directive->type == '%')
		return (ft_putchar('%'));
	else
		return (ERROR);
}

/*
** Assuming str starts at '%'
*/
int pf_parse_directive(const char **str, va_list args)
{
	t_directive directive;

	pf_init_directive(&directive);
	pf_get_flags(&directive.flags, str);
	directive.field_width = pf_get_field_width(str, args);
	if (directive.field_width < 0)
	{
		directive.flags.minus = 1;
		if (directive.flags.zero == 1)
			directive.flags.zero = WAS_SET;
		directive.field_width = ft_abs(directive.field_width);
	}
	directive.precision = pf_get_precision(str, args);
	directive.type = pf_get_conversion(str);
	//ft_display(flag, field_width, precision, conversion);
	return (ft_convert(&directive, args));
}

int ft_printf(const char *format_string, ...)
{
	int chars_read;
	va_list args;

	chars_read = 0;
	va_start(args, format_string);
	while (*format_string)
	{
		if (*format_string == '%')
		{
			format_string++;
			chars_read += pf_parse_directive(&format_string, args);
		}
		else
		{
			write(1, format_string, 1);
			chars_read++;
			format_string++;
		}
	}
	va_end(args);
	return (chars_read);
}
