#include "ft_printf.h"

void  print_s(t_format *format, va_list arg_ptr)
{
  int   i;
  char  *str;
  /*
  printf("\n----------------\n");
  printstruct(format);
  printf("\n----------------\n");
  */
  str = va_arg(arg_ptr, char *);
  //printf("%s\n, str);
  i = 0;
  i += ft_putstr(str);
  format->printed_chars += i;
  (void)format;
}
