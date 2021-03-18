#include "../includes/push_swap.h"

int		get_stack_size(t_stack stack)
{
	return stack.bottom - stack.top;
}

int		get_stack_nbr_len(t_stack st)
{
	int count = 0;

	for (int i = st.top; i < st.bottom; i++)
	{
		count += ft_intlen(st.nums[i]);
		count += 1;
	}
	return (count);
}

void	show_stack(t_stack a, const char *what)
{
	int		count;
	int		i;

	count = get_stack_nbr_len(a);
	i = -1;
	while (++i < 16 + count)
		msg("-");
	msg("\n");
	msg(what);
	msg(" stack   top   ");
	i = a.top;
	while (i < a.bottom)
	{
		msg(ft_itoa(a.nums[i]));
		msg(" ");
		i++;
	}
	msg("|bottom\n");
	i = -1;
	while (++i < 16 + count)
		msg("-");
	msg("\n");
}

