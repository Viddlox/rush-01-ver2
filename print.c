/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:45:22 by jintan            #+#    #+#             */
/*   Updated: 2023/08/14 10:57:36 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	print_board(int board[4][4])
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putchar(board[row][col] + '0');
			if (col == 3)
			{
				col++;
			}
			else
			{
				ft_putchar(' ');
			}
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
