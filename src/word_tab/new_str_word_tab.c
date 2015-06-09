/*
** str.c for  in /home/mart_4/rendu/TestPiscine/minishel/projet_1
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Thu Jan 22 01:50:48 2015 Thomas Martins
** Last update Sun Mar  8 22:40:18 2015 Thomas Martins
*/

#include "../struct.h"

char	**split_algo(char *s, char c, t_val *val, char **tab)
{
  while (s[val->i] != '\0' && s[val->i] != '\n')
    {
      val->b = 0;
      if (s[val->i] == c && s[val->i + 1] == c)
	break ;
      if (val->i != 0)
	val->i++;
      if ((tab[val->a] = malloc((str_clen(s, c) + 1) * sizeof(char))) == NULL)
	return (clean_tab(tab, val->a - 1));
      while ((s[val->i] != c) && (s[val->i] != '\n') && (s[val->i] != '\0'))
	tab[val->a][val->b++] = s[val->i++];
      tab[val->a][val->b] = '\0';
      val->a++;
    }
  tab[val->a] = 0;
  return (tab);
}

char	**split_cmd(char *s, char c, t_val *val)
{
  char	**tab;

  if (*s == ';' || s == NULL)
    return (NULL);
  if ((tab = malloc((check_word(s, c) + 1) * sizeof(char *))) == NULL)
    return (NULL);
  init_value(val);
  if ((split_algo(s, c, val, tab)) == NULL)
    return (NULL);
  return (tab);
}
