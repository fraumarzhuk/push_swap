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
    int number;
    int index;
    int push_cost;
    bool above_median;
    bool cheapest;
    struct s_Stack *next;
    struct s_Stack *prev;
    struct s_Stack *target_node;
}   t_Stack;

void    insert_end(t_Stack **stack, int number);
void    find_last(t_Stack **stack);
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
int     init_stack_a(t_Stack *stack_a, char **argv);
void    sorting(t_Stack **stack_a, t_Stack **stack_b);
void    push_to_b(t_Stack **stack_a, t_Stack **stack_b);
int     stack_len(t_Stack *stack);
int     is_sorted(t_Stack *stack);
void    sort_three(t_Stack **stack_a);
long    ft_atol(const char *str);


#endif