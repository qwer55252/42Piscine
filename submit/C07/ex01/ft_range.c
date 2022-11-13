/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ragne.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:48:26 by sajung            #+#    #+#             */
/*   Updated: 2022/06/09 17:33:28 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*arr;
	int	i;

	if (min >= max)
		return (0);
	len = max - min;
	arr = (int *)malloc(sizeof(int) * len + 1);
	i = 0;
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
