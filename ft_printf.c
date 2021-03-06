#icnclude "ft_printf.h"

void    ft_putchar(char c)
{
        write(1, &c, 1);
}
  
int     ft_printf(const char *format, ...)
{
        int   i;
        int   c;
//On creer un compteur qui va se souvenir de combien de % on a croiser.
        i = 0;
        count = 0;
        //va_start(args, ?)
        while (format[i])
        {
                  if (format[i] != '%')
                  {
                          ft_puthcar(format[i]);
                  }
                  else
                  {
                          count++;
                          va_args(args, int);
                          //incrementer va_args?
                          i++;
                          if (format[i] == '%')
                                   ft_putchar('%');
                          else if (format[i] == 'c')
                                   this_c(format[i], args);
                          else if (format[i] == 's')
                                   this_s(format[i], args);
                          else if (format[i] == 'p')
                                   this_p(format[i], args);
                          else if (format[i] == 'd' || format[i] == 'i')
                                   this_dori(format[i], args);
                          else if (format[i] == 'u')
                                   this_u(format[i], args);
                          else if (format[i] == 'x' || format[i] == 'X')
                                   this_xx(format[i], args);
                          return(0);
                  }
                  i++;
        }
        va_end(args);
        return (1);
}
