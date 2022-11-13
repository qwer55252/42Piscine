/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:51:22 by sajung            #+#    #+#             */
/*   Updated: 2022/06/09 17:42:26 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	*arr;
	int	i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	arr = (int *)malloc(sizeof(int) * len + 1);
	if (arr == 0)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (i);
}
