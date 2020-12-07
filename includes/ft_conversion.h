/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:28:00 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/07 13:39:51 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSION_H
# define FT_CONVERSION_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int ft_int_size(long int n, int base);
int ft_atoi(const char **str);
char *ft_itoa(int n);
char *ft_utoa(unsigned int n);
char			*ft_utoa_base(unsigned int n, char *base);
#endif
