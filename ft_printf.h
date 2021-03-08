#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

# define ERROR -1
# define DONE 0
# define SIGNED_INT 1
# define UNSIGNED_INT 2
# define ALPHA 3
# define PERCENT 4
# define HEXA 5
# define POINTER 6

typedef struct  s_format
{
        int indicator[2]; //0 = 0 et 1 = dash
        int width;
        int precision;
        int type;
        int lenght;
        int size;
}                                 t_format;

int ft_printf(const char *format, ...);
int is_numeric_conv(char c);
int is_alpha_conv(char c);

/*
** UTILS
*/

int found_char(char *str, char c);
int correct_type(char c);
int ft_isdigit(int c);

/*
**  struct part
*/

t_format  ft_init_struct(void);

/*
** get_struct
*/

int get_conv_type(char *str);
int get_width(char *str);
int get_precision(char *str);

int fill_dash_indicator(char *str, t_format *format);
int fill_zero_indicator(char *str, t_format *format);
int fill_type(char *str, t_format *format);
int fill_width(char *str, t_format *format);
int fill_precision(char *str, t_format *format);
void  fill_struct_element(char *str, t_format *format);
int count_format(char *str);
char  *ft_format_dup(char *str)
char  **split_format(char *str);

#endif
