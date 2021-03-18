#include "../includes/push_swap.h"

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
	while (get_next_line(0, &line) > 0)
	{
		line_exec(&a, &b, line);
		free(line);
	}
	show_stack(a, "A");
	show_stack(b, "B");
	if (check_asc(a))
		msg("OK");
	else
		msg("KO");
}
