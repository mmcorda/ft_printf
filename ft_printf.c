#icnclude "ft_printf.h"

//Verifier qu on a bien le bon nombre d element dans va_list?
//Ajouter printed_chars dans la structure ?
//remettre en ptr le spec , retester
int     parse(const char *format, va_list arg_ptr)
{
        t_format        *spec;
        int             len;
        int             printed_chars;
        
        len = 0;
        spec = ft_init_struct();
        //marche pas pour %
        //printf("\nLa string est : "%s\n", &format[i]
        fill_struct(format, spec);//attention a ne pas envoyer des mauvais type
        if (found_star(format))
                handle_star(format, spec, arg_ptr);
        printed_type(format, spec, arg_ptr);
        printed_chars = spec->printed_chars;
        return(printed_chars);
}

void	print_type(const char *str, t_format *spec, va_list arg_ptr)
{
	int type;
	type = spec->type;
	/*
	printf("----------\n");
	printstruct(*spec);
	printf("----------\n");
	*/
	if (type == PC)
		print_pc(str, spec);
	else if (type == S)
	{
		print_s(spec, arg_ptr);
	}
	else if (type == ID)
	{
		print_id(spec, arg_ptr);
	}
	else if (type == U)
	{
		print_u(spec, arg_ptr);
	}
	/*
		return (print_u(format));
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
//Attention differencier i et de printed chars
int     ft_printf(const char *format, ...)
{
        int             printed_chars;
        va_list         arg_ptr;
        int                     i;
        //t_format      spec;
        
        printed_chars = 0;
        i = 0;
        va_start(arg_ptr, format);
//On creer un compteur qui va se souvenir de combien de % on a croiser.
        while (format[i])
        {
                  if (format[i] == '%')
                  {
                          if (!(is_correct_spec(&format[i])))
                                  return (0);
                          printed_chars += parse(&format[i], arg_ptr); //Attention valeur de retour pas bonne/ ok
                          i += len_util_end_format(&format[i]);
                  }
                  else
                  {
                          ft_putchar(format[i]);
                          printed_chars++;
                  }
                  i++;
        }
        va_end(arg_ptr);
        return (printed_chars);
}
