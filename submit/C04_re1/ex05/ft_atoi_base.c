/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 01:11:43 by sajung            #+#    #+#             */
/*   Updated: 2022/06/02 01:20:32 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	find_idx(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (ch == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	is_valid(char *base)
{
	int	i;
	int	j;

	if (str_len(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((9 <= base[i] && base[i] <= 13) || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	long long	result;
	int			base_len;
	int			idx;
	int			sign;

	if (!is_valid(base))
		return (0);
	base_len = str_len(base);
	result = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && find_idx(*str, base) != -1)
	{
		idx = find_idx(*str, base);
		result = result * base_len + idx;
		str++;
	}
	return ((int)(result * sign));
}
