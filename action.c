#include "push_swap.h"

void	ft_swap(t_stack *st)
{
	int		temp;

	if (st->size <= 1)
		return;
	temp = st->nums[st->top];
	st->nums[st->top] = st->nums[st->top + 1];
	st->nums[st->top + 1] = temp;
}

void	ft_push(t_stack *source, t_stack *target)
{
	if (source->size == 0)
		return ;
	target->nums[--target->top] = source->nums[source->top++];
	source->size = get_stack_size(*source);
	target->size = get_stack_size(*target);
}

void	ft_reverse(t_stack *st)
{
	if (st->size <= 1)
		return ;
	st->nums[st->bottom] = st->nums[st->top];
	st->top++;
	st->bottom++;
}

void	ft_r_reverse(t_stack *st)
{
	if (st->size <= 1)
		return ;
	st->nums[st->top - 1] = st->nums[st->bottom - 1];
	st->top--;
	st->bottom--;
}
