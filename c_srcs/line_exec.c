/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:36:19 by taehkim           #+#    #+#             */
/*   Updated: 2021/03/18 21:36:22 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	line_exec2(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp(line, "rr", 3))
	{
		ft_reverse(a);
		ft_reverse(b);
	}
	else if (!ft_strncmp(line, "rra", 4))
		ft_r_reverse(a);
	else if (!ft_strncmp(line, "rrb", 4))
		ft_r_reverse(b);
	else if (!ft_strncmp(line, "rrr", 4))
	{
		ft_r_reverse(a);
		ft_r_reverse(b);
	}
	else
	{
		msg("Error\n");
		exit(1);
	}
}

void	line_exec(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp(line, "sa", 3))
		ft_swap(a);
	else if (!ft_strncmp(line, "sb", 3))
		ft_swap(b);
	else if (!ft_strncmp(line, "ss", 3))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (!ft_strncmp(line, "pa", 3))
		ft_push(b, a);
	else if (!ft_strncmp(line, "pb", 3))
		ft_push(a, b);
	else if (!ft_strncmp(line, "ra", 3))
		ft_reverse(a);
	else if (!ft_strncmp(line, "rb", 3))
		ft_reverse(b);
	else
		line_exec2(a, b, line);
}
