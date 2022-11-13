/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:32:43 by sajung            #+#    #+#             */
/*   Updated: 2022/05/24 17:32:48 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursive(int num, int i, int n, char *arr)
{
	int	j;

	arr[i] = num + '0';
	if (i == n - 1)
	{
		arr[n] = '\0';
		write(1, arr, n);
		if (arr[0] - '0' != 10 - n)
		{
			write(1, ", ", 2);
		}
		return ;
	}
	j = num + 1;
	while (j <= 9)
	{
		recursive(j, i + 1, n, arr);
		j++;
	}
}

void	ft_print_combn(int n)
{
	int		j;
	char	arr[20];

	j = 0;
	while (j <= 10 - n)
	{
		if (j == 10 - n)
		{
			recursive(j, 0, n, arr);
		}
		else
		{
			recursive(j, 0, n, arr);
		}
		j++;
	}
}
