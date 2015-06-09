/*
** call_builtin.c for  in /home/mart_4/rendu/PSU_2014_minishell2/src/read
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 29 14:02:43 2015 Thomas Martins
** Last update Sun Mar 29 14:11:00 2015 Thomas Martins
*/

#include "../struct.h"

int	init_value(t_val *val)
{
  val->i = 0;
  val->a = 0;
  val->b = 0;
  return (0);
}

int	check(char *s)
{
  int	i;
  int	a;

  i = -1;
  a = 0;
  while (s[++i])
    {
      if (s[i] == '\t')
	a++;
    }
  if (a > 0)
    return (1);
  else
    return (-1);
}

int	call_builtin(t_first *sh, char **env)
{
  my_cd_check(sh, env);
  my_cd_home(sh, env);
  my_cd_two(sh, env);
  my_exit(sh, sh->buff2);
  help_mini(sh->buff2, sh);
  return (0);
}
