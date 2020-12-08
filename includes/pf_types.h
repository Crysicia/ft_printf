/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:00:26 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/08 21:17:51 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_TYPES_H
# define PF_TYPES_H

# define NOT_SET -256
# define ERROR -1
# define FLAG_MINUS 256
# define FLAG_ZERO 512
# define DECIMAL_BASE 10
# define HEX_BASE 16
# define HEX_CHARSET "0123456789abcdef"
# define HEX_UPPER_CHARSET "0123456789ABCDEF"
# define DECIMAL_CHARSET "0123456789"

typedef struct	s_flags
{
	int			zero;
	int			minus;
}				t_flags;

typedef struct	s_directive
{
	t_flags		flags;
	int			field_width;
	int			precision;
	int			type;
}				t_directive;

#endif
