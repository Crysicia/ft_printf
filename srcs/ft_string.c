/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:18:02 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 15:50:27 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_string.h"

int		ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
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

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putnchar(char c, int n)
{
	int i;

	i = 0;
	if (n < 1)
		return (0);
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (n);
}

int		ft_putstr(char *str)
{
	int length;

	length = ft_strlen(str);
	write(1, str, length);
	return (length);
}
