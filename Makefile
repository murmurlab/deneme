srcs            = $(shell find . -name "*.c")

CC              = cc
RM              = rm -f
CFLAGS          = -std=c99 -Wall -Wextra  -I.

OBJS            = $(srcs:.c=.o)

NAME			= murmurlibc.a

all:            $(NAME)

$(NAME):        $(OBJS)
				ar rcs $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS)
				
fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:         all clean fclean re