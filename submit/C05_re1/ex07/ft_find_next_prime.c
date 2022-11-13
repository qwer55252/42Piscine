/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:24:16 by sajung            #+#    #+#             */
/*   Updated: 2022/06/05 18:26:25 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime1(int nb)
{
	long long	i;

	if (nb <= 1)
		return (0);
	else
	{
		i = 2;
		while (i * i <= nb)
		{
			if (nb % i == 0)
				return (0);
			i++;
		}
		return (1);
	}
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime1(nb))
		nb++;
	return (nb);
}
