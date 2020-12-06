/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:25:49 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/06 18:07:58 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_conversion.h"
#include "../includes/ft_string.h"

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

int ft_int_size(long int n)
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
	length = ft_int_size(n);
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

char			*ft_utoa(unsigned int n)
{
	char	*str;
	size_t	length;

	length = ft_int_size(n);
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
