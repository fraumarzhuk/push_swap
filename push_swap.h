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

void    insert_end(t_Stack **stack_a, int value);
void    sa(t_Stack *stack_a);
void    sb(t_Stack *stack_b);
void    ss(t_Stack *stack_a, t_Stack *stack_b);
void    pa(t_Stack **stack_a, t_Stack **stack_b);
void    pb(t_Stack **stack_a, t_Stack **stack_b);
void    ra(t_Stack **stack_a);
void    rb(t_Stack **stack_b);
void    rr(t_Stack *stack_a, t_Stack *stack_b);
void    rra(t_Stack **stack_a);
void    rrb(t_Stack **stack_b);
void    rrr(t_Stack *stack_a, t_Stack *stack_b);
int     init_stack_a(t_Stack *stack_a, char *argv);
int     init_stack_b(t_Stack *stack_b);
void    sorting(t_Stack *stack_a, t_Stack *stack_b);
void    push_to_b(t_Stack *stack_a, t_Stack *stack_b);

//helpers:

#endif