/*
** struct.h for  in /home/mart_4/rendu/Printf_Warning
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sat Feb  7 23:37:19 2015 Thomas Martins
** Last update Sun Mar  8 22:26:28 2015 Thomas Martins
*/

#ifndef PRINTF_H_
# define PRINTF_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	my_putnbr_unsigned(unsigned int nb);
int	my_putstr_two(char *str, int nb);
char	*my_strcpy_two(char *dest, char *src);
void	my_putnbr_base(int nb, char *base);
int	my_put_nbr_long(long int nb);
int	my_put_nbr_two(int nb, int a);
void	my_putnbr_base_long(long int nb, char *base);
int	my_flag_two(va_list ap, const char *ftm, int i);
int	my_flag_last(va_list ap, const char *ftm, int i);
int	my_put_ld(va_list ap, const char *ftm, int i);
int	my_condition_flag(va_list ap, const char *ftm, int i);
int	function(void *ptr);
int	my_condition_two(va_list ap, const char *ftm, int i);
int	my_condition(va_list ap, const char *ftm, int i);
int	my_printf(const char *ftm, ...);
int	my_putnbr_flag(long unsigned int nb);
int	my_function_two(void *ptr);
void	my_putnbrbase_long(long int nb, char *base);
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_put_nbr(int nb);
int	my_strlen(char *str);
int	my_put_nbr_long(long int nb);
int	my_put_nbr_long_long(long int nb);

#endif
