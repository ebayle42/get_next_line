*This project has been created as part of the 42 curriculum by ebayle.*

# get_next_line

## Description

get_next_line, reading a line from a file descriptor is way too tedious.

The goal is about programming a function that returns a line read from a file descriptor until it achieve the end of the file

### How it works

Each call to `get_next_line()` returns the next line of the file (including the `\n`), or `NULL` when there is nothing left to read or an error occurs.

Since `read()` reads `BUFFER_SIZE` bytes at a time, it often reads more than one line. The extra characters are kept between calls in a **static variable** (the *stash*)

### Functions

`get_next_line.c` :
- `get_next_line()`: checks `fd` and `BUFFER_SIZE`, then fills the stash, extracts the line, cleans the stash and returns the line.
- `read_to_stash()`: reads `BUFFER_SIZE` bytes at a time and appends them to the stash until it contains a `\n` or `read` returns 0, freeing everything and returning `NULL` on error.
- `extract_line()`: allocates and returns a copy of the stash up to and including the first `\n` (or up to the end if there is none).
- `clean_stash()`: returns a new string with what follows the first `\n`, frees the old stash, and returns `NULL` if nothing is left.

`get_next_line_utils.c` :
- `ft_strlen()`: returns the length of `str`, or 0 if `str` is `NULL`.
- `ft_strjoin()`: returns a new string made of `s1` followed by `s2` and frees `s1`, so the old stash never leaks.
- `ft_strlcpy()`: copies at most `size - 1` characters from `src` to `dst`, always ends with `\0` and returns the length of `src`.
- `ft_strchr()`: returns a pointer to the first occurrence of `c` in `s`, or `NULL` if it is not found or `s` is `NULL`.

`get_next_line.h` :
- Defines `BUFFER_SIZE` (1000 by default, can be changed with `-D BUFFER_SIZE=n`), includes `<stdlib.h>` and `<unistd.h>`, and declares the prototypes.


## Instructions

Compile 
```sh
cc -Wall -Wextra -Werror get_next_line.c get_next_line.h get_next_line_utils.c  
```

## Resources

- `man 3` page of every function used
- [GNL Tester](https://github.com/Tripouille/gnlTester) by [Tripouille](Tripouille)
- [developpez.com](https://www.developpez.net/forums/d1765527/c-cpp/c/debuter/lire-ligne-file-descriptor/)
- [StackOverflow](https://stackoverflow.com/questions)

AI usage: Claude was used as a peer reviewer to point out edge cases and bugs
through hints, and to help with the Makefile and this README. All functions
were written by me.
