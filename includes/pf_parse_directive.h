/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_directive.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:52:08 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/04 18:01:42 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PARSE_DIRECTIVE_H
# define PF_PARSE_DIRECTIVE_H
# include <stdarg.h>
# include "pf_types.h"
void	pf_init_directive(t_directive *directive);
int		pf_get_conversion(const char **str);
int		pf_get_precision(const char **str, va_list args);
int		pf_get_field_width(const char **str, va_list args);
int		pf_get_flags(t_flags *flags, const char **str);
#endif
