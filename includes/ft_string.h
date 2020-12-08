/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:18:31 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 19:03:53 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# include <unistd.h>

int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_putchar(char c);
int		ft_putnchar(char c, int n);
int		ft_putstr(char *str);

#endif
