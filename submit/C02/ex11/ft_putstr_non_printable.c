/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:05:46 by sajung            #+#    #+#             */
/*   Updated: 2022/05/29 18:58:39 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char ch)
{
	if (ch < 32 || 126 < ch)
		return (0);
	return (1);
}

void	write_hex(char ch)
{
	char	*hex;
	char	div;
	char	mod;

	hex = "0123456789abcdef";
	write(1, "\\", 1);
	div = hex[ch / 16];
	mod = hex[ch % 16];
	write(1, &div, 1);
	write(1, &mod, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_printable(str[i]))
			write(1, &str[i], 1);
		else
			write_hex(str[i]);
		i++;
	}
}
