/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:52:54 by sajung            #+#    #+#             */
/*   Updated: 2022/05/29 18:42:52 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;
	int	diff;

	diff = 'a' - 'A';
	i = 0;
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] -= diff;
		}
		i++;
	}
	return (str);
}
