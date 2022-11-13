/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:03:00 by sajung            #+#    #+#             */
/*   Updated: 2022/06/04 23:14:47 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	sqrt;

	sqrt = 0;
	if (nb <= 0)
		return (0);
	while (sqrt * sqrt < (long long)nb)
		sqrt++;
	if (sqrt * sqrt == (long long)nb)
		return (sqrt);
	return (0);
}
