/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:24:16 by sajung            #+#    #+#             */
/*   Updated: 2022/06/05 00:11:40 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt1(int nb)
{
	long long	sqrt;

	sqrt = 0;
	if (nb < 0)
		return (0);
	while (sqrt * sqrt < (long long)nb)
		sqrt++;
	return (sqrt);
}

int	ft_is_prime1(int nb)
{
	int	i;
	int	sqrt;

	if (nb < 2)
		return (0);
	else if (nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 2;
	sqrt = ft_sqrt1(nb);
	while (i <= sqrt)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime1(nb))
		nb++;
	return (nb);
}
