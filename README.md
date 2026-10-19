*This project has been created as part of the 42 curriculum by mmitrovi.*

# ft_printf

## Description
`ft_printf` is a 42 school project that challenges us to recode our own version of the standard C library function `printf()`. While it won't cover every single complex feature of the original GNU implementation, it successfully replicates its core functionality and visual output for the required conversion formats.

The project handles standard specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

# Doxigen Comment
To better understand my code functions and parameters, please look at the breaf explanation in Doxigen comments.
There you can see breaf explaination what function does, as well as an explanation of the parameters and what it returns.

---

## Instructions

1. Clone the repository with `git clone`.
2. This project includes a Makefile to build the static library (`libftprintf.a`).
3. Run the following command at the root of the project to compile:
   ```bash
   make
4. After that you can clear .o and .a files using:
   ```bash
   make clean
   make fclean
5. Last part is to recompile whole project from scartch with:
   ```bash
   make re
6. To test my code please uncomment main from ft_printf.c and compile it like this:
   ```bash
   cc -Wall -Wextra -Werror ft_printf.c libftprintf.a -o test
7. Por el fin, just start the program:
   ```bash
   ./test
## Explanation
# what should you see? 

You should see comparison of my ft_printf and original printf function for each specifier. And also you should see the length of characters each function return.

## Resources:
Documentation: Man pages, Geekforgeeks, Gemini.
Peers: git hub: Durian Sosa, Alberto, Caperale, Sebastian, cvizcain.

# AI usage:
AI was used as a supporting tool exclusively for proofreading, spell-checking, and correcting grammar in this README file.

## Thank you for your time!
