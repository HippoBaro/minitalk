/*
** client.h for minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Feb 27 21:40:30 2015 Hippolyte Barraud
** Last update Wed Mar  4 00:10:38 2015 Hippolyte Barraud
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include "common.h"

# define ERROR_SERVER_UNREACH	"Error : Server unreachable.\n"
# define ERROR_TIMEOUT	       	"Error : Server did not answer in \
time (timeout).\n"
# define ERROR_CORRUPTED_DATA	"\nError : Server indicates corrupted \
data. Retrying...\n"
# define ERROR_INVALID_PID	"Error : Invalid PID\n"

# define CONNECTED		"Connection established with server @"
# define TRANSFER_SUCCES       	"\nServer response : transfer completed. \
Data integrity checked.\n"

# define USAGE_BIN	 	"Usage : ./client [PID] [message or \
file URI]\n"

typedef struct	s_stats
{
  int 	       	lastrate;
  time_t       	lasttime;
  int 	       	lastbytetransfered;
  int 	       	percent;
}	       	t_stats;

typedef struct 	s_bool
{
  bool	       	source_isfile;
  bool	       	server_reached;
  bool	       	len_sent;
  bool	       	checksum_sent;
  bool	       	str_sent;
  bool	       	did_print_meta_comfirm;
}		t_bool;

typedef struct	s_client
{
  char		*string;
  int		len;
  int 		checksum;
  int		target_pid;
  int		i_byte;
  int		i_bit;
  t_stats	stats;
  t_bool	bools;
}		t_client;

t_client	*g_data;

int    	my_strlen(char *str);
int    	check_pid(char *pid);
void	check_arg(int ac, char **av);
void 	init_client(int pid, char *str, t_client *ptr);
void	*xmalloc(size_t size);

/*
** transaction.c
*/
void	transaction_error(int signal);
void	transaction_completed();
void	transaction_select(int signum);
void	start_transaction();

/*
** printer.c
*/
void	print_stage(bool meta_sent);
void 	print_pid(int pid);

/*
** bonus.c
*/
char	*get_datarate();
char	*try_readfile(char *uri);
char	*get_eta(int percent);

/*
** binary.c
*/
char	*get_binary(int pid, int coding);

/*
** transision.c
*/
void    init_transmision();
void	send_char(int signal);
void	send_int32(int data);
bool	send_bin(char *bin);
void    init_transmision();

#endif /* CLIENT_H_ ! */
