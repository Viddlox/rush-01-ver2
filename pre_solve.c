#include "rush01.h"

//finds 4 clue edges and checks it against the position within the 2d grid. 
//Places a 1 next to every 4 found (2 max).

void	find4_fill1(int board[4][4], int *input, int pos)
{
	int	fill;

	fill = 0;
	while ((input[pos]) && pos <= 15)
	{
		if ((input[pos] == 4) && ((pos >= 8 && pos <= 11)))
		{
			while (fill < 4)
			{
				board[pos % 4][fill] = fill + 1;
				fill++;
			}
		}
		fill = 4;
		if ((input[pos] == 4) && ((pos >= 12 && pos <= 15)))
		{
			while (fill > 0)
			{
				board[pos % 4][4 - fill] = fill;
				fill--;
			}
		}
		pos++;
	}
}

//After filling 4s, we find the position of 4s in the map and fill the
// zero spaces) with ascending numbers (fill). 
//checking against the clue arr each time
//does this for the first half then second half for the last 4.

void	find4_fill0(int board[4][4], int *input)
{
	int	pos;
	int	fill;

	pos = 0;
	fill = 0;
	while ((input[pos]) && pos < 8)
	{
		if ((input[pos] == 4) && ((pos >= 0 && pos <= 3)))
		{
			while (fill < 4)
			{
				board[fill][pos] = fill + 1;
				fill++;
			}
		}
		fill = 5;
		if ((input[pos] == 4) && ((pos >= 4 && pos <= 7)))
		{
			while (--fill > 0)
				board[4 - fill][(pos % 4)] = fill;
		}
		pos++;
	}
	find4_fill1(board, input, pos);
}

//Iterates through the 2d grid and checks the position of 1 clues at different ranges in the array.
//Fills a 4 next to every adjacent 1 (4 max)

void	find1_fill4(int board[4][4], int *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if ((input[i] == 1) && ((i >= 0) && (i <= 3)))
		{
			board[0][i] = 4;
		}
		if ((input[i] == 1) && ((i >= 4) && (i <= 7)))
		{
			board[3][i - 4] = 4;
		}
		if ((input[i] == 1) && ((i >= 8) && (i <= 11)))
		{
			board[i - 8][0] = 4;
		}
		if ((input[i] == 1) && ((i >= 12) && (i <= 15)))
		{
			board[i - 12][3] = 4;
		}
		i++;
	}
	find4_fill0(board, input);
}

//zeroes out the whole 4 x 4 2d grid. Then starts filling the "pre-solvable" values.

int	empty_board(int *input)
{
	int		row;
	int		col;
	int		board[4][4];

	row = 0;
	col = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
	find1_fill4(board, input);
	if ((solve(board, input)) == 1)
		print_board(board);
	else
		write(1, "Error\n", 6);
	return (0);
}
