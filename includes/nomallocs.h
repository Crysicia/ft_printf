#ifndef NOMALLOCS_H
# define NOMALLOCS_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include "pf_types.h"
# include "pf_parse_directive.h"

void ft_display(int flags, int field_width, int precision, int conversion);
int ft_convert(t_directive *directive, va_list args);
int ft_printf(const char *format_string, ...);
int pf_print_int(t_directive *directive, va_list args);
int pf_print_char(t_directive *directive, va_list args);
int pf_print_string(t_directive *directive, va_list args);
int pf_print_unsigned(t_directive *directive, va_list args);

#endif
