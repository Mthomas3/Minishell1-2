/*
** struct.h for  in /home/mart_4/rendu/PSU_2014_minishell2
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 29 18:49:08 2015 Thomas Martins
** Last update Sun Mar 29 18:49:11 2015 Thomas Martins
*/

#ifndef STRUCT_H_
# define STRUCT_H_
# define SIZE 1

#include "printf/printf.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct	s_value
{
  int		i;
  int		a;
  int		b;
  int		cpt;
  char		*arg;
  char		*arg_two;
  int		fd_redir;
  int		fd;
  int		stdout_cpy;
}		t_val;

typedef struct	s_next
{
  char		buffer[SIZE + 1];
  char		*str;
  int		j;
}		t_next;

typedef struct  s_list
{
  char		*var;
  struct s_list *prev;
  struct s_list *next;
}               t_list;

typedef struct  s_shell_two
{
  char          **tab;
  char          **argument;
  char		*buff2;
  char		*buff3;
  char          buff[4096];
  pid_t         pid;
  int           fd;
  char          *str_two;
  char		*str_three;
  int		check;
  int		check_two;
  int		status;
  int		e_check;
  char		**arg;
}               t_first;

typedef struct	s_strw
{
  int		j;
  int		i;
}		t_str;

typedef struct	s_pipe
{
  int		b;
  int		c;
}		t_pipe;

typedef struct	s_redir
{
  int		a;
  int		b;
  int		c;
}		t_redir;

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_putstr_error(char *str);
void		arg_fail(void);
void		help_mini(char *buff, t_first *sh);
int		my_getnbr(char *str);
int		my_strcmp(char *s1, char *s2);
char		*my_strstr(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, size_t n);
char		*get_env_user(char **env);
char		*get_env_old(char **env);
char		*get_env_two(char **env, char *s);
char		**get_env(char **env, t_val *val, int ac);
void		put_user(char *str);
char		*my_backpath(char *path);
int		my_putnbr(int nb);
void		put_host(char *str);
int		is_numb(char *s);
void		my_exit(t_first *sh, char *buff);
int		my_cd_check(t_first *sh, char **env);
int		my_cd_home(t_first *sh, char **env);
int		my_cd_two(t_first *sh, char **env);
void		function_check_error(t_first *sh, int nbr);
int		check_my_tab(t_first *sh);
int		my_exec(t_first *s, char **env);
int		my_pid_two(t_first *sh, char **env, int a);
int		my_pid(t_first *sh, t_val *val, char **env);
char		*get_envs(char *id, char **environ);
char		*get_path(char **environ);
int		print_identity(char **environ);
int		print_path(char **environ);
int		print_prompt(char n, char **environ);
int		check_word(char *str, char c);
int		init_value(t_val *val);
int		my_cmd(t_first *sh, t_val *val, char **env);
int		read_two(t_first *sh, t_val *val, char **env);
void		end_free(t_first *sh, t_val *val);
int		check_redir(t_first *sh, t_val *val, char **env);
int		my_redir(t_first *sh, t_val *val, char **env);
char		**split_algo(char *s, char c, t_val *val, char **tab);
char		**split_cmd(char *s, char c, t_val *val);
int		my_strlen(char *str);
char		*my_strcat(char *dest, char *src);
char		*str_two(char *dest, char *src, t_str *s, char *str);
char		**clean_tab(char **tab, int size);
int		str_clen(char *str, char carac);
char		**wordtab_algo(char *s, char c, t_val *val, char **tab);
char		**wordtab(char *s, char c, t_val *val);
void		ctrl_all(int signum);
void		init_terms(char **env, t_first *sh, t_val *val, int ac);
void		check_sigint(void);
char		*epur_str(char *s);
int		check(char *s);
int		call_builtin(t_first *sh, char **env);

#endif
