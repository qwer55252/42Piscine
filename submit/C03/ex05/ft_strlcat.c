/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:39:10 by sajung            #+#    #+#             */
/*   Updated: 2022/06/02 00:42:21 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				i;
	int				j;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = str_len(dest);
	src_len = str_len(src);
	i = 0;
	j = 0;
	if (size <= str_len(dest))
		return (src_len + size);
	while (dest[i])
		i++;
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
