/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:12:18 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 15:49:10 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_math.h"

int	ft_max(int a, int b)
{
	return ((a > b) ? a : b);
}

int	ft_min(int a, int b)
{
	return ((a < b) ? a : b);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
