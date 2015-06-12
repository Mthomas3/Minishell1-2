/*
** cat_str.c for  in /home/mart_4/project_github/Minishell1-2/src/basic
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Fri Jun 12 23:22:54 2015 Thomas Martins
** Last update Fri Jun 12 23:26:15 2015 Thomas Martins
*/

#include "../struct.h"

char	*cat_str(char *dest, const char *src)
{
  int	i;
  int	len;

  i = 0;
  len = my_strlen(dest);
  while (src[i])
    {
      dest[len + i] = src[i];
      i++;
    }
  dest[len + i] = '\0';
  return (dest);
}
