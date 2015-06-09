/*
** function_one.c for  in /home/mart_4/rendu/PSU_2014_minishell2/src/printf
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  8 10:25:03 2015 Thomas Martins
** Last update Sun Mar  8 10:25:12 2015 Thomas Martins
*/

#include "printf.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar(48 + (nb % 10));
  if (nb == 0)
    return (1);
  return (0);
}

int	my_putnbr_unsigned(unsigned int nb)
{
  if (nb >= 10)
    my_putnbr_unsigned(nb / 10);
  my_putchar(48 + (nb % 10));
  if (nb == 0)
    return (1);
  return (0);
}
