/*
** main.c for  in /home/mart_4/rendu/PSU_2014_minishell2
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar  8 11:37:18 2015 Thomas Martins
** Last update Wed Jun 10 22:18:06 2015 Thomas Martins
*/

#include <string.h>
#include "src/struct.h"

void		ctrl_all(int signum)
{
  if (signum == SIGINT)
    my_putstr("$>\n");
  else if (signum == SIGQUIT)
    exit(1);
}

void		init_terms(char **env, t_first *sh, t_val *val, int ac)
{
  check_sigint();
  sh->tab = get_env(env, val, ac);
}

void		check_sigint(void)
{
  signal(SIGQUIT, ctrl_all);
  signal(SIGINT, ctrl_all);
}

int		main(int ac, char **av, char **environ)
{
  t_val		*val;
  t_first	*sh;

  if (ac > 1)
    arg_fail();
  if ((val = malloc(sizeof(*val))) == NULL)
    return (1);
  if ((sh = malloc(sizeof(*sh))) == NULL)
    return (1);
  if (ac == 1 && *environ != NULL)
    if ((print_prompt(0, environ)) < 0)
      my_putstr("$>\n");
  init_terms(environ, sh, val, ac);
  sh->check = 0;
  if ((read_two(sh, val, environ, av)) < 0)
    return (1);
  end_free(sh, val);
  return (0);
}
