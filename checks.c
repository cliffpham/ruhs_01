/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpham <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:39:28 by cpham             #+#    #+#             */
/*   Updated: 2019/04/07 21:27:23 by jbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define EM 0
#define N 9

int		check_horizontal(int grid[N][N], int row, int num)
{
	int col;

	col = 0;
	while (col < N)
	{
		if (grid[row][col] == num)
			return (0);
		col++;
	}
	return (1);
}

int		check_vertical(int grid[N][N], int col, int num)
{
	int row;

	row = 0;
	while (row < N)
	{
		if (grid[row][col] == num)
			return (0);
		row++;
	}
	return (1);
}

int		check_square(int grid[N][N], int start_row, int start_col, int num)
{
	int row;
	int col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			if (grid[row + start_row][col + start_col] == num)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int		can_place(int grid[N][N], int row, int col, int num)
{
	int horizontal;
	int vertical;
	int square;

	horizontal = check_horizontal(grid, row, num);
	vertical = check_vertical(grid, col, num);
	square = check_square(grid, row - row % 3, col - col % 3, num);
	if (horizontal == 1 && vertical == 1 && square == 1 && grid[row][col] == 0)
		return (1);
	return (0);
}
