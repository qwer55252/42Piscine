/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:10:18 by sajung            #+#    #+#             */
/*   Updated: 2022/05/19 23:10:23 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_while(char i, char j, char k, char *separate)
{	
	while (i <= '7')
	{
		j = i + 1;
		k = i + 2;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				write(1, &i, 1);
				write(1, &j, 1);
				write(1, &k, 1);
				if (i == '7' && j == '8' && k == '9')
				{
					i++;
					break ;
				}
				write(1, separate, 2);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;
	char	separate[2];

	i = '0';
	j = '1';
	k = '2';
	separate[0] = ',';
	separate[1] = ' ';
	print_while(i, j, k, separate);
}
