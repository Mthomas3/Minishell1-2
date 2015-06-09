/*
** str_cat.c for  in /home/mart_4/rendu/TestPiscine/minishel/projet_1
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Thu Jan 22 02:06:37 2015 Thomas Martins
** Last update Sat Mar  7 21:19:39 2015 Thomas Martins
*/

#include "../struct.h"

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    a++;
  return (a);
}

char	*my_strcat(char *dest, char *src)
{
  char	*str;
  t_str	*s;

  s = malloc(sizeof(*s));
  str = malloc(my_strlen(dest) * 100);
  if (!str || !s)
    return (NULL);
  s->j = 0;
  s->i = 0;
  str_two(dest, src, s, str);
  return (str);
}

char	*str_two(char *dest, char *src, t_str *s, char *str)
{
  while (dest[s->i] != '\0')
    {
      str[s->i] = dest[s->i];
      s->i++;
    }
  str[s->i++] = '/';
  while (src[s->j] != '\0')
    str[s->i++] = src[s->j++];
  str[s->i] = '\0';
  return (str);
}
