/*
** my_getnbr.c for  in /home/mart_4/rendu/PSU_2014_minishell2/src/basic
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  8 10:24:00 2015 Thomas Martins
** Last update Sun Mar  8 10:24:09 2015 Thomas Martins
*/

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	c;

  c = 0;
  nb = 0;
  i = 0;
  while (str[i] == 45)
    {
      c = c + 1;
      i = i + 1;
    }
  while (str[i] >= 48 && str[i] <= 57)
    if (nb <= 2147483647)
      {
	nb = nb * 10;
	nb = nb + str[i] - 48;
	i = i + 1;
      }
    else
      return (0);
  if (c % 2 == 1)
    nb = -nb;
  return (nb);
}
