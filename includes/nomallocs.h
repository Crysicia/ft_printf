#ifndef NOMALLOCS_H
# define NOMALLOCS_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

#define NOT_SET -256
#define ERROR -512
#define FLAG_MINUS 256
#define FLAG_ZERO 512


void ft_display(int flags, int field_width, int precision, int conversion);

int ft_convert(int flag, int field_width, int precision, int conversion, va_list args);
int ft_putchar(char c);
int get_conversion(const char **str);
int get_precision(const char **str, va_list args);
int get_field_width(const char **str, va_list args);
int get_flags(const char **str);
int				ft_atoi(const char **str);
char	*ft_strchr(const char *s, int c);
int ft_abs(int n);
int ft_printf(const char *format_string, ...);
int ft_parse_directive(const char **str, va_list args);

int ft_putstr(char *str);
int ft_putnchar(char c, int n);
int	ft_strlen(const char *s);

int pf_print_int(int flag, int field_width, int precision, va_list args);
char			*ft_itoa(int n);
int pf_int_size(int n);
int ft_max(int a, int b);

#endif
