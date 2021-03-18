#ifndef __PUSH_SWAP_H
#define __PUSH_SWAP_H
#include "../Libft1/libft.h"
#include "../c_srcs/get_next_line.h"
#include <unistd.h>
#include <stdio.h>

typedef struct	s_stack
{
	int		nums[10000];
	int		top;
	int		bottom;
	int		size;
	int		chunk_size;
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
void	msg_act_one(char *func_name, void (*act)(t_stack *), t_stack *a);
void	msg_act_two(char *func_name, void (*act)(t_stack *, t_stack *),
		t_stack *a, t_stack *b);


void	get_3_commands(t_stack *a);
void	get_under_5_commands(t_stack *a, t_stack *b);
void	get_2_commands(t_stack *a);

int		get_min_index(t_stack st);
int		get_max_index(t_stack st);
int		get_dist_to_top(t_stack st, int index);
void	move_to_the_top(t_stack *st, int index, int flag);

int		find_medium(t_stack st, int chunk_size, int repeat);
void	push_to_b_under_medium(t_stack *a, t_stack *b, int medium, int before);
void	push_to_a_with_sort(t_stack *a, t_stack *b);
void	get_commands_by_chunk(t_stack *a, t_stack *b, int size);

int		check_asc(t_stack st);
#endif
