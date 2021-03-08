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
              return (ERROR);
      return (0);
}

//Width arrive apres indicateur si il y en a
//Width = entier decimal non negatif qui controle le nb minimal de char qui sont generes

//faire confition si il y a un indicator et else
//voir si width est undifined

int   get_width(char *str)
{
      int   width;
      int   i;
      
      width = 0;
      i = 1;
      while (str[i] == '-' || str[i] == '0')
            i++;
      while (ft_isdigit(str[i]) && str[i]) //tant que mon char est un nb decimal
      {
            width = width * 10 + str[i] - '0'; //on enleve la virgule
            i++;
      }
      return (width);
}

int        get_precision(char *str)
{
      int   precision;
      int   i;
      
      precision = 0;
      i = 1;
      while (str[i] && str[i] != '.')
            i++;
      while (ft_isdigit(str[i]) && str[i])
      {
            precision = precision * 10 + str[i] - '0';
            i++;
      }
      printf("%i\n", precision);
      return (precision);
}
