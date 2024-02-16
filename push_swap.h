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
void     init_stack_a(t_Stack **stack_a, char **argv);



//Errors:
int     syntax_errors(const char *str);
int     duplication_errors(t_Stack *stack, int n);
void    free_stack(t_Stack *stack);
void    handle_errors(t_Stack **stack);

//Helpers:
t_Stack *find_last(t_Stack *stack);
long    ft_atol(const char *str);
int     stack_len(t_Stack *stack);
t_Stack *find_min(t_Stack *stack);
t_Stack *find_max(t_Stack *stack);

//Sorting:
void    move_to_b(t_Stack **stack_a, t_Stack **stack_b);
int     is_sorted(t_Stack *stack);
void    sort_three(t_Stack **stack_a);
void    current_index(t_Stack *stack);
void    perfom_real_magic_sorting(t_Stack **stack_a, t_Stack **stack_b);

//Sort_stacks:
void move_a_to_b(t_Stack **stack_a, t_Stack **stack_b);
void move_b_to_a(t_Stack **stack_a, t_Stack **stack_b);

//Init a to b:

void    set_target_a(t_Stack *stack_a, t_Stack *stack_b);
void    cost_analysis_a(t_Stack *stack_a, t_Stack *stack_b);
void    set_cheapest(t_Stack *stack);
void    init_nodes_a(t_Stack *stack_a, t_Stack *stack_b);

//Init b to a

void    set_target_b(t_Stack *stack_a, t_Stack *stack_b);

#endif