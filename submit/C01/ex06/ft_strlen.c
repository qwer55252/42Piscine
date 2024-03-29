/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:40:55 by sajung            #+#    #+#             */
/*   Updated: 2022/05/24 23:43:09 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned long	cnt;
	int				i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	cnt = i;
	return (cnt);
}
