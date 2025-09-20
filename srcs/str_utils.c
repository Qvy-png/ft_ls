/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-agu <rdel-agu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:46:54 by rdel-agu          #+#    #+#             */
/*   Updated: 2025/09/20 13:00:02 by rdel-agu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_putchar(char c){

	write(1, &c, 1);
}

void	ft_putstr(char *str){

	write(1, &str, ft_strlen(str));
}

int	ft_strlen(char *str){

	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void    ft_putnbr(int n){

	long int	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
