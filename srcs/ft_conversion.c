/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:25:49 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 15:48:50 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_conversion.h"
#include "../includes/ft_string.h"
#include "../includes/pf_types.h"

int		ft_atoi(const char **str)
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

int		ft_int_size(long int n, int base)
{
	int	length;

	length = 1;
	if (n < 0)
		length++;
	while (n /= base)
		length++;
	return (length);
}

char	*ft_itoa(long n)
{
	char	*str;
	size_t	length;
	int		negative;

	negative = (n < 0) ? 1 : 0;
	length = ft_int_size(n, DECIMAL_BASE);
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

int		ft_unsigned_size(unsigned long long n, int base)
{
	int	length;

	length = 1;
	while (n /= base)
		length++;
	return (length);
}

char	*ft_utoa(unsigned long long n)
{
	char	*str;
	size_t	length;

	length = ft_unsigned_size(n, DECIMAL_BASE);
	if ((str = malloc(1 + length * sizeof(char))))
	{
		str[length--] = '\0';
		while (n != 0)
		{
			str[length--] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (str);
}

char	*ft_utoa_base(unsigned long long n, char *base)
{
	char	*str;
	size_t	length;
	int		base_size;

	base_size = ft_strlen(base);
	length = ft_unsigned_size(n, base_size);
	if ((str = malloc(1 + length * sizeof(char))))
	{
		str[length--] = '\0';
		while (n != 0)
		{
			str[length--] = base[n % base_size];
			n /= base_size;
		}
	}
	return (str);
}
