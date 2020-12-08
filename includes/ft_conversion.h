/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:28:00 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 16:34:42 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSION_H
# define FT_CONVERSION_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_int_size(long int n, int base);
int		ft_atoi(const char **str);
char	*ft_itoa(long n);
int		ft_unsigned_size(unsigned long long n, int base);
char	*ft_utoa(unsigned long long n);
char	*ft_utoa_base(unsigned long long n, char *base);

#endif
