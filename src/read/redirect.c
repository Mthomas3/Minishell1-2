/*
** redirect.c for  in /home/mart_4/rendu/PSU_2014_minishell2/src/read
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  8 17:15:33 2015 Thomas Martins
** Last update Sun Mar 29 18:47:26 2015 Thomas Martins
*/

#include "../struct.h"

int	check_redir(t_first *sh, t_val *val, char **env)
{
  int	a;

  a = -1;
  while (sh->argument[++a])
    {
      if (*sh->argument[a] == '>')
	{
	  val->arg = sh->argument[a - 1];
	  val->arg_two = sh->argument[a + 1];
	  if ((my_redir(sh, val, env)) < 0)
	    return (-1);
	}
    }
  return (0);
}

int	my_redir(t_first *sh, t_val *val, char **env)
{
  char	*tmp;
  char	buff[4096];

  if ((tmp = malloc(sizeof(char *))) == NULL)
    return (-1);
  val->fd_redir = open(val->arg_two, O_WRONLY | O_CREAT
		       | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  val->stdout_cpy = dup(1);
  close(1);
  dup2(val->fd_redir, 1);
  if ((sh->pid = fork()) == -1)
    return (-1);
  if ((my_pid(sh, val, env)) < 0)
    return (-1);
  while ((val->fd = read(1, buff, 4095)) > 0)
    {
      buff[val->fd] = 0;
      write(1, tmp, my_strlen(tmp));
      free(tmp);
    }
  close(val->fd_redir);
  dup2(val->stdout_cpy, 1);
  return (0);
}
