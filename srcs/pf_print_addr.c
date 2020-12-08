/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:25:18 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 18:33:29 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nomallocs.h"
#include "../includes/ft_math.h"
#include "../includes/ft_string.h"
#include "../includes/ft_conversion.h"
#include "../includes/pf_parse_directive.h"

int	pfa_print_field_width(t_directive *directive, int max, int *head)
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
		if (!*head)
		{
			*head = 1;
			printed += ft_putstr("0x");
		}
		padding_char = '0';
	}
	printed += ft_putnchar(padding_char, width);
	return (printed);
}

int	pfa_handle_zero(int precision)
{
	if (precision == 0)
		return (0);
	return (ft_putchar('0'));
}

int	pfa_print_precision(t_directive *d, unsigned long long *v, int *head)
{
	int		printed;
	char	*number;

	printed = 0;
	if (!*head)
	{
		*head = 1;
		printed += ft_putstr("0x");
	}
	printed += ft_putnchar('0', d->precision - ft_unsigned_size(*v, HEX_BASE));
	if (*v == 0)
		printed += pfa_handle_zero(d->precision);
	else
	{
		number = ft_utoa_base(*v, HEX_CHARSET);
		printed += ft_putstr(number);
		free(number);
	}
	return (printed);
}

int	pf_print_addr(t_directive *directive, va_list args)
{
	int					size;
	unsigned long long	value;
	int					printed;
	int					max;
	int					head;

	head = 0;
	printed = 0;
	value = va_arg(args, unsigned long long);
	size = ft_unsigned_size(value, HEX_BASE) + 2;
	if (value == 0 && directive->precision == 0)
		size = 2;
	max = ft_max(directive->precision, size);
	if (directive->flags.minus == 1)
	{
		printed += pfa_print_precision(directive, &value, &head);
		printed += pfa_print_field_width(directive, max, &head);
	}
	else
	{
		printed += pfa_print_field_width(directive, max, &head);
		printed += pfa_print_precision(directive, &value, &head);
	}
	return (printed);
}
