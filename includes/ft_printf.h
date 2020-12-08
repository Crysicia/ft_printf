/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:07:08 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 21:33:27 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
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

int	pfi_print_field_width(t_directive *directive, int max, long *value);
int	pfi_handle_zero(int precision, int field_width);
int	pfi_print_precision(t_directive *d, long *v);

int	pfa_print_field_width(t_directive *directive, int max, int *head);
int	pfa_handle_zero(int precision);
int	pfa_print_precision(t_directive *d, unsigned long long *v, int *head);

int	pfh_print_field_width(t_directive *directive, int max);
int	pfh_handle_zero(int precision, int field_width);
int	pfh_print_precision(t_directive *d, char *charset, unsigned int *value);

int	pf_putnstr(const char *str, int limit);

int	pfu_print_field_width(t_directive *directive, int max);
int	pfu_handle_zero(int precision, int field_width);
int	pfu_print_precision(t_directive *d, unsigned int *v);

#endif
