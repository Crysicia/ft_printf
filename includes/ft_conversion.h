/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:28:00 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/04 17:29:58 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSION_H
# define FT_CONVERSION_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

int ft_int_size(int n);
int ft_atoi(const char **str);
char *ft_itoa(int n);
#endif
