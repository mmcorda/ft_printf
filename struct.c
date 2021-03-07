#include "../ft_printf.h"

t_format        ft_init_struct(void)
{
        t_format  format;
  
        format.indicator = 0;
        format.width = 0;
        format.precision = 0;
        format.size = 0;
        format.type = 0;
        return (format);
}
