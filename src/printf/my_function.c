/*
** my_function.c for  in /home/mart_4/rendu/PSU_2014_minishell2/src/printf
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  8 10:25:22 2015 Thomas Martins
** Last update Sun Mar  8 11:09:04 2015 Thomas Martins
*/

#include "printf.h"

char	*my_strcpy_two(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

int	my_putnbr_long(long unsigned int nb)
{
  if (nb >= 10)
    my_putnbr_long(nb / 10);
  my_putchar(48 + (nb % 10));
  if (nb == 0)
    return (1);
  return (0);
}

int	my_putnbr_long_long(long unsigned int nb)
{
  if (nb >= 10)
    my_putnbr_long(nb /10);
  my_putchar(48+ (nb %10));
  if (nb == 0)
    return (1);
  return (0);
}
