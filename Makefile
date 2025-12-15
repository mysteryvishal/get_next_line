CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = get_next_line.h get_next_line_utils.c get_next_line.c

MAIN = test_2.c
TEST = test_file1.txt

all:
	$(CC) $(CFLAGS) $(SRCS) $(MAIN) -D BUFFER_SIZE=42

debug:
	$(CC) -g $(SRCS) $(MAIN)

build:
	$(CC) $(CFLAGS) $(SRCS) $(MAIN)

test:
	./a.out $(TEST)

fclean:
	$(RM) -rf ./a.out ./a.out.dSYM ./get_next_line.h.*

re: fclean all