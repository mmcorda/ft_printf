#include "../ft_printf.h"

int   fill_type(char *str, t_format)
{
      int type;
  
      type = get_conv_type(str);
      format->type = type;
      return (type);
}

int   fill_dash_indicator(str, t_format *format)
{
      int dash;
  
      dash = found_char(str, '-');
      if (dash == 1)
      {
              format->indicator[1] = 1;
      }
      return (dash);
}

int   fill_zero_indicator(char *str, t_format *format)
{
        if (found_char(str, '-') == 1)
        {
                format.indicator[0] = 0;
                format.indicator[1] = 1;
                return (0);
        }
        else
        {
                //Voir cette partie pour le cas d'erreur
                if (str[1] == '0')
                {
                        format.indicator[0] = 1;
                        format.indicator[1]
                        return (1);
                }
        }
        return (0);
}

int   fill_width(char *str, t_format format)
{
      int   precision;
      
      width = get_width(str);
      format->width = width;
      return (width);
}

int   fill_precision(char *str, t_format *format)
{
      int   precision;
      
      precision = get_precision(str);
      format->precision = precision;
      return (precision);
}

int   fill_type(char *str, t_format *format)
{
      int   type;
      
      type = get_conv_type(str);
      format->type = type;
      return (type);
}
      
      
        
