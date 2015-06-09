/*
** get_env_next.c for  in /home/mart_4/TeamWork/Minitwo
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb  8 00:58:27 2015 Thomas Martins
** Last update Sun Mar  8 00:26:54 2015 Thomas Martins
*/

#include "../struct.h"

char	*my_backpath(char *path)
{
  int	i;

  i = 0;
  while (path[i] != 0)
    i++;
  while (path[i] != '/')
    i--;
  path[i + 1] = '\0';
  return (path);
}

int	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar(48 + (nb % 10));
  if (nb == 0)
    return (1);
  return (0);
}

void	put_host(char *str)
{
  int	a;

  a = 0;
  my_putchar('(');
  while (str[a])
    {
      my_putchar(str[a]);
      a++;
    }
  my_putstr("/@_/");
}
