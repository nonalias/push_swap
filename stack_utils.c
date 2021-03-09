#include "push_swap.h"

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

// banned function! remove before submit this subject.
void	show_stack(t_stack a, const char *what)
{
	int		count;

	count = get_stack_nbr_len(a);
	for (int i = 0; i < 16 + count; i++)
	{
		ft_putstr_fd("-", 1);
	}
	ft_putstr_fd("\n", 1);
	//printf("---------------------------------------------\n");
	printf("%s stack   top   ", what);
	for (int j = a.top; j < a.bottom; j++)
		printf("%d ", a.nums[j]);
	printf("|bottom\n");
	for (int i = 0; i < 16 + count; i++)
	{
		ft_putstr_fd("-", 1);
	}
	ft_putstr_fd("\n", 1);
	//printf("---------------------------------------------\n");
}

