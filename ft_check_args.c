int		ft_check_complete_grid(char **args)
{
	int i;
	int j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (args[i][j] == '.')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_args(char **args)
{
	int i;
	int j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if ((args[i][j] != '.') && !(args[i][j] >= 49 && args[i][j] <= 57))
				return (0);
			j++;
			if (j == 9 && args[i][j] != '\0')
				return (0);
		}
		i++;
	}
	return (ft_check_complete_grid(args));
}
