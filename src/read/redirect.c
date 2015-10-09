/*
** redirect.c for  in /home/mart_4/rendu/PSU_2014_minishell2/src/read
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  8 17:15:33 2015 Thomas Martins
** Last update Fri Oct  9 13:50:37 2015 Thomas Martins
*/

#include "../struct.h"
#include <string.h>

int	check_redir(t_first *sh, t_val *val, char **env, char **avs)
{
  int	a;
  char	*command;
  char	*command_two;

  a = -1;
  if (!(command = malloc(sizeof(char *))))
    return (-1);
  if (!(command_two = malloc(sizeof(char *))))
    return (-1);
  while (sh->argument[++a])
    {
      if (*sh->argument[a] == '>')
	{
	  command = sh->argument[a - 1];
	  command_two = sh->argument[a + 1];
	  if ((my_redir(sh, val, env, command,
			command_two, avs)) == EXIT_FAILURE)
	    return (-1);
	}
    }
  return (0);
}

char	*change_str(char *cmd_old)
{
  char	*new_cmd;

  if ((new_cmd = malloc(sizeof(char) * my_strlen(cmd_old) + 1)) == NULL)
    return (NULL);
  new_cmd[0] = '/';
  new_cmd[1] = 'b';
  new_cmd[2] = 'i';
  new_cmd[3] = 'n';
  new_cmd[4] = '/';
  new_cmd[5] = '\0';
  cat_str(new_cmd, cmd_old);
  return (new_cmd);
}

int	pid_redir(char *cmd, char **avs, char **env, int *pid)
{
  int	status;

  status = 0;
  if (*pid == 0)
    {
      if ((execve(cmd, avs, env)) == -1)
	return (EXIT_FAILURE);
    }
  else
    wait(&status);
  return (0);
}

int	my_redir(t_first *sh, t_val *val, char **env, char *cmd, char *cmd2, char **avs)
{
  int	fd;
  int	cp;
  char	*tmp;
  char	buffer[4096];
  int	pid;

  (void)val;
  sh->check++;
  if ((tmp = malloc(sizeof(char **))) == NULL)
    return (EXIT_FAILURE);
  if ((cmd = change_str(cmd)) == NULL)
    return (EXIT_FAILURE);
  fd = open(cmd2, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
	    | S_IWUSR | S_IRGRP | S_IROTH);
  cp = dup(1);
  close(1);
  dup2(fd, 1);
  if ((pid = fork()) == -1)
    return (EXIT_FAILURE);
  if ((pid_redir(cmd, avs, env, &pid)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while ((fd = read(1, buffer, 4095)) > 0)
    {
      buffer[fd] = 0;
      write(1, tmp, my_strlen(tmp));
      free(tmp);
    }
  close(fd);
  dup2(cp, 1);
  return (EXIT_SUCCESS);
}
