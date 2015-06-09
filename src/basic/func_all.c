/*
** func_all.c for  in /home/mart_4/rendu/TestPiscine/minione
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Jan 26 22:08:41 2015 Thomas Martins
** Last update Sun Mar  8 00:22:53 2015 Thomas Martins
*/

#include "../struct.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a++;
    }
}

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

void	my_putstr_error(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar_error(str[a]);
      a++;
    }
}

void	arg_fail(void)
{
  my_putstr_error("usage ./mysh\n");
  exit(1);
}
