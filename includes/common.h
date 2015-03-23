/*
** common.h for minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Feb 27 21:40:39 2015 Hippolyte Barraud
** Last update Wed Mar  4 00:11:06 2015 Hippolyte Barraud
*/

#ifndef COMMON_H_
# define COMMON_H_

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

# define ERROR_MALLOC		"Error : Memory allocation failed.\n"
# define ERROR_UNREACH		"Error : Target unreachable.\n"

# define RED	       		"\033[1;31m"
# define GREEN	       		"\033[1;32m"
# define CYAN	       		"\033[1;36m"
# define BLUE	       		"\033[1;34m"
# define YELLOW	       		"\033[1;33m"
# define BLANK	       		"\033[0m"

# define TRUE			1
# define FALSE			0

typedef unsigned char		bool;

void	my_put_nbr(int nb);
void	my_putchar(char c);
void	my_putstr(char *str);
int    	my_getnbr(char *str);
int 	hash (const char *word);
void 	kill_safe(int pid, int signum);
void	print_error(char *descr, bool Critical);
void	print_colored(char *str, char *color);

#endif /* COMMON_H_ ! */
