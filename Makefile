srcs            = $(shell find . -name "*.c")

CC              = clang
RM              = rm -f
wflags			= -Wall -Wextra -Werror
CFLAGS          = -std=c99 -g $(wflags) -I.

OBJS            = $(srcs:.c=.o)

NAME			= libmurmurc.a

all:            $(NAME)

$(NAME):        $(OBJS)
				ar rcs $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS)
				
fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:         all clean fclean re