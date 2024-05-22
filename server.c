/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:39:03 by sgalli            #+#    #+#             */
/*   Updated: 2023/03/09 17:56:14 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_r	g_r;

// se prende SIGSUR1 cioe 0 lo scrive con la conversione 0 | 0 che fa sempre 0
//senno con SIGUSR2 cioe 1 lo fa con 1 | 1 che fa sempre 1
//se arrivo a 8 bits lo scrivo in ascii
//se non e nullo lo scrivo con &(g_r.c)
//se e arrivato alla fine e il server a finito tutto
//exit(0) esce
//se ci sono dei problemi con il pid del client esci
void	conversion(int s_n, siginfo_t *info, void *ctxt)
{
	(void)ctxt;
	if (s_n == SIGUSR1)
	{
		g_r.c = (g_r.c << 1) | 0;
	}
	else if (s_n == SIGUSR2)
	{
		g_r.c = (g_r.c << 1) | 1;
	}
	g_r.bits = g_r.bits + 1;
	if (g_r.bits == 8)
	{
		if (g_r.c != 0)
		{
			write(1, &(g_r.c), 1);
		}
		else if (g_r.c == '\0' && kill(info->si_pid, SIGUSR2) == -1)
			exit(1);
		g_r.c = 0;
		g_r.bits = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		exit(1);
}

//prende il pid del client (act.sa_flags = SA_SIGINFO;)
//converte il carattere (act.sa_sigaction = conversion;)
//prende il bit 0 ignorando i vecchi (sigaction(SIGUSR1, &converter, NULL);)
//prende il bit 1 ignorando i vecchi(sigaction(SIGUSR2, &converter, NULL);)
int	main(void)
{
	struct sigaction	converter;

	converter.sa_flags = SA_SIGINFO;
	converter.sa_sigaction = conversion;
	sigaction(SIGUSR1, &converter, NULL);
	sigaction(SIGUSR2, &converter, NULL);
	g_r.c = 0;
	g_r.bits = 0;
	ft_printf("your pid(process identifier) is : %d\n\n", getpid());
	while (1)
	{
		sleep(1);
	}
}
