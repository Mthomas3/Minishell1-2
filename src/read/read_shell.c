/*
** read_shell.c for  in /home/mart_4/rendu/PSU_2014_minishell2/src/read
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  8 11:20:39 2015 Thomas Martins
** Last update Fri Oct  9 13:58:00 2015 Thomas Martins
*/

#include "../struct.h"

int	check_word(char *str, char c)
{
  int	len;
  int	a;

  len = 1;
  a = 0;
  while (str[a++])
    {
      if (str[a] == c)
	len++;
      while (str[a] == c)
	a++;
    }
  return (len);
}

int	my_cmd(t_first *sh, t_val *val, char **env, char **avs)
{
  int	a;

  if ((check(sh->buff2)) < 0)
    if ((sh->argument = wordtab(sh->buff2, ' ', val)) == NULL)
      return (-1);
  if ((check(sh->buff2)) > 0)
    {
      epur_str(sh->buff2);
      if ((sh->argument = wordtab(sh->buff2, '\t', val)) == NULL)
	return (-1);
    }
  call_builtin(sh, env);
  if ((check_redir(sh, val, env, avs)) < 0)
    return (-1);
  if ((sh->pid = fork()) == -1)
    return (-1);
  check_sigint();
  if ((my_pid(sh, val, env)) < 0)
    return (-1);
  a = -1;
  while (sh->argument[++a])
    free(sh->argument[a]);
  free(sh->argument[a]);
  return (0);
}

int	read_two(t_first *sh, t_val *val, char **env, char **avs)
{
  char	**tab;
  int	a;
  int	b;

  a = 0;
  while ((sh->fd = read(0, sh->buff, 4095)) > 0)
    {
      sh->buff[sh->fd] = 0;
      if ((tab = split_cmd(sh->buff, ';', val)) == NULL)
	return (-1);
      b = -1;
      while (tab && tab[++b])
	{
	  a = -1;
	  while (tab[b][++a] == ' ');
	  sh->buff2 = &tab[b][a];
	  if ((my_cmd(sh, val, env, avs)) < 0)
	    return (-1);
	}
      if ((print_prompt(0, env)) < 0)
	my_putstr("\n$> ");
    }
  return (0);
}

void	end_free(t_first *sh, t_val *val)
{
  free(sh);
  free(val);
}
