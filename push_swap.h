#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "./libft/libft.h"
#include "./libft/printf/ft_printf.h"

// # include "./printf/printf.h"

typedef struct Stack
{
    int value;
    struct Stack *next;
    struct Stack *prev;
}   Stack;

void    insert_end(Stack **stack_a, int value);
