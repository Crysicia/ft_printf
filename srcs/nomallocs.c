/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nomallocs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 09:50:55 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/03 17:15:10 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nomallocs.h"

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_strchr(const char *s, int c)
{
	size_t index;
	size_t s_len;

	index = -1;
	s_len = 0;
	while (s[s_len])
		s_len++;
	while (++index <= s_len)
		if (s[index] == (char)c)
			return ((char *)&s[index]);
	return (NULL);
}

int				ft_atoi(const char **str)
{
	long	total;

	total = 0;
	while (ft_strchr("0123456789", **str))
	{
		total *= 10;
		total += **str - '0';
		*str += 1;
	}
	return (total);
}


/*
** Input : Format string
** Output : Flag code
*** Flag code : 0 = None, 1 = Zero, 2 = minus, -1 = error
*/
int get_flags(const char **str)
{
	int flag;

	flag = NOT_SET;
	while (ft_strchr("0-", **str))
	{
		if (**str == '0' && flag != FLAG_MINUS)
			flag = FLAG_ZERO;
		if (**str == '-')
			flag = FLAG_MINUS;
		*str += 1;
	}
	return (flag);
}

/*
** Input : Format string
** Output : Field width, 0 by default
*/
int get_field_width(const char **str, va_list args)
{
	if (**str == '*')
	{
		*str += 1;
		return (va_arg(args, int));
	}
	return (ft_atoi(str));
}

/*
** Input : Format string
** Output : Precision, 0 by defaul
*/
int get_precision(const char **str, va_list args)
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


/*
** Input : Format string
** Output : conversion char
*/
int get_conversion(const char **str)
{
	int conversion;

	if (ft_strchr("cspdiuxX", **str))
	{
		conversion = (int)**str;
		*str += 1;
		return (conversion);
	}
	return (ERROR);
}

void ft_display(int flags, int field_width, int precision, int conversion)
{
	if (flags == ERROR || field_width == ERROR || precision == ERROR || conversion == ERROR)
		return ;
	printf("\n----- FLAGS -----\nFlag: %d\nField width: %d\nPrecision: %d\nConversion: %c\n-----------------\n",
		flags, field_width, precision, conversion);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putnchar(char c, int n)
{	
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
	return (n);
}

int	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

int ft_putstr(char *str)
{
	int length;

	length = ft_strlen(str);
	write(1, str, length);
	return (length);
}

int ft_convert(int flag, int field_width, int precision, int conversion, va_list args)
{
	if (conversion == 'c')
		return (ft_putchar(va_arg(args, int)));
	// else if (conversion == 's')
	// 	;
	// else if (conversion == 'p')
	// 	;
	else if (conversion == 'd' || conversion == 'i')
		return (pf_print_int(flag, field_width, precision, args));
	// else if (conversion == 'u')
	// 	;
	// else if (conversion == 'x')
	// 	;
	// else if (conversion == 'X')
	// 	;
	else
		return (ERROR);
}

/*
** Assuming str starts at '%'
*/
int ft_parse_directive(const char **str, va_list args)
{
	int flag;
	int field_width;
	int precision;
	int conversion;

	if (**str == '%')
	{
		*str += 1;
		write(1, "%", 1);
		return (1);
	}
	flag = get_flags(str);
	field_width = get_field_width(str, args);
	if (field_width < 0)
	{
		flag = FLAG_MINUS;
		field_width = ft_abs(field_width);
	}
	precision = get_precision(str, args);
	conversion = get_conversion(str);
	//ft_display(flag, field_width, precision, conversion);
	return (ft_convert(flag, field_width, precision, conversion, args));
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
			chars_read += ft_parse_directive(&format_string, args);
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
