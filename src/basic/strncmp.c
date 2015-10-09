/*
** strcmp.c for  in /home/mart_4/rendu/TestPiscine/minishel/projet_1
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Thu Jan 22 16:09:31 2015 Thomas Martins
** Last update Fri Oct  9 14:00:03 2015 Thomas Martins
*/

#include <string.h>
#include "../struct.h"

int		my_strncmp(char *s1, char *s2, size_t n)
{
  size_t	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while ((s1[i] == s2[i]) && s1[i] && (i < n))
    i++;
  if (i == n)
    return (0);
  return (s1[i] - s2[i]);
}

char		*my_strcpy(char *dest, const char *src)
{
  char		*d;

  d = dest;
  while (*src)
    *(dest++) = *(src++);
  *dest = 0;
  return (d);
}
