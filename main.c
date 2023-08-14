#include "rush01.h"

//checks the amount of 4s and 1s, making sure 4s cannot exceed 2 and 1s cannot exceed 4 in a 4 x 4 grid.

int	check_rules(char *input)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (input[i])
	{
		if (input[i] == '4')
			error++;
		i++;
	}
	if (error > 2)
		return (0);
	i = 0;
	error = 0;
	while (input[i])
	{
		if (input[i] == '1')
			error++;
		i++;
	}
	if (error != 4)
		return (0);
	return (1);
}

//checks if the clue value is between 1 and 4,  if there are spaces between each value.
//And that if the next value is NULL and the previous value is a space (last value).
//If true, will convert char to int and pass it into an integer array *input.

int	check_input(char *arg, int *input)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	if (check_rules(arg) == 1)
	{
		while (arg[i])
		{
			if ((arg[i] >= '1' && arg[i] <= '4') && ((arg[i + 1] == ' ')
					|| ((arg[i + 1] == NULL) && (arg[i - 1] == ' '))))
			{
				input[out] = (arg[i] - '0');
				out++;
				i++;
			}
			if ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == ' ')
				i++;
			else
				return (out);
		}
		input[out] = '\0';
		return (out);
	}
	return (0);
}

//main function parses clue edges into single array

int	main(int ac, char **av)
{
	int	input[16];

	if (ac == 2)
	{
		if (check_input(av[1], input) == 16)
			empty_board(input);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
