/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:45:06 by sgalli            #+#    #+#             */
/*   Updated: 2023/03/13 12:02:51 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	g_server_ready = 1;

void	recived_b(int sig)
{
	(void)sig;
	g_server_ready = 0;
}

/*
cambio il valore di g_server_ready a 0 per avviare la conversione
converto il primo bit con b_value = (c >> i & 1)
se da errori nel bit 1 o 0 cioe -1 esci
(while (g_server_ready != 0);) cicla finche il server non a elaborato il bit
facendolo bit per bit
passa al prossimo bit i--;
*/

void	bit_conversion(int pid, char c)
{
	int	i;
	int	b_value;

	signal(SIGUSR1, recived_b);
	i = 7;
	while (i >= 0)
	{
		b_value = (c >> i & 1);
		g_server_ready = 1;
		if (b_value != 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		while (g_server_ready != 0)
		{
		}
		i--;
	}
}

/*conversione in bit dei caratteri per tutta la stringa*/
void	convert_b(int pid, char *v)
{
	size_t	i;

	i = 0;
	while (v[i] != '\0')
	{
		bit_conversion(pid, v[i]);
		i++;
	}
	bit_conversion(pid, '\n');
	bit_conversion(pid, '\0');
}

//mando la conferma di messaggio e esco
void	message(int sig)
{
	(void)sig;
	ft_printf("message recived :)\n");
	exit(0);
}
/*se il numero di elementi e sbagliato o il 3 elemento non e un numero
(signal(SIGUSR2, message);) mando il messaggio di conferma
(convert_b(pid, v[2]);) converto la parola
il while finale finisce il programma
*/

int	main(int c, char **v)
{
	int	pid;

	pid = 0;
	if (c != 3 || ft_sisdigit(v[1]) == 0)
	{
		ft_printf("number of element or digit error\n");
		exit(1);
	}
	signal(SIGUSR2, message);
	pid = ft_atoi(v[1]);
	convert_b(pid, v[2]);
	while (1)
	{
		pause();
	}
}
