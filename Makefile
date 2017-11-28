.PHONY: clean, fclean, re

CC=gcc
CFLAGS= -Wall -Wextra -Werror #-Wconversion
OBJP=./obj/
LIBP=libft/
LIB=libft.a
NAME=fillit
FILES=createsheet.c cleansheet.c fillsheet.c visualize.c index.c main.c solve.c stack.c
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(addprefix $(OBJP), $(OBJS))
	$(MAKE) -C $(LIBP)
	$(CC) $(CFLAGS) -o $@ $(addprefix $(LIBP), $(LIB)) $^

debug: 
	$(CC) $(CFLAGS) -g $(LIBP)*.c $(FILES) -o $(NAME)

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
