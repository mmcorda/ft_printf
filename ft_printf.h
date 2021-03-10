#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

# define ERROR -1
# define DONE 0
# define SIGNED_INT 1
# define UNSIGNED_INT 2
# define ALPHA 3
# define PERCENT 4
# define HEXA 5
# define POINTER 6

typedef struct  s_flags
{
        bool    justify_left;
        bool    pad_zero;
}                                 t_flags;

typedef struct  s_format
{
       // int indicator[2]; //0 = 0 et 1 = dash
        t_flags flags;
        int width;
        int precision;
        int type;
}                                 t_format;

int ft_printf(const char *format, ...);
int is_numeric_conv(char c);
int is_alpha_conv(char c);

/*
** UTILS - separer plus tard
*/

int     found_char(const char *str, char c);
int     correct_type(char c);
int     ft_isdigit(int c);
void    ft_putchar(char c);
void    ft_putnbr(int nbr);
int     ft_strlen(const char *s);

int     correct_spec(char *s);
int     ft_putstr(char *str);
int     find_next_correct_type_no_pc(const char *str);
int     count_total_pc(const char *str);
//No "pc" = no %
int     is_correct_type_no_pc(char c);

/*
**  struct.c part
*/

t_format  ft_init_struct(void);
void    fill_struct_element(char *str, t_format *format);
int     count_format(char *str);

/*
** get_struct
*/

int get_conv_type(char *str);
int get_width(char *str);
int get_precision(char *str);

/* 
** fill_struct.c - revoir params
*/

int     fill_type(char *str, t_format *format);
int     fill_width(char *str, t_format *format);
int     fill_precision(char *str, t_format *format);
bool    justify_left(const char *str, t_format *format);
bool    pad_zero(const char *str, t_format *format);

/*
** split_formats.c
*/

char  *ft_format_dup(char *str);
char  **split_format(char *str);

/*
** manage_type.c a revoir (autres fonctions dans fichiers separes)
*/

int     get_type(const char *format, int *printed_chars);

/*
** type_pc.c
*/

void    print_pc(const char *str, t_format *format, int *print_chars);

//int fill_dash_indicator(char *str, t_format *format);
//int fill_zero_indicator(char *str, t_format *format);

#endif
