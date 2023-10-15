char	**ft_create_sudoku(char **args);
int		ft_print_sudoku(char **grid);

int		ft_little_square(char **grid, int x, int y, char value)
{
	int xmax;
	int ymax;

	x = x / 3 * 3;
	y = y / 3 * 3;
	xmax = x + 2;
	ymax = y + 2;
	while (x <= xmax)
	{
		y = ymax - 2;
		while (y <= ymax)
		{
			if (grid[x][y] == value)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int		ft_free_space(char **grid, int x, int y, char value)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[x][i] == value || grid[i][y] == value)
			return (0);
		i++;
	}
	return (ft_little_square(grid, x, y, value));
}

void	ft_cpy(char **grid, char **sol_grid, int *n)
{
	int i;

	i = -1;
	while (++i < 81)
		sol_grid[i / 9][i % 9] = grid[i / 9][i % 9];
	*n += 1;
}

void	ft_solver(char **grid, int pos, int *n, char **sol_grid)
{
	char	value;

	if (grid[pos / 9][pos % 9] > '.' && *n < 2)
	{
		if (pos < 80)
			ft_solver(grid, pos + 1, n, sol_grid);
		else
			ft_cpy(grid, sol_grid, n);
		return ;
	}
	value = '1';
	while (value <= '9' && *n < 2)
	{
		if (ft_free_space(grid, pos / 9, pos % 9, value))
		{
			grid[pos / 9][pos % 9] = value;
			if (pos < 80)
				ft_solver(grid, pos + 1, n, sol_grid);
			else
				ft_cpy(grid, sol_grid, n);
			grid[pos / 9][pos % 9] = '.';
		}
		value++;
	}
}
