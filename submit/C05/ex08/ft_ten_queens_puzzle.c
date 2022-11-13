/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sajung <sajung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:39:51 by sajung            #+#    #+#             */
/*   Updated: 2022/06/05 00:09:20 by sajung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_board(int board[10])
{
	int		i;
	char	ch;

	i = 0;
	while (i < 10)
	{
		ch = board[i] + '0';
		write(1, &ch, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_risk_next_position(int board[10], int next_row, int next_col)
{
	int	prev_row;
	int	prev_col;

	prev_row = 0;
	prev_col = 0;
	while (prev_row < next_row)
	{
		if (board[prev_row] == next_col)
			return (1);
		prev_col = board[prev_row];
		if (next_row - prev_row == next_col - prev_col)
			return (1);
		if (next_row - prev_row == prev_col - next_col)
			return (1);
		prev_row++;
	}
	return (0);
}

void	arr_duplicate(int *dest, int *src)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		dest[i] = src[i];
		i++;
	}
}

void	ft_recursive(int row, int col, int board[10], int *return_value)
{
	int	tmp[10];
	int	prev_row;
	int	next_col;

	prev_row = 0;
	next_col = 0;
	board[row] = col;
	if (row >= 9)
	{
		*return_value += 1;
		print_board(board);
		return ;
	}
	arr_duplicate(tmp, board);
	while (next_col < 10)
	{
		if (!is_risk_next_position(tmp, row + 1, next_col))
			ft_recursive(row + 1, next_col, tmp, return_value);
		next_col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	return_value;
	int	board[10];
	int	col;
	int	i;

	return_value = 0;
	col = 0;
	i = 0;
	while (i < 10)
		board[i++] = -1;
	while (col < 10)
	{
		ft_recursive(0, col, board, &return_value);
		col++;
	}
	return (return_value);
}
