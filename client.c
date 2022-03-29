/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:37:45 by mrafik            #+#    #+#             */
/*   Updated: 2022/03/29 18:33:18 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

int	main(int argc,	char **argv)
{
	int		x;
	int		y;
	pid_t	pid;

	y = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][y])
		{
			x = 7;
			while (0 <= x)
			{
				if (argv[2][y] & (1 << x))
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				usleep(200);
				x--;
			}
			y++;
		}
	}
}
