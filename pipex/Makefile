NAME = pipex.a

AR = @ar -rc

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

CC = @cc 

SRCS = ft_pipex.c ft_func.c ft_str.c

OBJS = ${subst .c,.o,${SRCS}}

all : $(NAME)

$(NAME) : ${OBJS}
	${AR} $(NAME) ${OBJS}
	${CC} ${CFLAGS} ${NAME} -o pipex

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} $(NAME) pipex

re : fclean all
