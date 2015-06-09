/*
** pid.c for * in /home/mart_4/TeamWork/Minitwo
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb  8 12:08:16 2015 Thomas Martins
** Last update Sun Mar 29 22:17:20 2015 Thomas Martins
*/

#include <string.h>
#include "../struct.h"

void	function_check_error(t_first *sh, int nbr)
{
  if (sh->tab[nbr] == 0 && sh->check == 0 && sh->e_check == 0)
    {
      my_printf("Command not found => '%s' <= \n", sh->argument[0]);
      exit(1);
    }
}

int	check_my_tab(t_first *sh)
{
  int	a;

  a = 0;
  while (sh->argument[a])
    {
      if (*sh->argument[0] == ';')
  	{
  	  my_putstr("bash: syntax error near unexpected tolen `;'\n");
  	  sh->e_check++;
  	}
      a++;
      sh->e_check = 0;
    }
  return (0);
}

int	my_exec(t_first *sh, char **env)
{
  int	a;

  a = 0;
  if ((execve(sh->str_two, sh->argument, env)) == -1)
    a++;
  else
    return (1);
  return (0);
}

int	my_pid_two(t_first *sh, char **env, int a)
{
  if (!my_strncmp(sh->argument[0], "./", 2))
    execve(sh->argument[0], &sh->argument[1], env);
  else
    {
      while (sh->tab[a])
	{
	  if ((sh->str_two = my_strcat(sh->tab[a], sh->argument[0])) == NULL)
	    return (-1);
	  my_exec(sh, env);
	  ++a;
	}
    }
  check_my_tab(sh);
  function_check_error(sh, a);
  exit(0);
}

int	my_pid(t_first *sh, t_val *val, char **env)
{
  int	a;

  a = 0;
  (void)val;
  sh->status = 0;
  if (sh->pid == 0)
    {
      if ((my_pid_two(sh, env, a)) < 0)
	return (-1);
    }
  else
    wait(&sh->status);
  return (0);
}
