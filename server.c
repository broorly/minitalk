/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:37:56 by mrafik            #+#    #+#             */
/*   Updated: 2022/03/28 20:37:56 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	print_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	write(1, "PID: ", 5);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
}

int	ft_count(int force)
{
	int	s;
	int	i;

	i = 0;
	s = 1;
	while (i < force)
	{
		s *= 2;
		i++;
	}
	return (s);
}

void	handle(int signum)
{
	static int	i = 7;
	static char	print;

	if (SIGUSR1 == signum)
		print += ft_count(i);
	i--;
	if (i == -1)
	{
		write(1, &print, 1);
		print = 0;
		i = 7;
	}
}

int	main(void)
{
	print_pid();
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	while (1)
		pause();
	return (0);
}
