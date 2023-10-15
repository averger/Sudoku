#include <stdlib.h>

char	**ft_create_sudoku(char **line)
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	grid = (char**)malloc(sizeof(char *) * 9);
	while (i < 9)
	{
		grid[i] = (char *)malloc(sizeof(char) * 9);
		j = 0;
		while (j < 9)
		{
			grid[i][j] = line[i + 1][j];
			j += 1;
		}
		i += 1;
	}
	return (grid);
}
