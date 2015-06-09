/*
** printf_two.c for  in /home/mart_4/rendu/PSU_2014_minishell2/src/printf
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  8 11:11:55 2015 Thomas Martins
** Last update Sun Mar  8 11:12:08 2015 Thomas Martins
*/

#include "printf.h"

int	my_flag_two(va_list ap, const char *ftm, int i)
{
  if (ftm[i] == 'X')
    my_putnbr_base_long(va_arg(ap, long int), "0123456789ABCDEF");
  else if (ftm[i] == 'o')
    my_putnbr_base_long(va_arg(ap, long int), "01234567");
  if (ftm[i] == 'l')
    {
      i++;
      if (ftm[i] == 'x')
	my_putnbrbase_long(va_arg(ap, long int), "0123456789abcdef");
      if (ftm[i] == 'X')
	my_putnbrbase_long(va_arg(ap, long int), "0123456789ABCDEF");
      if (ftm[i] == 'i')
	my_put_nbr_long_long(va_arg(ap, long int));
      else if (ftm[i] == 'o' || ftm[i] == 'u')
	i = my_flag_last(ap, ftm, i);
    }
  return (i);
}

int	my_flag_last(va_list ap, const char *ftm, int i)
{
  if (ftm[i] == 'o')
    my_putnbrbase_long(va_arg(ap, long int), "01234567");
  return (0);
}

int     my_put_ld(va_list ap, const char *ftm, int i)
{
  i = i + 1;
  if (ftm[i] == 'd')
    {
      my_put_nbr_long(va_arg(ap, long int));
      return (i);
    }
  if (ftm[i] == 'l')
    {
      i = i + 1;
      if (ftm[i] == 'd')
        {
          my_put_nbr_long_long(va_arg(ap, long int));
          return (i);
        }
    }
  if (ftm[i] == 'x')
    my_putnbr_base(va_arg(ap, long int), "0123456789abcdef");
  else if (ftm[i] == 'X' || ftm[i] == 'i' || ftm[i] == 'o' || ftm[i] == 'u')
    i = my_flag_two(ap, ftm, i);
  return (i);
}

int	my_condition_flag(va_list ap, const char *ftm, int i)
{
  i = i + 1;
  if (ftm[i] == 'o')
    {
      my_putchar('0');
      my_putnbr_base(va_arg(ap, int), "01234567");
    }
  if (ftm[i] == 'l')
    {
      i = i + 1;
      if (ftm[i] == 'o')
	{
	  my_putchar('0');
	  my_putnbr_base_long(va_arg(ap, long int), "01234567");
	}
    }
  return (i);
}
