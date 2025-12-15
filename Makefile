CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = get_next_line.h get_next_line_utils.c get_next_line.c
MAIN = test_main.c

all:
	$(CC) $(CFLAGS) $(SRCS) $(MAIN) -D BUFFER_SIZE=42

buildtest:
	$(CC) $(SRCS) $(MAIN)

test:
	./a.out test_1.txt

fclean:
	$(RM) ./a.out ./get_next_line.h.*

re: fclean all