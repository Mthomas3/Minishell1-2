/*
** get_env.c for  in /home/mart_4/TeamWork/Minitwo
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Feb  8 00:55:35 2015 Thomas Martins
** Last update Sun Mar  8 22:36:31 2015 Thomas Martins
*/

#include "../struct.h"

char	*get_env_user(char **env)
{
  char	*s;
  int	a;

  a = 0;
  while (env[a])
    {
      if ((my_strncmp(env[a], "HOME=", 5)) == 0)
	s = &env[a][5];
      a++;
    }
  return (s);
}

char	*get_env_old(char **env)
{
  char	*s;
  int	a;

  a = 0;
  while (env[a])
    {
      if ((my_strncmp(env[a], "OLDPWD=", 7)) == 0)
	s = &env[a][7];
      a++;
    }
  return (s);
}

char	*get_env_two(char **env, char *s)
{
  int	a;

  a = -1;
  while (env[++a] != NULL)
    {
      if ((my_strncmp(env[a], s, my_strlen(s))) == 0)
	return (&env[a][my_strlen(s) + 1]);
    }
  return (NULL);
}

char	**get_env(char **env, t_val *val, int ac)
{
  int	a;
  char	**tab;

  a = 0;
  while (env[a] != NULL)
    {
      if (my_strncmp(env[a], "PATH=", 5) == 0)
	tab = wordtab(&env[a][5], ':', val);
      if (ac > 1)
	{
	  if (my_strncmp(env[a], "HOST=", 5) == 0)
	    put_host(&env[a][5]);
	  if (my_strncmp(env[a], "USER=", 5) == 0)
	    put_user(&env[a][5]);
	}
      a++;
    }
  return (tab);
}

void	put_user(char *str)
{
  int	b;
  int	a;

  b = 0;
  a = 0;
  while (str[a])
    {
      my_putchar(str[a]);
      a++;
      b++;
    }
  my_putchar('/');
  my_putstr(") $>");
}
