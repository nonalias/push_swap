#ifndef __PUSH_SWAP_H
#define __PUSH_SWAP_H
#include "./Libft/libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

typedef struct	s_stack
{
	int		nums[10000];
	int		top;
	int		bottom;
	int		size;
}				t_stack;

int		ft_intlen(int n);

void	ft_swap(t_stack *st);
void	ft_push(t_stack *source, t_stack *target);
void	ft_reverse(t_stack *st);
void	ft_r_reverse(t_stack *st);

void	line_exec(t_stack *a, t_stack *b, char *line);


int		validate(int argc, char **argv);

int		get_stack_size(t_stack stack);
int		get_stack_nbr_len(t_stack st);
void	show_stack(t_stack a, const char *what);

int		init(t_stack *a, t_stack *b, int argc, char **argv);

void	msg(const char *str);
#endif
