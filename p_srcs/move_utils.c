/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:42:17 by taehkim           #+#    #+#             */
/*   Updated: 2021/03/18 21:42:18 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_min_index(t_stack st)
{
	long	min;
	int		min_index;
	int		i;

	min = 2500000000;
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
	long	max;
	int		max_index;
	int		i;

	max = -2500000000;
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
