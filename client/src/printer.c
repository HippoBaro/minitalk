/*
** printer.c for Minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Wed Mar  4 00:06:56 2015 Hippolyte Barraud
** Last update Wed Mar  4 03:31:45 2015 Hippolyte Barraud
*/

#include "../../includes/client.h"

static void	DoProgress(int percent)
{
  char		*datarate;
  char 		*eta;
  int		width;
  int		pos;
  int		i;

  eta = get_eta(percent);
  datarate = get_datarate();
  width = 80 - my_strlen(datarate) - my_strlen(eta);
  my_putstr(datarate);
  pos = (percent * width) / 100 + 1;
  i = 0;
  my_putstr("[");
  while (i++ < pos)
    my_putstr("=");
  if (percent < 100)
    my_putstr(">");
  else
    my_putstr("=");
  i = 0;
  while (i++ < width - pos + 1)
    my_putstr(" ");
  my_putstr("]");
  my_putstr(eta);
}

static void	print_metadata()
{
  g_data->stats.percent = -1;
  print_colored(CONNECTED, GREEN);
  my_putstr(GREEN);
  my_put_nbr(g_data->target_pid);
  my_putstr(".\n\n");
  my_putstr(BLANK);
  print_colored("Sending metadata :\n", BLUE);
  my_putstr("Data lenght : ");
  my_put_nbr(g_data->len);
  my_putstr(" bytes.\n");
  my_putstr("Data checksum : ");
  my_put_nbr(g_data-> checksum);
  my_putstr(".\n");
}

void	print_stage(bool meta_sent)
{
  if (meta_sent == FALSE)
    print_metadata();
  else if (!g_data->bools.did_print_meta_comfirm)
    {
      g_data->bools.did_print_meta_comfirm = TRUE;
      print_colored("[OK]\n\n", GREEN);
      my_putstr("Transmitting main data...\n");
    }
  else if ((int)((float)g_data->i_byte /
		 (float)g_data->len * 100) >  g_data->stats.percent)
    {
      my_putstr("\r");
      g_data->stats.percent = (int)((float)g_data->i_byte /
				    (float)g_data->len * 100);
      DoProgress(g_data->stats.percent);
    }
}

void print_pid(int pid)
{
  my_putstr("Client PID : ");
  my_put_nbr(pid);
  my_putstr("\n");
}
