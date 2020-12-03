/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:25:18 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/03 17:06:06 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nomallocs.h"

int pf_int_size(int n)
{
	int	length;

	length = 1;
	if (n < 0)
		length++;
	while (n /= 10)
		length++;
	return (length);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	length;
	int		negative;

	negative = (n < 0) ? 1 : 0;
	length = pf_int_size(n);
	// if (n == 0)
	// {
	// 	if ((str = malloc(2 * sizeof(char))))
	// 	{
	// 		str[0] = '0';
	// 		str[1] = '\0';
	// 	}
	// 	return (str);
	// }
	if ((str = malloc(1 + length * sizeof(char))))
	{
		str[length--] = '\0';
		if (negative)
			str[0] = '-';
		while (n != 0)
		{
			str[length--] = (n < 0) ? -(n % 10) + '0' : (n % 10) + '0';
			n /= 10;
		}
	}
	return (str);
}

int ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

int pf_print_field_width(int flag, int precision, int width, int *value)
{
	int printed_chars;
	char padding_char;

	//write(1, "\n-- Print field width\n", 22);
	if (width < 1)
		return (0);
	printed_chars = 0;
	padding_char = ' ';
	if (flag == FLAG_ZERO && precision == NOT_SET)
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

int pf_print_precision(int precision, int field_width, int *value)
{
	int printed_chars;
	//write(1, "\n-- Print precision\n", 20);
	printed_chars = 0;
	if (*value < 0)
	{
		*value = ft_abs(*value);
		printed_chars += ft_putchar('-');
	}
	printed_chars += ft_putnchar('0', precision - pf_int_size(*value));
	if (*value == 0)
		printed_chars += pf_handle_zero(precision, field_width);
	else
		printed_chars += ft_putstr(ft_itoa(*value));
	return (printed_chars);
}

int pf_print_int(int flag, int field_width, int precision, va_list args)
{
	int size;
	int value;
	int printed_chars;
	int max;
	int neg;

	printed_chars = 0;
	value = va_arg(args, int);
	neg = (value < 0) ? 1 : 0;
	size = pf_int_size(value);
	max = ft_max(precision + neg, size);
	// if (precision == 4 && field_width == 5)
	// 	printf("\n\n\n\n----- Flags -----\n-- Flag: %s\n-- Precision: %d\n-- Field width: %d\n\n\n\n", (flag == FLAG_MINUS) ? "Minus" : (flag == FLAG_ZERO) ? "Zero" : "None", precision, field_width);
	if (flag == FLAG_MINUS)
	{
		printed_chars += pf_print_precision(precision, field_width, &value);
		printed_chars += pf_print_field_width(flag, precision, field_width - max, &value);
	}
	else
	{
		printed_chars += pf_print_field_width(flag, precision, field_width - max, &value);
		printed_chars += pf_print_precision(precision, field_width, &value);
	}
	return (printed_chars);
}
