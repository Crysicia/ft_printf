/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpassera <lpassera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:00:26 by lpassera          #+#    #+#             */
/*   Updated: 2020/12/06 13:23:59 by lpassera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_TYPES_H
# define PF_TYPES_H

#define NOT_SET -256
#define WAS_SET -1024
#define ERROR -512
#define FLAG_MINUS 256
#define FLAG_ZERO 512

typedef struct s_flags
{
	int zero;
	int minus;
}					t_flags;

typedef struct	s_directive
{
	t_flags     flags;
	int			field_width;
	int			precision;
	int			type;
}				t_directive;

#endif
