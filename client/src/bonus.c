/*
** bonus.c for Minitalk in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Wed Mar  4 00:01:40 2015 Hippolyte Barraud
** Last update Wed Mar  4 03:26:39 2015 Hippolyte Barraud
*/

#include <time.h>
#include <stdio.h>
#include "../../includes/client.h"

char		*get_eta(int percent)
{
  static char	out[128];
  static int   	left = -1;

  if (difftime(time(NULL), g_data->stats.lasttime) > 1)
    {
      if ((g_data->i_byte - g_data->stats.lastbytetransfered) != 0)
	left = (g_data->len - g_data->stats.lastbytetransfered) /
	  (g_data->i_byte - g_data->stats.lastbytetransfered);
    }
  if (left == -1)
    sprintf(out, "%d %% - ETA : ? s" BLANK, percent);
  else
    sprintf(out, "%d %% - ETA : %d s" BLANK, percent, left - 1);
  return (&out[0]);
}

char		*get_datarate()
{
  static char	out[45];
  int 		rate;

  rate = g_data->stats.lastrate;
  if (difftime(time(NULL), g_data->stats.lasttime) > 1)
    {
      g_data->stats.lasttime = time(NULL);
      rate = g_data->i_byte - g_data->stats.lastbytetransfered;
      g_data->stats.lastbytetransfered = g_data->i_byte;
      g_data->stats.lastrate = rate;
    }
  if (rate == 0)
    rate = g_data->i_byte;
  if (rate < 1000)
    {
      sprintf(out, BLUE "%5d B/s", rate);
      return (&out[0]);
    }
  sprintf(out, BLUE "%5d KB/s", rate / 1000);
  return (&out[0]);
}

char	*try_readfile(char *uri)
{
  FILE	*f;
  long	fsize;
  char	*str;

  if ((f = fopen(uri, "rb")) == NULL)
    return (NULL);
  fseek(f, 0, SEEK_END);
  fsize = ftell(f);
  fseek(f, 0, SEEK_SET);
  str = xmalloc(fsize + 1);
  fread(str, fsize, 1, f);
  fclose(f);
  str[fsize] = '\0';
  return (str);
}
