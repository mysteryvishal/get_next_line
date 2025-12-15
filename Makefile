CC = gcc
CFLAGS = -Wall -Wextra -Werror
DBGFLAGS = -g -O0
RM = rm -rf
SRCS = get_next_line_utils.c get_next_line.c
MAIN = test_2.c
OUT = test2

all:
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 -o $(OUT) $(SRCS) $(MAIN)

debug:
	$(CC) $(DBGFLAGS) -o $(OUT) $(SRCS) $(MAIN)

build:
	$(CC) $(CFLAGS) -o $(OUT) $(SRCS) $(MAIN)

test:
	./$(OUT) test_file1.txt

fclean:
	$(RM) ./$(OUT) ./$(OUT).dSYM

re: fclean all

.PHONY: all debug build test fclean re