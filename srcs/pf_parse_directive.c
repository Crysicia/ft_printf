/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_directive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:42:26 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 15:57:01 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pf_parse_directive.h"
#include "../includes/ft_conversion.h"
#include "../includes/nomallocs.h"
#include "../includes/ft_string.h"

void	pf_init_directive(t_directive *directive)
{
	directive->flags.zero = NOT_SET;
	directive->flags.minus = NOT_SET;
	directive->field_width = 0;
	directive->precision = NOT_SET;
	directive->type = 0;
}

int		pf_get_conversion(const char **str)
{
	int conversion;

	if (ft_strchr("cspdiuxX%", **str))
	{
		conversion = (int)**str;
		*str += 1;
		return (conversion);
	}
	return (ERROR);
}

int		pf_get_precision(const char **str, va_list args)
{
	int arg;

	if (**str != '.')
		return (NOT_SET);
	*str += 1;
	if (**str == '*')
	{
		*str += 1;
		arg = va_arg(args, int);
		return (arg < 0 ? NOT_SET : arg);
	}
	return (ft_atoi(str));
}

int		pf_get_field_width(const char **str, va_list args)
{
	if (**str == '*')
	{
		*str += 1;
		return (va_arg(args, int));
	}
	return (ft_atoi(str));
}

int		pf_get_flags(t_flags *flags, const char **str)
{
	while (ft_strchr("0-", **str))
	{
		if (**str == '0')
			flags->zero = 1;
		if (**str == '-')
			flags->minus = 1;
		*str += 1;
	}
	if (flags->zero == 1 && flags->minus == 1)
		flags->zero = WAS_SET;
	return (1);
}
