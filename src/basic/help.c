/*
** help.c for  in /home/mart_4/rendu/TestPiscine/Minitwo
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sat Mar  7 11:16:15 2015 Thomas Martins
** Last update Sun Mar  8 19:39:49 2015 Thomas Martins
*/

#include "../struct.h"

void	help_mini(char *buff, t_first *sh)
{
  if ((my_strncmp(buff, "help", 4)) == 0)
    {
      my_putstr("bonjour && bienvenue dans mon Minishell2\n");
      my_putstr("Les commandes actuellements gérés sont : \n");
      my_putstr("Toutes les commandes du path\n");
      my_putstr("Mais aussi : exit / cd / cd ..");
      my_putstr("le ';' presque le > !\n");
      my_putstr("Voilà, bonne journée et à bientôt!\n");
      sh->check++;
    }
}
