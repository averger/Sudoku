#include <unistd.h>

char	**ft_create_sudoku(char **line);
int		ft_print_sudoku(char **grid);
int		ft_check_args(char **args);
void	ft_solver(char **grid, int pos, int *n, char **sol_grid);

int		check(char **sol_grid)
{
	int x;
	int i;
	int n1;
	int n2;

	x = 0;
	i = 0;
	while (x < 9)
	{
		n1 = 0;
		n2 = 0;
		i = 0;
		while (i < 9)
		{
			n1 += sol_grid[x][i] - 48;
			n2 += sol_grid[i][x] - 48;
			i++;
		}
		if (n1 != 45 || n2 != 45)
			return (0);
		x++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		n;
	char	**grid;
	char	**sol_grid;

	n = 0;
	if ((argc != 10) || (ft_check_args(argv) == 0))
		write(2, "Error\n", 6);
	if (argc == 10 && ft_check_args(argv) == 1)
	{
		grid = ft_create_sudoku(argv);
		sol_grid = ft_create_sudoku(argv);
		ft_solver(grid, 0, &n, sol_grid);
		if (n != 1)
			write(2, "Error\n", 6);
		else
		{
			if (check(sol_grid) == 1)
				ft_print_sudoku(sol_grid);
			else
				write(2, "Error\n", 6);
		}
	}
	return (0);
}
