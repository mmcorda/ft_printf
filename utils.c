#include "../ft_printf.h"

int   found_char(char *str, char c)
{
      int i;
  
      i = 0;
      while (str[i])
      {
              if (str[i] == c)
                      return (1);
              i++;
      }
      return (0);
}

int	is_correct_type(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 's' || c == 'c' ||
		c == 'x' || c == 'X' || c == 'p')//Attention au cas du %
		return (1);
	return (0);
}
