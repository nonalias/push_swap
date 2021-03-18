#include "push_swap.h"

void	sort_stack_and_show(t_stack a)
{
	int		size;

	show_stack(a, "before");
	size = get_stack_size(a);
	for (int i = a.top; i < a.bottom; i++)
	{
		for (int j = a.top; j - a.top < a.bottom - i - 1; j++)
		{
			if (a.nums[j] > a.nums[j + 1])
			{
				int temp;
				temp = a.nums[j];
				a.nums[j] = a.nums[j + 1];
				a.nums[j + 1] = temp;
			}
		}
	}
	show_stack(a, "sorted");
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	if (argc <= 1)
		return (1);
	if (!init(&a, &b, argc, argv))
	{
		msg("Error\n");
		return (1);
	}
	//sort_stack_and_show(a);
	//show_stack(a, "A");
	//show_stack(b, "B");
	while (get_next_line(0, &line) > 0)
	{
		//printf("%s\n", line);
		line_exec(&a, &b, line);
		//show_stack(a, "A");
		//show_stack(b, "B");
		free(line);
	}
	//printf("count : %d\n", count);
	show_stack(a, "A");
	show_stack(b, "B");
	for (int i = a.top; i < a.bottom - 1; i++)
	{
		if (a.nums[i] > a.nums[i + 1])
		{
			printf("KO\n");
			return (0);
		}
	}
	printf("OK\n");
}
