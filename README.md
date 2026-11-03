*This project has been created as part of the 42 curriculum by ebayle.*

# get_next_line

## Description

get_next_line, reading a line from a file descriptor is way too tedious.

The goal is about programming a function that returns a line read from a file descriptor

`get_next_line.c` : 
`get_next_line.h` : 
`get_next_line_utils.c` : 

## Instructions

Compile:

```sh
make        # builds libft.a
```
```sh
make clean  # removes object files
```
```sh
make fclean # removes object files and libft.a
```
```sh
make re     # fclean + all
```

Use it in a project:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=256 get_next_line.c -L. -lft -I. -o program
```

## Resources

- `man 3` page of every function used
- [GNL Tester](https://github.com/Tripouille/gnlTester) by [Tripouille](Tripouille)
- [developpez.com](https://www.developpez.net/forums/d1765527/c-cpp/c/debuter/lire-ligne-file-descriptor/)
- [StackOverflow](https://stackoverflow.com/questions)

AI usage: Claude was used as a peer reviewer to point out edge cases and bugs
through hints, and to help with the Makefile and this README. All functions
were written by me.
