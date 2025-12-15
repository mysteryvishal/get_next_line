*This project has been created as part of the 42 curriculum by vmistry*

# get_next_line

## Description
This repo implements a function that reads a line from a file descriptor and returns it as a string, handling arbitrary BUFFER_SIZE values and remaining bytes between calls.

## Instructions
- Implementation: [get_next_line.c](get_next_line.c) — function: [`get_next_line`](get_next_line.c)  
- Helpers: [get_next_line_utils.c](get_next_line_utils.c) — helpers: [`ft_strjoin`](get_next_line_utils.c), [`ft_substr`](get_next_line_utils.c), [`ft_strdup`](get_next_line_utils.c), [`ft_strchr`](get_next_line_utils.c), [`ft_strlen`](get_next_line_utils.c)  
- Header: [get_next_line.h](get_next_line.h) — defines [`BUFFER_SIZE`](get_next_line.h) 

Compile (without linking)
```bash
cc -c get_next_line.h get_next_line.c get_next_line_utils.c
```
To override BUFFER_SIZE at compile time append the following to the command above:
```
-D BUFFER_SIZE=42
```

## Resources
- man pages and references:
  - man 2 read
  - man 3 malloc / free / strerror
- Helpful guides:
  - C string handling and memory management primers (strchr, strlen, strdup, memcpy).
- Notes:
  - Free each returned line after use to avoid leaks.
  - Follow 42 coding standards and check for edge cases (empty files, binary data, very large BUFFER_SIZE).
