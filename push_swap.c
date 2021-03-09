#include "push_swap.h"

void	msg_act_one(char *func_name, void (*act)(t_stack *), t_stack *a)
{
	act(a);
	msg(func_name);
	msg("\n");
}

void	msg_act_two(char *func_name, void (*act)(t_stack *, t_stack *), t_stack *a, t_stack *b)
{
	act(a, b);
	msg(func_name);
	msg("\n");
}

void	three_element_asc_sort(t_stack *st)
{
	int		size;

	size = get_stack_size(*st);
	if (size == 3)
	{
		// 1 2 3
		if (st->nums[st->top] < st->nums[st->top + 1] &&
				st->nums[st->top + 1] < st->nums[st->top + 2])
		{
			// nothing to do
		}
		// 1 3 2
		else if (st->nums[st->top] < st->nums[st->top + 1] &&
				st->nums[st->top + 1] > st->nums[st->top + 2] &&
				st->nums[st->top] < st->nums[st->top + 2])
		{
			msg_act_one("rra", ft_r_reverse, st);
			msg_act_one("sa", ft_swap, st);
		}
		// 2 3 1
		else if (st->nums[st->top] < st->nums[st->top + 1] &&
				st->nums[st->top + 1] > st->nums[st->top + 2] &&
				st->nums[st->top] > st->nums[st->top + 2])
		{
			msg_act_one("rra", ft_r_reverse, (st));
		}
		//3 2 1
		else if (st->nums[st->top] > st->nums[st->top + 1] &&
				st->nums[st->top + 1] > st->nums[st->top + 2])
		{
			msg_act_one("sa", ft_swap, (st));
			msg_act_one("rra", ft_r_reverse, (st));
		}
		// 2 1 3
		else if (st->nums[st->top] > st->nums[st->top + 1] &&
				st->nums[st->top + 1] < st->nums[st->top + 2] &&
				st->nums[st->top] < st->nums[st->top + 2])
		{
			msg_act_one("sa", ft_swap, (st));
		}
		//3 1 2
		else if (st->nums[st->top] > st->nums[st->top + 1] &&
				st->nums[st->top + 1] < st->nums[st->top + 2] &&
				st->nums[st->top] > st->nums[st->top + 2])
		{
			msg_act_one("ra", ft_reverse, (st));
		}
	}
	else if (size == 2)
	{
		if (st->nums[st->top] > st->nums[st->top + 1])
		{
			msg_act_one("sa", ft_swap, (st));
		}
	}

}

void	three_element_desc_sort(t_stack *st)
{
	int		size;

	size = get_stack_size(*st);
	if (size == 3)
	{
		// 1 2 3
		if (st->nums[st->top] < st->nums[st->top + 1] &&
				st->nums[st->top + 1] < st->nums[st->top + 2])
		{
			msg_act_one("sb", ft_swap, (st));
			msg_act_one("rrb", ft_r_reverse, (st));
		}
		// 1 3 2
		else if (st->nums[st->top] < st->nums[st->top + 1] &&
				st->nums[st->top + 1] > st->nums[st->top + 2] &&
				st->nums[st->top] < st->nums[st->top + 2])
		{
			msg_act_one("rb", ft_reverse, (st));
		}
		// 2 3 1
		else if (st->nums[st->top] < st->nums[st->top + 1] &&
				st->nums[st->top + 1] > st->nums[st->top + 2] &&
				st->nums[st->top] > st->nums[st->top + 2])
		{
			msg_act_one("sb", ft_swap, (st));
		}
		//3 2 1
		else if (st->nums[st->top] > st->nums[st->top + 1] &&
				st->nums[st->top + 1] > st->nums[st->top + 2])
		{
			//nothing
		}
		// 2 1 3
		else if (st->nums[st->top] > st->nums[st->top + 1] &&
				st->nums[st->top + 1] < st->nums[st->top + 2] &&
				st->nums[st->top] < st->nums[st->top + 2])
		{
			msg_act_one("rrb", ft_r_reverse, (st));
		}
		//3 1 2
		else if (st->nums[st->top] > st->nums[st->top + 1] &&
				st->nums[st->top + 1] < st->nums[st->top + 2] &&
				st->nums[st->top] > st->nums[st->top + 2])
		{
			msg_act_one("rrb", ft_r_reverse, (st));
			msg_act_one("sb", ft_swap, st);
		}
	}
	else if (size == 2)
	{
		if (st->nums[st->top] < st->nums[st->top + 1])
		{
			msg_act_one("sb", ft_swap, (st));
		}
	}
}

void	over_three_element_desc_sort(t_stack *st)
{
	// first two element is always over than last elements
	// 3 2 1
	// 2 3 1  two case can exist

	// 3 2 1 -> nothing to do
	//
	// 2 3 1 - > only calls ft_swap
	if (st->nums[st->top] < st->nums[st->top + 1])
		msg_act_one("sb", ft_swap, (st));
}

