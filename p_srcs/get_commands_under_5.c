/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands_under_5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:45:27 by taehkim           #+#    #+#             */
/*   Updated: 2021/03/18 21:46:19 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_3_commands(t_stack *a)
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
	get_3_commands(a);
	while (get_stack_size(*b))
	{
		msg_act_two("pa", ft_push, b, a);
		if (a->nums[a->top] > a->nums[a->top + 1])
			msg_act_one("ra", ft_reverse, a);
	}
}

void	get_2_commands(t_stack *a)
{
	if (a->nums[a->top] > a->nums[a->top + 1])
		msg_act_one("sa", ft_swap, a);
}
