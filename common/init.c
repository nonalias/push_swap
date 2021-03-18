/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:34:23 by taehkim           #+#    #+#             */
/*   Updated: 2021/03/18 21:34:24 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_overlap(t_stack *st, int num)
{
	int		i;

	i = st->top;
	while (i < st->bottom)
	{
		if (st->nums[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	get_chunk(t_stack *a)
{
	if (a->size >= 100 && a->size < 250)
		a->chunk_size = a->size / 3;
	else if (a->size >= 250)
		a->chunk_size = a->size / 5;
	else
		a->chunk_size = 2;
}

int		init(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;
	int		temp;

	if (!validate(argc, argv))
		return (0);
	a->top = 5000;
	a->bottom = 5000;
	i = 0;
	while (i < argc - 1)
	{
		temp = ft_atoi(argv[i + 1]);
		if (check_overlap(a, temp))
			return (0);
		a->nums[a->top + i] = temp;
		a->bottom++;
		i++;
	}
	a->size = get_stack_size(*a);
	get_chunk(a);
	b->top = 5000;
	b->bottom = 5000;
	b->size = get_stack_size(*b);
	return (1);
}
