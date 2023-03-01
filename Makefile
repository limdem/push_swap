RM	= rm -rf
CC	= gcc 
CFLAGS=-Wall -Wextra -Werror
NAME	= push_swap
INCLUDES = -I ./includes
SRCS_DIR = srcs/
SRCS	=	main.c\
				three_sort.c\
				operations.c\
				operations2.c\
				operations3.c\
				extremes_pos.c\
				big_sort.c\
				utils.c\
				utils2.c\
				utils3.c\
				small_sort.c\
				parser.c
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))	
OBJS	= $(SRCS:.c=.o)

%.o: %.c
	${CC} -c ${CFLAGS} ${INCLUDES} $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

	
$(OBJS): $(SRCS_PATH)
	${CC} -c ${CFLAGS} ${INCLUDES} ${SRCS_PATH}

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re