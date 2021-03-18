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

int		get_min_index(t_stack st)
{
	long	min = 2500000000;
	int		min_index;
	int		i;

	i = st.top;
	while (i < st.bottom)
	{
		if (st.nums[i] < min)
		{
			min = st.nums[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int		get_max_index(t_stack st)
{
	long	max = -2500000000;
	int		max_index;
	int		i;

	i = st.top;
	while (i < st.bottom)
	{
		if (st.nums[i] > max)
		{
			max = st.nums[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

int		get_dist_to_top(t_stack st, int index)
{
	int		dist;

	dist = index - st.top;
	if (st.bottom - index < dist)
		dist = st.bottom - index;
	return (dist);
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

void	move_to_the_top(t_stack *st, int index, int flag)
{
	if (index - st->top < st->bottom - index)
	{
		while (index != st->top)
		{
			if (flag == 0)
				msg_act_one("ra", ft_reverse, (st));
			else if (flag == 1)
				msg_act_one("rb", ft_reverse, (st));
		}
	}
	else
	{
		while (index != st->bottom)
		{
			if (flag == 0)
				msg_act_one("rra", ft_r_reverse, (st));
			else if (flag == 1)
				msg_act_one("rrb", ft_r_reverse, (st));
		}
	}
}

void	pa_all(t_stack *a, t_stack *b)
{
	while (get_stack_size(*b))
		msg_act_two("pa", ft_push, b, a);
}

int		find_medium(t_stack st, int chunk_size, int repeat)
{
	int		i;
	int		j;
	int		size;
	int		temp;

	size = get_stack_size(st);
	i = st.top;
	while (i < st.bottom)
	{
		j = st.top;
		while (j < st.bottom - 1)
		{
			if (st.nums[j] > st.nums[j + 1])
			{
				temp = st.nums[j];
				st.nums[j] = st.nums[j + 1];
				st.nums[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (st.nums[st.top + (chunk_size * repeat - 1)]);
}

void	get_3_commands(t_stack *a, t_stack *b)
{
	if (a->nums[a->top] > a->nums[a->top + 1] &&
			a->nums[a->top + 1] > a->nums[a->top + 2])
	{
		msg_act_one("sa", ft_swap, a);
		msg_act_one("rra", ft_r_reverse, a);
	}
	else if (a->nums[a->top] > a->nums[a->top + 1] &&
			a->nums[a->top + 1] < a->nums[a->top + 2] &&
			a->nums[a->top] < a->nums[a->top + 2])
		msg_act_one("sa", ft_swap, a);
	else if (a->nums[a->top] > a->nums[a->top + 1] &&
			a->nums[a->top + 1] < a->nums[a->top + 2] &&
			a->nums[a->top] > a->nums[a->top + 2])
		msg_act_one("ra", ft_reverse, a);
	else if (a->nums[a->top] < a->nums[a->top + 1] &&
			a->nums[a->top + 1] > a->nums[a->top + 2] &&
			a->nums[a->top] < a->nums[a->top + 2])
	{
		msg_act_one("sa", ft_swap, a);
		msg_act_one("ra", ft_reverse, a);
	}
	else if (a->nums[a->top] < a->nums[a->top + 1] &&
			a->nums[a->top + 1] > a->nums[a->top + 2] &&
			a->nums[a->top] > a->nums[a->top + 2])
		msg_act_one("rra", ft_r_reverse, a);
}

void	get_under_5_commands(t_stack *a, t_stack *b)
{
	int		min_index;
	int		max_index;
	int		min_index_dist;
	int		max_index_dist;

	while (get_stack_size(*a) > 3)
	{
		min_index = get_min_index(*a);
		max_index = get_max_index(*a);
		min_index_dist = get_dist_to_top(*a, min_index);
		max_index_dist = get_dist_to_top(*a, max_index);
		if (min_index_dist < max_index_dist)
			move_to_the_top(a, min_index, 0);
		else
			move_to_the_top(a, max_index, 0);
		msg_act_two("pb", ft_push, a, b);
	}
	get_3_commands(a, b);
	while (get_stack_size(*b))
	{
		msg_act_two("pa", ft_push, b, a);
		if (a->nums[a->top] > a->nums[a->top + 1])
			msg_act_one("ra", ft_reverse, a);
	}
}

void	get_commands(t_stack *a, t_stack *b)
{
	int		i;
	int		k;
	int		size;
	int		medium;
	int		before = -987654321;

	// medium -> 25 50 75 100 이 순차적으로 나와야 함.
	size = get_stack_size(*a);
	if (size == 5 || size == 4)
		get_under_5_commands(a, b);
	else if (size == 3)
		get_3_commands(a, b);
	else
	{
	k = 0;
	while (k < size / a->chunk_size)
	{
		medium = find_medium(*a, a->chunk_size, k + 1);
		i = 0;
		while (i < size)
		{
			if (a->nums[a->top] <= medium && a->nums[a->top] > before)
				msg_act_two("pb", ft_push, a, b);
			else
				msg_act_one("ra", ft_reverse, a);
			i++;
		}
		while (get_stack_size(*b))
		{
			int min_index = get_min_index(*b);
			int max_index = get_max_index(*b);
			int	min_index_dist = get_dist_to_top(*b, min_index);
			int	max_index_dist = get_dist_to_top(*b, max_index);

			//min_index_dist < max_index_dist ? move_to_top(b, min_index) : move_to_top(b, max_index);
			if (min_index_dist < max_index_dist)
			{
				move_to_the_top(b, min_index, 1);
				msg_act_two("pa", ft_push, b, a);
				msg_act_one("ra", ft_reverse, a);
			}
			else
			{
				move_to_the_top(b, max_index, 1);
				msg_act_two("pa", ft_push, b, a);
			}

		}
		while (a->nums[a->top] <= medium && a->nums[a->top] > before)
			msg_act_one("ra", ft_reverse, a);
		before = medium;
		k++;
	}
	while (a->nums[a->top] > medium)
		msg_act_two("pb", ft_push, a, b);
	while (get_stack_size(*b))
	{
		int min_index = get_min_index(*b);
		int max_index = get_max_index(*b);
		int	min_index_dist = get_dist_to_top(*b, min_index);
		int	max_index_dist = get_dist_to_top(*b, max_index);

		//min_index_dist < max_index_dist ? move_to_top(b, min_index) : move_to_top(b, max_index);
		if (min_index_dist < max_index_dist)
		{
			move_to_the_top(b, min_index, 1);
			msg_act_two("pa", ft_push, b, a);
			msg_act_one("ra", ft_reverse, a);
		}
		else
		{
			move_to_the_top(b, max_index, 1);
			msg_act_two("pa", ft_push, b, a);
		}

	}

	while (a->nums[a->top] > medium)
		msg_act_one("ra", ft_reverse, a);

	//show_stack(*a, "A");
	//show_stack(*b, "B");
	}
}

int		main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	if (argc <= 1)
		return (1);
	if (!init(&a, &b, argc, argv))
	{
		msg("Error\n");
		return (1);
	}
	if (check_asc(a))
		return (0);
	//printf("hello world");
	//get_commands(&a, &b);
	//three_element_asc_sort(&a);
	get_commands(&a, &b);
	//printf("%d\n", a.top);
	//show_stack(a, "A");
	//show_stack(b, "B");
	//over_three_element_desc_sort(&a);
	//show_stack(a, "A");
	//show_stack(b, "B");
}
