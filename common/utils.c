/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:36:10 by taehkim           #+#    #+#             */
/*   Updated: 2021/03/18 21:36:12 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_intlen(int i)
{
	int		len;

	len = 0;
	if (i < 0)
	{
		len++;
		i *= -1;
	}
	while (i)
	{
		i /= 10;
		len++;
	}
	return (len);
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
