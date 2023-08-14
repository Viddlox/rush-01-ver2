/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheng <micheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:51:16 by micheng           #+#    #+#             */
/*   Updated: 2023/08/14 11:02:19 by micheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

int		empty_board(int *input);
int		solve(int board[4][4], int *input);
void	print_board(int board[4][4]);
void	find4_fill1(int board[4][4], int *input, int pos);
int		check_board(int board[4][4], int *in_num);


#endif