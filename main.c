/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:41:02 by jintan            #+#    #+#             */
/*   Updated: 2023/08/14 11:01:20 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_syntax(char *input)
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

int	check_input(char *arg, int *input)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	if (check_syntax(arg) == 1)
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
