#include "push_swap.h"


int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	if (!init(&a, &b, argc, argv))
	{
		msg("Error\n");
		return (1);
	}
	//show_stack(a, "A");
	//show_stack(b, "B");
	while (get_next_line(0, &line) > 0)
	{
		printf("%s\n", line);
		line_exec(&a, &b, line);
		//show_stack(a, "A");
		//show_stack(b, "B");
		free(line);
	}
	//printf("count : %d\n", count);
	//show_stack(a, "A");
	//show_stack(b, "B");
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
