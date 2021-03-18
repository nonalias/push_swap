CC	=	clang
CFLAGS	=	-Wall -Wextra -Werror
HEADER	=	

GNL	=	./c_srcs/get_next_line.c \
		./c_srcs/get_next_line_utils.c

GNL_OBJS	=	$(GNL:%.c=%.o)

CHECKER	=	checker
PUSH_SWAP	=	push_swap

C_SRCS	=	./c_srcs/checker.c \
		./common/validate.c \
		./common/init.c \
		./common/utils.c \
		./c_srcs/line_exec.c \
		./common/action.c \
		./common/stack_utils.c \
		./common/msg_action.c \

C_OBJS	=	$(C_SRCS:%.c=%.o)
P_SRCS	=	./p_srcs/push_swap.c \
		./common/validate.c \
		./common/init.c \
		./common/utils.c \
		./common/action.c \
		./common/stack_utils.c \
		./common/msg_action.c \
		./p_srcs/get_commands_under_5.c \
		./p_srcs/get_commands_by_chunk.c \
		./p_srcs/move_utils.c \

P_OBJS	=	$(P_SRCS:%.c=%.o)

libft	=	Libft1/libft.a

all	:	checker push_swap

$(libft)		:	
	$(MAKE) -C Libft1

$(CHECKER):	$(C_OBJS) $(libft) $(GNL_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(PUSH_SWAP)	:	$(P_OBJS) $(libft) $(GNL_OBJS)
	$(CC) $(CFLAGS) $^ -o $@



%.o		:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -D BUFFER_SIZE=10


clean		:	
	$(MAKE) clean -C Libft1
	rm $(C_OBJS)
	rm $(P_OBJS)
	rm $(GNL_OBJS)

fclean		:	clean
	$(MAKE) fclean -C Libft1
	rm $(checker) $(push_swap)

re		:	fclean all

.PHONY		:	all checker push_swap  libft clean fclean re
