#include "../includes/push_swap.h"

void	msg(const char *str)
{
	ft_putstr_fd(str, 1);
}

void	msg_act_one(char *func_name, void (*act)(t_stack *), t_stack *a)
{
	act(a);
	msg(func_name);
	msg("\n");
}

void	msg_act_two(char *func_name, void (*act)(t_stack *, t_stack *),
		t_stack *a, t_stack *b)
{
	act(a, b);
	msg(func_name);
	msg("\n");
}
