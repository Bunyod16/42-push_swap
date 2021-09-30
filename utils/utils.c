#include "../push_swap.h"

int	ft_isnum(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	sorted(char **argv)
{
	int	i;
	int	min;

	if (argv[1] && ft_isnum(argv[1]))
		min = ft_atoi(argv[1]);
	i = 0;
	while (argv[++i])
	{
		if (ft_isnum(argv[i]))
		{
			if (ft_atoi(argv[i]) >= min)
				min = ft_atoi(argv[i]);
			else
				return 0;
		}
		else
			exit(0);
	}
	return (1);
}