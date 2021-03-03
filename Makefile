NAME = libftprintf.a

SRCS = srcs/ft_printf.c \

OBJS = 

INCLUDES = include/ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)

$(OBJS): $(SRCS) $(INCLUDES)
        @gcc -Wextra -Werror -Wall -c (SRCS)
        @ar rcs $(NAME) $(OBJS)
        
clean:
        rm -rf $(OBJS)
        
fclean: clean
        rm -rf $(NAME)
        
re: fclean all
