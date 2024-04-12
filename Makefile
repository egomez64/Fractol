NAME = fractol

LIBFT = libft/libft.a

MACROLIBX = MacroLibX/libmlx.so

FT_PRINTF = ft_printf/libftprintf.a

CC = cc

SRCS = main.c init.c hook.c result.c events.c ft_atod.c color.c

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

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MACROLIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MACROLIBX) -o $@ -lm -lSDL2

$(LIBFT):
	@make -j8 -C libft/ all

$(MACROLIBX):
	@make -j8 -C MacroLibX/
	
$(FT_PRINTF):
	@make -j8 -C ft_printf/ all

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)
	@make -C libft/ clean
	@make -C MacroLibX/ clean
	@make -C ft_printf/ clean
	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(MACROLIBX)
	rm -f $(FT_PRINTF)

re: fclean all

.PHONY: all fclean clean re
