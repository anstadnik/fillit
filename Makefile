.PHONY: clean, fclean, re

CC=gcc
CFLAGS= -Wall -Wextra -Werror 
OBJP=./obj/
LIBP=libft/
LIB=libft.a
NAME=fillit
FILES=main.c
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(addprefix $(OLIB), $(OBJS))
	$(MAKE) -C $(LIBP)
	$(CC) $(CFLAGS) -o $@ $(addprefix $(LIBP), $(LIB)) $^

$(addprefix $(OLIB), %.o): %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(addprefix $(OLIB), $(OBJS))
	$(MAKE) -C $(LIBP) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(addprefix $(LIBP), $(LIB))

re:
	$(MAKE) fclean
	$(MAKE) all
