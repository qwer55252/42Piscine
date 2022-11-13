/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:57:20 by sajung            #+#    #+#             */
/*   Updated: 2022/05/26 22:30:13 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_upper(char ch)
{
	if ('A' <= ch && ch <= 'Z')
	{
		return (1);
	}
	return (0);
}

int	is_lower(char ch)
{
	if ('a' <= ch && ch <= 'z')
	{
		return (1);
	}
	return (0);
}

int	is_capitalize(char *str, int i)
{
	if (i == 0)
		return (1);
	if ('a' <= str[i - 1] && str[i - 1] <= 'z')
		return (0);
	else if ('A' <= str[i - 1] && str[i - 1] <= 'Z')
		return (0);
	else if ('0' <= str[i - 1] && str[i - 1] <= '9')
		return (0);
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	diff;

	diff = 'a' - 'A';
	i = 0;
	while (str[i])
	{
		if (is_capitalize(str, i))
		{
			if (is_lower(str[i]))
				str[i] -= diff;
		}
		else if (is_upper(str[i]))
			str[i] += diff;
		i++;
	}
	return (str);
}
