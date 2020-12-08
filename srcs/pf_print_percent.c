/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:25:18 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 18:52:15 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_string.h"
#include "../includes/pf_parse_directive.h"

int	pf_print_percent(t_directive *directive)
{
	int		printed;
	char	padding_char;

	printed = 0;
	padding_char = ' ';
	if (directive->flags.minus == 1)
	{
		printed += ft_putchar('%');
		printed += ft_putnchar(padding_char, directive->field_width - 1);
	}
	else
	{
		if (directive->flags.zero == 1)
			padding_char = '0';
		printed += ft_putnchar(padding_char, directive->field_width - 1);
		printed += ft_putchar('%');
	}
	return (printed);
}
