/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 02:12:07 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/12 11:22:46 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int				i;
	char			hold[10];
	unsigned int	nbun;

	if (nb == 0)
		write(fd, "0", 1);
	i = 0;
	if (nb < 0)
	{
		nbun = nb * -1;
		write(fd, "-", 1);
	}
	else
		nbun = nb;
	while (nbun > 0)
	{
		hold[i] = nbun % 10 + '0';
		nbun = nbun / 10;
		i++;
	}
	while (i != 0)
	{
		i--;
		write(fd, &hold[i], 1);
	}
}
