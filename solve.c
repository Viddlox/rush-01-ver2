#include "rush01.h"

int	look_0(int board[4][4], int *r, int *c)
{
	*r = 0;
	*c = 0;
	while (*r < 4)
	{
		*c = 0;
		while (*c < 4)
		{
			if (board[*r][*c] == 0)
			{
				return (1);
			}
			*c += 1;
		}
		*r += 1;
	}
	return (0);
}

int	check_col(int board[4][4], int col, int num)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (board[row][col] == num)
		{
			return (0);
		}
		row++;
	}
	return (1);
}

int	check_row(int board[4][4], int row, int num)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (board[row][col] == num)
		{
			return (0);
		}
		col++;
	}
	return (1);
}

int	check_dupe(int board[4][4], int r, int c, int num)
{
	if (((check_row(board, r, num)) && (check_col(board, c, num))
			&& (board[r][c] == 0)))
	{
		return (1);
	}
	return (0);
}

int	solve(int board[4][4], int *input)
{
	int	row;
	int	col;
	int	tower_h;

	tower_h = 1;
	if ((look_0(board, &row, &col) == 0) && (check_board(board, input) == 1))
	{
		return (1);
	}
	while (tower_h <= 4)
	{
		if (check_dupe(board, row, col, tower_h))
		{
			board[row][col] = tower_h;
			if (solve(board, input) == 1)
			{
				return (1);
			}
			board[row][col] = 0;
		}
		tower_h++;
	}
	return (0);
}
