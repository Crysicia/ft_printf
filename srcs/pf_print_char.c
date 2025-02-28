/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:25:18 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 18:52:17 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_string.h"
#include "../includes/pf_parse_directive.h"

int	pf_print_char(t_directive *directive, va_list args)
{
	int c;
	int printed;

	printed = 0;
	c = va_arg(args, int);
	if (directive->flags.minus == 1)
	{
		printed += ft_putchar(c);
		printed += ft_putnchar(' ', directive->field_width - 1);
	}
	else
	{
		printed += ft_putnchar(' ', directive->field_width - 1);
		printed += ft_putchar(c);
	}
	return (printed);
}
