/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands_by_chunk.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:45:46 by taehkim           #+#    #+#             */
/*   Updated: 2021/03/18 21:45:56 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	push_to_b_under_medium(t_stack *a, t_stack *b, int medium, int before)
{
	if (a->nums[a->top] <= medium && a->nums[a->top] > before)
		msg_act_two("pb", ft_push, a, b);
	else
		msg_act_one("ra", ft_reverse, a);
}

void	push_to_a_with_sort(t_stack *a, t_stack *b)
{
	int		min_index;
	int		max_index;
	int		min_index_dist;
	int		max_index_dist;

	while (get_stack_size(*b))
	{
		min_index = get_min_index(*b);
		max_index = get_max_index(*b);
		min_index_dist = get_dist_to_top(*b, min_index);
		max_index_dist = get_dist_to_top(*b, max_index);
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
}

void	get_commands_by_chunk(t_stack *a, t_stack *b, int size)
{
	int		i;
	int		k;
	int		medium;
	int		before;

	before = -2147483648;
	k = 0;
	while (k < size / a->chunk_size)
	{
		medium = find_medium(*a, a->chunk_size, k + 1);
		i = -1;
		while (++i < size)
			push_to_b_under_medium(a, b, medium, before);
		push_to_a_with_sort(a, b);
		while (a->nums[a->top] <= medium && a->nums[a->top] > before)
			msg_act_one("ra", ft_reverse, a);
		before = medium;
		k++;
	}
	while (a->nums[a->top] > medium)
		msg_act_two("pb", ft_push, a, b);
	push_to_a_with_sort(a, b);
	while (a->nums[a->top] > medium)
		msg_act_one("ra", ft_reverse, a);
}
