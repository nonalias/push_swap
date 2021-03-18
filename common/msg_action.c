/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:36:33 by taehkim           #+#    #+#             */
/*   Updated: 2021/03/18 21:36:36 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
