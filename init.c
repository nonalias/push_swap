#include "push_swap.h"

int		init(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;

	if (!validate(argc, argv))
		return (0);
	//a->nums = malloc(sizeof(int) * 10000);
	//b->nums = malloc(sizeof(int) * 10000);
	a->top = 5000;
	a->bottom = 5000 + argc - 1;
	i = 0;
	while (i < argc - 1)
	{
		a->nums[a->top + i] = ft_atoi(argv[i + 1]);
		i++;
	}
	a->size = get_stack_size(*a);
	b->top = 5000;
	b->bottom = 5000;
	b->size = get_stack_size(*b);
	return (1);
}
