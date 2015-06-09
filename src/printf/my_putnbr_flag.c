/*
** my_putnbr_flag.c for  in /home/mart_4/rendu/PSU_2014_minishell2/src/printf
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  8 11:11:10 2015 Thomas Martins
** Last update Sun Mar  8 23:38:49 2015 Thomas Martins
*/

#include "printf.h"

int	my_putnbr_flag(long unsigned int nb)
{
  if (nb >= 10)
    my_putnbr_flag(nb / 10);
  my_putchar(48 + (nb % 10));
  if (nb == 0)
    return (1);
  return (0);
}

int	my_function_two(void *ptr)
{
  my_putstr("0x");
  my_putnbr_base((long int)ptr, "0123456789ABCDEF");
  return (0);
}

void	my_putnbrbase_long(long int nb, char *base)
{
  int	result;
  int	dividor;
  int	size_base;

  size_base = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  dividor = 1;
  while ((nb / dividor) >= size_base)
    dividor = dividor * size_base;
  while (dividor > 0)
    {
      result = (nb / dividor) % size_base;
      my_putchar(base[result]);
      dividor = dividor / size_base;
    }
}
