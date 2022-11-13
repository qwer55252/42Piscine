/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:09:26 by sajung            #+#    #+#             */
/*   Updated: 2022/05/24 16:36:23 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ab_write(char a1, char a2, char b1, char b2)
{
	write(1, &a1, 1);
	write(1, &a2, 1);
	write(1, " ", 1);
	write(1, &b1, 1);
	write(1, &b2, 1);
}

void	ft_print_comb2_comb(char a1, char a2)
{
	char	b1;
	char	b2;

	b1 = a1;
	b2 = a2 + 1;
	while (b1 <= '9')
	{
		while (b2 <= '9')
		{
			ab_write(a1, a2, b1, b2);
			if (a1 == '9' && a2 == '8')
			{
				break ;
			}
			write(1, ", ", 2);
			b2++;
		}
		b1++;
		b2 = '0';
	}
}

void	ft_print_comb2(void)
{
	char	a1;
	char	a2;

	a1 = '0';
	a2 = '0';
	while (a1 <= '9')
	{
		while (a2 <= '9')
		{
			ft_print_comb2_comb(a1, a2);
			a2++;
		}
		a1++;
		a2 = '0';
	}
}
