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
