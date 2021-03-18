/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:41:17 by taehkim           #+#    #+#             */
/*   Updated: 2021/03/18 21:41:19 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_stack_size(t_stack stack)
{
	return (stack.bottom - stack.top);
}

int		get_stack_nbr_len(t_stack st)
{
	int		count;
	int		i;

	count = 0;
	i = st.top;
	while (i < st.bottom)
	{
		count += ft_intlen(st.nums[i]);
		count += 1;
		i++;
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
