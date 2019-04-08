/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpham <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:20:33 by cpham             #+#    #+#             */
/*   Updated: 2019/04/07 21:27:07 by jbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define N 9
#define EM 0

int		can_place(int grid[N][N], int row, int col, int num);

int		find_col(int grid[N][N], int row)
{
	int i;
	int j;

	i = row;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (grid[i][j] == EM)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int		search_cells(int grid[N][N])
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (grid[i][j] == EM)
				return (i);
			j++;
		}
		i++;
	}
	return (9);
}

int		solve(int grid[N][N])
{
	int row;
	int col;
	int num;
	int place;
	int recur;

	row = search_cells(grid);
	col = find_col(grid, row);
	num = 1;
	if (row == 9)
		return (1);
	while (num <= 9)
	{
		place = can_place(grid, row, col, num);
		if (place == 1)
		{
			grid[row][col] = num;
			recur = solve(grid);
			if (recur == 1)
				return (1);
			grid[row][col] = EM;
		}
		num++;
	}
	return (0);
}
