#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "./libft/libft.h"
#include "./libft/printf/ft_printf.h"

typedef struct Stack
{
    int value;
    struct Stack *next;
    struct Stack *prev;
}   Stack;

void    insert_end(Stack **stack_a, int value);
void    sa(Stack *stack_a);
void    sb(Stack *stack_b);
void    ss(Stack *stack_a, Stack *stack_b);
void    pa(Stack **stack_a, Stack **stack_b);
void    pb(Stack **stack_a, Stack **stack_b);
void    ra(Stack **stack_a);
void    rb(Stack *stack_a, Stack *stack_b);
void    rr(Stack *stack_a, Stack *stack_b);
void    rra(Stack *stack_a, Stack *stack_b);
void    rrb(Stack *stack_a, Stack *stack_b);
void    rrr(Stack *stack_a, Stack *stack_b);