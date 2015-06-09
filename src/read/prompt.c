/*
** prompt.c for  in /home/mart_4/rendu/PSU_2014_minishell2/src/read
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  8 11:21:17 2015 Thomas Martins
** Last update Sun Mar  8 22:38:43 2015 Thomas Martins
*/

#include <string.h>
#include "../struct.h"
#include <dirent.h>

char	*get_envs(char *id, char **environ)
{
  int	i;
  int	size;

  size = my_strlen(id);
  i = -1;
  while (environ[++i])
    {
      if (!my_strncmp(environ[i], id, size) && environ[i][size] == '=')
  	return (&environ[i][size + 1]);
    }
  return (NULL);
}

char	*get_path(char **environ)
{
  int	i;

  i = -1;
  while (environ[++i])
    {
      if (!my_strncmp(environ[i], "PWD=", 4))
  	return (&environ[i][4]);
    }
  return (NULL);
}

int	print_identity(char **environ)
{
  char	*user;
  char	*host;

  if ((user = get_envs("USER", environ)) == NULL)
    return (-1);
  my_putstr("[\033[32;1m");
  my_putstr(user);
  my_putstr("\033[0m@\033[35;1m");
  if ((host = get_envs("HOST", environ)) == NULL)
    return (-1);
  my_putstr("[\033[32;1m");
  my_putstr(host);
  my_putstr("\033[0m@\033[35;1m");
  my_putstr("/");
  my_putstr("\033[0m]");
  return (0);
}

int	print_path(char **environ)
{
  char	*home;
  char	*path;
  int	size_home;

  if ((home = get_envs("HOME", environ)) == NULL)
    return (-1);
  if ((path = get_envs("PWD", environ)) == NULL)
    return (-1);
  size_home = my_strlen(home);
  my_putstr("~");
  my_putstr(&path[size_home]);
  return (0);
}

int	print_prompt(char n, char **environ)
{
  if ((get_envs("PWD", environ)) == NULL)
    return (-1);
  if ((get_envs("USER", environ)) == NULL)
    return (-1);
  if ((get_envs("HOST", environ)) == NULL)
    return (-1);
  if (n)
    my_putstr("\n");
  if ((print_identity(environ)) < 0)
    return (-1);
  if ((print_path(environ)) < 0)
    return (-1);
  else
    my_putstr("$>");
  return (0);
}
