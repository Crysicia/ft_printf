/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:50:48 by lpassera          #+#    #+#             */
/*   Updated: 2020/11/27 18:37:11 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int ft_process(const char *format_string, va_list args)
{
	int chars_read;

	chars_read = 0;
	while (*format_string)
	{
		if (*format_string == '%')
		{
			format_string++;
			if (*format_string == '%')
			{
				ft_putchar(*format_string);
				format_string++;
				chars_read++;
			}
			else if (*format_string == 's')
			{
				char *string = va_arg(args, char *);
				ft_putstr(string);
				format_string++;
				chars_read += ft_strlen(string);
			}
			else
			{
				format_string++;
			}
		}
		else
		{
			ft_putchar(*format_string);
			format_string++;
			chars_read++;
		}
	}
	return (chars_read);
}

int ft_printf(const char *format_string, ...)
{
	va_list args;
	int chars_read;

	chars_read = 0;;
	va_start(args, format_string);
	chars_read = ft_process(format_string, args);
	va_end(args);
	return (chars_read);
}

int main(void)
{
	ft_printf("Hello World\n");
	ft_printf("My name is %%s and I love %s, eheh\n", "Crysicia", "chocolate");
	return (0);
}
