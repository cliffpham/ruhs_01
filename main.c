/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpham <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:22:33 by cpham             #+#    #+#             */
/*   Updated: 2019/04/07 22:55:05 by jbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define N 9

int		solve(int grid[N][N]);
void	ft_putnbr(int nb);
void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_matrix(int s[9][9])
{
	int c;
	int r;
	int cur;

	r = 0;
	while (r < 9)
	{
		c = 0;
		while (c < 9)
		{
			cur = s[r][c];
			ft_putnbr(cur);
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}

int		check_input(char **argv)
{
	int i;
	int j;

	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.' || (argv[i][j] >= '0' && argv[i][j] <= '9'))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int		**allocate_mem_matrix(char **str)
{
	int	**str2;
	int	i;
	int	nro_rows;

	i = 0;
	nro_rows = 0;
	str2 = (int**)malloc(sizeof(*str2) * 9);
	while (nro_rows < 9)
	{
		str2[nro_rows] = (int*)malloc(sizeof(int) * 9);
		while (i < 9)
		{
			if (str[nro_rows + 1][i] == '.')
				str2[nro_rows][i] = 0;
			else
				str2[nro_rows][i] = str[nro_rows + 1][i] - '0';
			i++;
		}
		i = 0;
		nro_rows++;
	}
	return (str2);
}

int		main(int argc, char **argv)
{
	int **m;
	int ma[9][9];
	int i;
	int j;

	i = -1;
	if (argc != 10 || check_input(argv) != 1)
		ft_putstr("error\n");
	else
	{
		m = allocate_mem_matrix(argv);
		while (++i < 9)
		{
			j = -1;
			while (++j < 9)
				ma[i][j] = m[i][j];
		}
		if (solve(ma) == 1)
			print_matrix(ma);
		else
			ft_putstr("error\n");
	}
	return (0);
}
