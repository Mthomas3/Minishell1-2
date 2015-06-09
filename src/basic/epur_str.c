/*
** epur_str.c for  in /home/mart_4/rendu/PSU_2014_minishell2/src/basic
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 29 13:51:47 2015 Thomas Martins
** Last update Sun Mar 29 18:47:58 2015 Thomas Martins
*/

#include "../struct.h"

char	*epur_str(char *s)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (s == NULL)
    return (NULL);
  while (s[i])
    {
      if (s[i] != ' ' && s[i] != '\t')
	{
	  s[j] = s[i];
	  j++;
	  if (s[i + 1] == ' ' || s[i + 1] == '\t')
	    {
	      s[j] = ' ';
	      j++;
	    }
	}
      i++;
    }
  s[j] = '\0';
  if (s[j - 1] == ' ')
    s[j - 1] = '\0';
  return (s);
}
