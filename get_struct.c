#include "../ft_printf.h"

//Width arrive apres indicateur si il y en a
//Width = entier decimal non negatif qui controle le nb minimal de char qui sont generes

//faire confition si il y a un indicator et else
//voir si width est undifined
int   get_width(const char *str, t_format format)
{
      int   width;
      int   i;
      
      width = 0;
      i = (format->type == PC) ? 1 : 0;
      while (str[i] == '-' || str[i] == '0')
            i++;
      while (ft_isdigit(str[i]) && str[i]) //tant que mon char est un nb decimal
      {
            width = width * 10 + str[i] - '0'; //on enleve la virgule
            i++;
      }
      format->width = width;
      return (width);
}

int        get_precision(const char *str, t_format format)
{
      int   precision;
      int   i;
      
      precision = 0;
      i = format->type == PC) ? 1 : 0;
      while (str[i] && str[i] != '.')
            i++;
      if (!str[i])
            return (precision);
      i++;
      while (ft_isdigit(str[i]) && str[i])
      {
            precision = precision * 10 + str[i] - '0';
            i++;
      }
      format->precision = precision
      //printf("%i\n", precision);
      return (precision);
}

int   get_type(const char *str) //Get Type Conversion
{
      int i;
  
      i = 0;
      if (format[i] == '%')
              i++;
      while (!(is_correct_type(format[i])) && format[i])
              i++;
      if (format[i] == 'i' || format[i] == 'd' || format[i] == 'u') //format = str ancien
              return (UID); //NUMERIC anciennement
      else if (format[i] == 'c')
              return (C); //ALPHA C
      else if (format[i] == 's')
              return (S); //ALPHA S 
      else if (format[i] == '%')
              return (PC); //PERCENT ancien
      else if (format[i] == 'x' || str[i] == 'X')
              return (H); //HEXA ancien
      else if (format[i] == 'p')
              return (P); //POINTER ancien
      return (0);
}

void  print_type(t_format *spec, va_list arg_ptr)
{
      int   type;
      /*
	printf("\n----------------\n");
	printstruct(spec);
	printf("\n----------------\n");
	*/
      //printf("\nWOUHOU!!\n");
      type = spec->type;
      if (type == PC)
            print_pc(spec);
      else if (type == S)
      {
            print_s(spec, arg_ptr);
      }
      /*s
	else if (type == UID)
		return (print_uid(format));
	else if (type == C)
		return (print_c(format));
	else if (type == H)
		return (print_pc(format));s
	else if (type == P)
		return (print_p(format));
	else
		return (-1);
	*/
}
