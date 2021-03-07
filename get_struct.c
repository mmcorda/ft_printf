#include "../ft_printf.h"

int   get_conv_type(char *str)
{
      int i;
  
      i = 0;
      while (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
              i++;
      if (str[i] == 'i' || str[i] == 'd' || str[i] == 'u')
              return (NUMERIC);
      else if (str[i] == 'c' || str[i] == 's')
              return (ALPHA);
      else if (str[i] == '%')
              return (PERCENT);
      else if (str[i] == 'x' || str[i] == 'X')
              return (HEXA);
      else if (str[i] == 'p')
              return (POINTER);
      //voir ce que je peux faire dans ce cas ?
      else
              return (-1);
}
