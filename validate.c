#include "push_swap.h"

int		validate(int argc, char **argv)
{
	int		i;
	int		j;
	int		size;

	if (argc <= 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		size = ft_strlen(argv[i]);
		while (j < size)
		{
			if ((j >= 1) && !ft_isdigit(argv[i][j]))
				return (0);
			if (j == 0 && !ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
