.PHONY: clean, fclean, re

CC=gcc
CFLAGS= -Wall -Wextra -Werror -Wconversion
OBJP=./obj/
LIBP=libft/
LIB=libft.a
NAME=fillit
FILES=getindex.c main.c
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(addprefix $(OBJP), $(OBJS))
	$(MAKE) -C $(LIBP)
	$(CC) $(CFLAGS) -o $@ $(addprefix $(LIBP), $(LIB)) $^

$(addprefix $(OBJP), %.o): %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(addprefix $(OBJP), $(OBJS))
	$(MAKE) -C $(LIBP) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(addprefix $(LIBP), $(LIB))

re:
	$(MAKE) fclean
	$(MAKE) all
