/*
** my_basicfct.c for  in /home/mart_4/TeamWork/minione
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sat Feb  7 12:34:01 2015 Thomas Martins
** Last update Sun Mar  8 22:32:18 2015 Thomas Martins
*/

#include "../struct.h"

int	my_strcmp(char *s1, char *s2)
{
  while (*s1 && *s1 == *s2)
    {
      ++s1;
      ++s2;
    }
  return (*s1 - *s2);
}

char	*my_strstr(char *s1, char *s2)
{
  int	i;

  if (!s1)
    return (NULL);
  while (*s1)
    {
      i = 0;
      while (*(s1 + i) && *(s1 + i) == *(s2 + i))
	++i;
      if (!*(s1 + i))
	return (s1);
      ++s1;
    }
  if (!*s2)
    return (s1 + my_strlen(s1));
  return (NULL);
}
