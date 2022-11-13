/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:31:46 by sajung            #+#    #+#             */
/*   Updated: 2022/06/02 01:22:45 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strncmp1(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				result;

	i = 0;
	while (*s1 != '\0' && *s2 != '\0' && i < n)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		i++;
	}
	if (n == i)
		return (0);
	return (*s1 - *s2);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (ft_strlen(to_find) == 0)
		return (str);
	while (*str)
	{
		if (!ft_strncmp1(str, to_find, ft_strlen(to_find)))
			return (str);
		str++;
	}
	return (0);
}
