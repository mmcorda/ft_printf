/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:27:18 by mcorda            #+#    #+#             */
/*   Updated: 2021/03/17 12:27:18 by mcorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int count_total_pc(const char *str)
{
  int i;
  int count;
  
  i = 0;
  count = 0;
  if (!str)
    return (0);
  while (str[i])
  {
    if (str[i] == '%')
    {
      count++;
      if (str[i + 1] == '%')
        i++;
    }
    i++;
  }
  return (count);
}

int found_char_until_type(const char *str, char c)
{
  int i;
  
  i = 0;
  if (!str && !c)
    return (0);
  while (str[i] && !(is_correct_type(str[i])))
  {
    if (str[i] == c)
      return (i);
    i++;
  }
  return (0);
}

char  *ft_strdup(const char *s1)
{
  int       i;
  char  *copy;
  
  i = 0;
  if (!s1)
    return (NULL);
  while (s1[i])
    i++;
  if (!(copy = (char *)malloc(sizeof(char) * (i + 1))))
    return (NULL);
  i = 0;
  while (s1[i])
  {
    copy[i] = s1[i];
    i++;
  }
  copy = '\0'
  return (copy);
}

int print_x_prime(char c, int x)
{
  int i;
  
  i = 0;
  while (i < x)
  {
    ft_putchar(c);
    i++;
  }
  return (i);
}
