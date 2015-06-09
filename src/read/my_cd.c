/*
** my_cd.c for  in /home/mart_4/TeamWork/Minitwo
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb  8 01:04:17 2015 Thomas Martins
** Last update Sun Mar  8 22:19:27 2015 Thomas Martins
*/

#include "../struct.h"

int	is_numb(char *s)
{
  int	a;

  a = 0;
  while (s[a])
    {
      if (s[a] < '0' || s[a] > '9')
	return (-1);
      else
	return (1);
      a++;
    }
  return (0);
}

void	my_exit(t_first *sh, char *buff)
{
  int	cpt;

  cpt = 0;
  if ((my_strncmp(buff, "exit", 4)) == 0 && sh->argument[1] != NULL)
    {
      if ((is_numb(sh->argument[1])) == 1)
	{
	  cpt = my_getnbr(sh->argument[1]);
	  exit(cpt);
	}
    }
  else if ((my_strncmp(buff, "exit", 4)) == 0)
    exit(EXIT_SUCCESS);
}

int	my_cd_check(t_first *sh, char **env)
{
  (void)env;
  if ((my_strncmp(sh->buff2, "cd", 2)) == 0)
    {
      chdir(sh->argument[1]);
      sh->check++;
    }
  return (0);
}

int	my_cd_home(t_first *sh, char **env)
{
  char	*get;

  if ((my_strncmp(sh->buff2, "cd", 2)) == 0 && sh->argument[1] == NULL)
    {
      get = get_env_user(env);
      chdir(get);
    }
  return (0);
}

int	my_cd_two(t_first *sh, char **env)
{
  char	*str;

  if ((my_strncmp(sh->buff2, "cd -", 4)) == 0)
    {
      str = get_env_old(env);
      chdir(str);
      sh->check++;
    }
  return (0);
}
