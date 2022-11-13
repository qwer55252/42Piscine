/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyun <cyun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:44:21 by cyun              #+#    #+#             */
/*   Updated: 2022/06/06 10:11:30 by cyun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "string_func.h"

int	main(int argc, char *argv[])
{
	int	idx;

	if (argc == 1)
		bsq(0);
	else
	{
		idx = 0;
		while (++idx < argc)
		{
			bsq(argv[idx]);
			if (idx != argc - 1)
				ft_putchar('\n');
		}
	}
	return (0);
}
