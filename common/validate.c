/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:38:50 by taehkim           #+#    #+#             */
/*   Updated: 2021/03/18 21:38:51 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long	ft_atoll(const char *str)
{
	int			idx;
	long long	result;
	int			sign;

	idx = 0;
	result = 0;
	sign = 0;
	while (str[idx] == ' ' || (str[idx] > 8 && str[idx] < 14))
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
		sign = -(str[idx++] - 44);
	if (str[idx] >= '0' && str[idx] <= '9')
	{
		if (sign == 0)
			sign = 1;
		while (str[idx] >= '0' && str[idx] <= '9')
			result = (result * 10) + (str[idx++] - '0');
	}
	return (sign * result);
}

int			is_in_integer(long long number)
{
	long long	min;
	long long	max;

	min = -2147483648;
	max = 2147483647;
	if (min <= number && number <= max)
		return (1);
	return (0);
}

int			validate(int argc, char **argv)
{
	int		i;
	int		j;
	int		size;

	if (argc <= 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		size = ft_strlen(argv[i]);
		while (j < size)
		{
			if ((j >= 1) && !ft_isdigit(argv[i][j]))
				return (0);
			if (j == 0 && !ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (0);
			j++;
		}
		if (!is_in_integer(ft_atoll(argv[i])))
			return (0);
		i++;
	}
	return (1);
}
