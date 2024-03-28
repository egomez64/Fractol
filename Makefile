NAME = fractol

LIBFT = libft/libft.a

MACROLIBX = MacroLibX/libmlx.so

CC = cc

SRCS = main.c init.c hook.c result.c

HEADERS = fractol.h

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

ifdef DEBUG
CFLAGS = -Wall -Wextra -g
endif

ifdef CHECK
CFLAGS += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MACROLIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MACROLIBX) -o $@ -lm -lSDL2

$(LIBFT):
	@make -j8 -C libft/ all

$(MACROLIBX):
	@make -j8 -C MacroLibX/

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)
	@make -C libft/ clean
	@make -C MacroLibX/ clean
	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(MACROLIBX)

re: fclean all

.PHONY: all fclean clean re
