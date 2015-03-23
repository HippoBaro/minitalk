/*
** server.h for minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Feb 27 21:40:48 2015 Hippolyte Barraud
** Last update Wed Mar  4 00:16:18 2015 Hippolyte Barraud
*/

#ifndef SERVER_H_
# define SERVER_H_

#include "common.h"

# define HEADER_DATA		BLUE "---------------------------------\
-DATA BEGIN-----------------------------------\n" BLANK
# define FOOTER_DATA		BLUE "----------------------------------\
-DATA END------------------------------------\n" BLANK

typedef	struct	s_serv
{
  int		c_pid;
  bool		error;
  int		n;
  int		len;
  int		cs;
  int		bitchar;
  int		i;
  int		bitint;
  char		*str;
  int 		checksum;
}	       	t_serv;

t_serv		*g_data;

/*
** main.c
*/
void	init_data(t_serv *ptr, bool force);
void	*xmalloc(size_t size);

/*
** transaction.c
*/
void	transaction_index(int signal);
void 	transaction_completed(void);

/*
** tranfer.c
*/
void 	handle_transfer_error(void);
void 	fill_char(int signal);
bool	fill_int(int signal, int *target);

#endif /* SERVER_H_ ! */
