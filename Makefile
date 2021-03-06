CC	=	clang
CFLAG	=	-Wall -Wextra -Werror
HEADER	=	

GNL	=	get_next_line.c \
		get_next_line_utils.c

GNL_OBJS	=	$(GNL:%.c=%.o)

C_SRCS	=	checker.c
C_OBJS	=	$(C_SRCS:%.c=%.o)
P_SRCS	=	push_swap.c
P_OBJS	=	$(P_SRCS:%.c=%.o)

libft	=	Libft/libft.a

all	:	checker push_swap

$(libft)		:	
	$(MAKE) -C Libft

checker	:	$(C_OBJS) $(libft) $(GNL_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

push_swap	:	$(P_OBJS) $(libft) $(GNL_OBJS)
	$(CC) $(CFLAGS) $^ -o $@



%.o		:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -D BUFFER_SIZE=10


clean		:	
	$(MAKE) clean -C Libft
	rm -rf $(C_OBJS)

fclean		:	clean
	$(MAKE) fclean -C Libft
	rm -rf $(checker) $(push_swap)

.PHONY		:	all checker push_swap  libft clean fclean