int		get_min_index(t_stack st, long at_least)
{
	long	min = 2500000000;
	int		min_index;
	int		i;

	i = st.top;
	while (i < st.bottom)
	{
		if (st.nums[i] < min && st.nums[i] > at_least)
		{
			min = st.nums[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int		check_asc(t_stack st)
{
	int		i;

	i = st.top;
	while (i < st.bottom - 1)
	{
		if (st.nums[i] > st.nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		get_dist_to_top(t_stack st, int index)
{
	int		dist;

	dist = index - st.top;
	if (st.bottom - index < dist)
		dist = st.bottom - index;
	return (dist);
}

void 	sort_indexes(int indexs[][2])
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 2 - i)
		{
			//printf("hello world\n");
			if (indexs[j][1] > indexs[j + 1][1])
			{
				temp = indexs[j][1];
				indexs[j][1] = indexs[j + 1][1];
				indexs[j + 1][1] = temp;
				temp = indexs[j][0];
				indexs[j][0] = indexs[j + 1][0];
				indexs[j + 1][0] = temp;
			}
			j++;
		}
		i++;
	}
}

void	move_to_the_top(t_stack *a, int index)
{
	//printf("%d %d\n", a->top, index);
	if (index - a->top < a->bottom - index)
	{
		while (index != a->top)
		{
			//printf("%d\n", a->top);
			msg_act_one("ra", ft_reverse, (a));
		}
	}
	else
	{
		while (index != a->bottom)
		{
			msg_act_one("rra", ft_r_reverse, (a));
		}
	}
}

void	pa_all(t_stack *a, t_stack *b)
{
	while (get_stack_size(*b))
		msg_act_two("pa", ft_push, b, a);
}

void	get_commands(t_stack *a, t_stack *b)
{
	int		i;

	while (get_stack_size(*a) >= 4)
	{
		if (get_stack_size(*b) == 0)
		{
			i = 0;
			while (i < 3)
			{
				/*
				show_stack(*a, "A");

				show_stack(*b, "B");
				*/
				int indexs[3][2];
				indexs[0][0] = get_min_index(*a, -3000000000);
				indexs[0][1] = get_dist_to_top(*a, indexs[0][0]);
				if (i < 2)
				{
					indexs[1][0] = get_min_index(*a, a->nums[indexs[0][0]]);
					indexs[1][1] = get_dist_to_top(*a, indexs[1][0]);
				}
				else
					indexs[1][1] = 987654321;
				if (i < 1)
				{
					indexs[2][0] = get_min_index(*a, a->nums[indexs[1][0]]);
					indexs[2][1] = get_dist_to_top(*a, indexs[2][0]);
				}
				else
				{
					indexs[2][1] = 987654321;
				}
				//printf("indexes : (%d,%d) (%d,%d) (%d,%d)\n", indexs[0][0], indexs[0][1], indexs[1][0], indexs[1][1], indexs[2][0], indexs[2][1]);
				sort_indexes(indexs);
				//printf("indexes : (%d,%d) (%d,%d) (%d,%d)\n", indexs[0][0], indexs[0][1], indexs[1][0], indexs[1][1], indexs[2][0], indexs[2][1]);
				move_to_the_top(a, indexs[0][0]);
				msg_act_two("pb", ft_push, a, b);
				i++;
			}
			/*
			i = 0;
			while (i < 3)
			{
				int j = i + 1;
				move_to_the_top(a, indexs[i][0]);
				ft_push(a, b);
				show_stack(*a, "A");
				show_stack(*b, "B");
				i++;
			}
			*/
			three_element_desc_sort(b);
		}
		else
		{
			int indexs[3][2];
			indexs[0][0] = get_min_index(*a, -3000000000);
			indexs[1][0] = get_min_index(*a, a->nums[indexs[0][0]]);
			indexs[2][0] = 987654321;
			indexs[0][1] = get_dist_to_top(*a, indexs[0][0]);
			indexs[1][1] = get_dist_to_top(*a, indexs[1][0]);
			indexs[2][1] = 987654321;
			//printf("indexes : (%d,%d) (%d,%d) (%d,%d)\n", indexs[0][0], indexs[0][1], indexs[1][0], indexs[1][1], indexs[2][0], indexs[2][1]);
			sort_indexes(indexs);
			//printf("indexes : (%d,%d) (%d,%d) (%d,%d)\n", indexs[0][0], indexs[0][1], indexs[1][0], indexs[1][1], indexs[2][0], indexs[2][1]);
			i = 0;
			while (i < 2)
			{
				int j = i + 1;
				move_to_the_top(a, indexs[i][0]);
				msg_act_two("pb", ft_push, a, b);
				//show_stack(*a, "A");
				//show_stack(*b, "B");
				i++;
			}
			over_three_element_desc_sort(b);
		}
	}
	three_element_asc_sort(a);
	pa_all(a, b);
}

int		main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	if (!init(&a, &b, argc, argv))
	{
		msg("Error\n");
		return (1);
	}
	//get_commands(&a, &b);
	//show_stack(a, "A");
	//show_stack(b, "B");
	//three_element_asc_sort(&a);
	get_commands(&a, &b);
	//over_three_element_desc_sort(&a);
	//show_stack(a, "A");
	//show_stack(b, "B");
}
