CC=clang
CSTD=c17
NAME=test
CFLAGS=-std=$(CSTD) -Wall -Werror -Wpedantic
FILES=$(NAME).c colored_msg.c

all:
	@ $(CC) $(CFLAGS) -o $(NAME) $(FILES)

run: all
	@ ./$(NAME)

clean:
	@ rm $(NAME)