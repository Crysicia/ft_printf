/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:07:08 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 19:04:19 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOMALLOCS_H
# define NOMALLOCS_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include "pf_types.h"
# include "pf_parse_directive.h"

int ft_convert(t_directive *directive, va_list args);
int ft_printf(const char *format_string, ...);
int pf_print_int(t_directive *directive, va_list args);
int pf_print_char(t_directive *directive, va_list args);
int pf_print_string(t_directive *directive, va_list args);
int pf_print_unsigned(t_directive *directive, va_list args);
int	pf_print_hex(t_directive *directive, char *charset, va_list args);
int	pf_print_addr(t_directive *directive, va_list args);
int pf_print_percent(t_directive *directive);

#endif
