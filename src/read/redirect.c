/*
** redirect.c for  in /home/mart_4/rendu/PSU_2014_minishell2/src/read
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  8 17:15:33 2015 Thomas Martins
** Last update Thu Jun 11 13:06:51 2015 Thomas Martins
*/

#include "../struct.h"

int	check_redir(t_first *sh, t_val *val, char **env, char **avs)
{
  int	a;
  char	*command;
  char	*command_two;

  a = -1;
  command = malloc(sizeof(char *));
  command_two = malloc(sizeof(char *));
  while (sh->argument[++a])
    {
      if (*sh->argument[a] == '>')
	{
	  command = sh->argument[a - 1];
	  command_two = sh->argument[a + 1];
	  if ((my_redir(sh, val, env, command, command_two, avs)) == EXIT_FAILURE)
	    return (-1);
	}
    }
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
  (void)pid;
  sh->check++;
  cmd = "/bin/cat";
  cmd2 = "toto";
  if ((tmp = malloc(sizeof(char **))) == NULL)
    return (EXIT_FAILURE);
  fd = open(cmd2, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  cp = dup(1);
  close(1);
  dup2(fd, 1);
  my_pid(sh, val, env);
  execve(cmd, avs, env);
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
