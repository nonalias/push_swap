#include <unistd.h>
#include "./Libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

typedef struct	s_stack
{
	int		nums[10000];
	int		top;
	int		bottom;
	int		size;
}				t_stack;

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

void	err_msg(const char *str)
{
	ft_putstr_fd(str, 1);
}

int		validate(int argc, char **argv)
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
		i++;
	}
	return (1);
}

int		get_stack_size(t_stack stack)
{
	return stack.bottom - stack.top;
}

int		get_stack_nbr_len(t_stack st)
{
	int count = 0;

	for (int i = st.top; i < st.bottom; i++)
	{
		count += ft_intlen(st.nums[i]);
		count += 1;
	}
	return (count);
}

// banned function! remove before submit this subject.
void	show_stack(t_stack a, const char *what)
{
	int		count;

	count = get_stack_nbr_len(a);
	for (int i = 0; i < 16 + count; i++)
	{
		ft_putstr_fd("-", 1);
	}
	ft_putstr_fd("\n", 1);
	//printf("---------------------------------------------\n");
	printf("%s stack   top   ", what);
	for (int j = a.top; j < a.bottom; j++)
		printf("%d ", a.nums[j]);
	printf("|bottom\n");
	for (int i = 0; i < 16 + count; i++)
	{
		ft_putstr_fd("-", 1);
	}
	ft_putstr_fd("\n", 1);
	//printf("---------------------------------------------\n");
}

int		init(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;

	if (!validate(argc, argv))
		return (0);
	a->top = 5000;
	a->bottom = 5000 + argc - 1;
	i = 0;
	while (i < argc - 1)
	{
		a->nums[a->top + i] = ft_atoi(argv[i + 1]);
		i++;
	}
	a->size = get_stack_size(*a);
	b->top = 5000;
	b->bottom = 5000;
	b->size = get_stack_size(*b);
	return (1);
}

void	ft_swap(t_stack *st)
{
	int		temp;

	if (st->size <= 1)
		return;
	temp = st->nums[st->top];
	st->nums[st->top] = st->nums[st->top + 1];
	st->nums[st->top + 1] = temp;
}

void	ft_push(t_stack *source, t_stack *target)
{
	if (source->size == 0)
		return ;
	target->nums[--target->top] = source->nums[source->top++];
	source->size = get_stack_size(*source);
	target->size = get_stack_size(*target);
}

void	ft_reverse(t_stack *st)
{
	if (st->size <= 1)
		return ;
	st->nums[st->bottom] = st->nums[st->top];
	st->top++;
	st->bottom++;
}

void	ft_r_reverse(t_stack *st)
{
	if (st->size <= 1)
		return ;
	st->nums[st->top - 1] = st->nums[st->bottom - 1];
	st->top--;
	st->bottom--;
}

void	action(t_stack *a, t_stack *b, char *line)
{
	if (!ft_strncmp(line, "sa", 2))
		ft_swap(a);
	else if (!ft_strncmp(line, "sb", 2))
		ft_swap(b);
	else if (!ft_strncmp(line, "ss", 2))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (!ft_strncmp(line, "pa", 2))
		ft_push(b, a);
	else if (!ft_strncmp(line, "pb", 2))
		ft_push(a, b);
	else if (!ft_strncmp(line, "ra", 2))
		ft_reverse(a);
	else if (!ft_strncmp(line, "rb", 2))
		ft_reverse(b);
	else if (!ft_strncmp(line, "rr", 2))
	{
		ft_reverse(a);
		ft_reverse(b);
	}
	else if (!ft_strncmp(line, "rra", 3))
		ft_r_reverse(a);
	else if (!ft_strncmp(line, "rrb", 3))
		ft_r_reverse(b);
	else if (!ft_strncmp(line, "rrr", 3))
	{
		ft_r_reverse(a);
		ft_r_reverse(b);
	}
	else
	{
		err_msg("Error\n");
		exit(1);
	}
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*line;

	if (!init(&a, &b, argc, argv))
	{
		err_msg("Error\n");
		return (1);
	}
	show_stack(a, "A");
	show_stack(b, "B");
	while (get_next_line(0, &line))
	{
		action(&a, &b, line);
	show_stack(a, "A");
	show_stack(b, "B");
		free(line);
	}
	/*
	show_stack(a, "A");
	show_stack(b, "B");
	*/
	for (int i = a.top; i < a.bottom; i++)
	{
		if (a.nums[a.top] > a.nums[a.top + 1])
		{
			printf("KO\n");
			return (0);
		}
	}
	printf("OK\n");
}
