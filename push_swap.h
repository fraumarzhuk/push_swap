#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./libft/printf/ft_printf.h"

typedef struct s_Stack
{
    int value;
    int index;
    int push_cost;
    bool above_median;
    bool cheapest;
    struct s_Stack *target_node;
    struct s_Stack *next;
    struct s_Stack *prev;
}   t_Stack;

void    insert_end(s_Stack **stack_a, int value);
void    sa(s_Stack *stack_a);
void    sb(s_Stack *stack_b);
void    ss(s_Stack *stack_a, s_Stack *stack_b);
void    pa(s_Stack **stack_a, s_Stack **stack_b);
void    pb(s_Stack **stack_a, s_Stack **stack_b);
void    ra(s_Stack **stack_a);
void    rb(s_Stack **stack_b);
void    rr(s_Stack *stack_a, s_Stack *stack_b);
void    rra(s_Stack **stack_a);
void    rrb(s_Stack **stack_b);
void    rrr(s_Stack *stack_a, s_Stack *stack_b);

#endif