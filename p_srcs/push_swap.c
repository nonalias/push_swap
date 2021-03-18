/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:42:26 by taehkim           #+#    #+#             */
/*   Updated: 2021/03/18 21:42:27 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_commands(t_stack *a, t_stack *b)
{
	int		size;

	size = get_stack_size(*a);
	if (size == 5 || size == 4)
		get_under_5_commands(a, b);
	else if (size == 3)
		get_3_commands(a);
	else if (size == 2)
		get_2_commands(a);
	else
		get_commands_by_chunk(a, b, size);
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
	get_commands(&a, &b);
}
