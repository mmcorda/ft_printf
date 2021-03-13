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
        if (found_char(format))
                handle_star(spec, arg_ptr);
        printed(spec, arg_ptr);
        printed_char = spec->printed_chars;
        return(printed_chars);
}

//Voir si on devrait ajouter une variable pour suivre sur quel caractere on se trouve
//Attention differencier i et de printed chars
//Attention tests plus ok nocrash null spec / ajouter fonction qui verifie
//finir les tests pc 0 15
int     ft_printf(const char *format, ...)
{
        int             printed_chars;
        va_list         arg_ptr;
        int                     i;
        //t_format      spec;
        
        printed_chars = 0;
        i = 0;
        //spec = ft_init_struct()
        //printstruct(spec);
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

/*                          count++;
                          va_args(args, int);
                          //incrementer va_args?
                          i++;
                          if (format[i] == '%')
                                   ft_putchar('%'); //parser
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
*/
