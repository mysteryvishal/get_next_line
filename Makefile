CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = get_next_line_utils.c get_next_line.c
MAIN = test_main.c
OUT = test_gnl

all:
	$(CC) $(CFLAGS) -o $(OUT) $(SRCS) $(MAIN)

debug:
	$(CC) -g -o $(OUT) $(SRCS) $(MAIN) -D BUFFER_SIZE=42

build:
	$(CC) -o $(OUT) $(SRCS) $(MAIN)

fclean:
	$(RM) ./$(OUT) ./$(OUT).dSYM ./a.out

re: fclean all

.PHONY: all debug build fclean re