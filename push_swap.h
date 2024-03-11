/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:50:11 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/03/11 19:17:50 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				number;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_Stack	*next;
	struct s_Stack	*prev;
	struct s_Stack	*target_node;
}	t_Stack;

void	insert_end(t_Stack **stack, int number);
void	init_stack_a(t_Stack **stack_a, char **argv);

//Commands:

//Push
void	push(t_Stack **dst, t_Stack **src);
void	pa(t_Stack **stack_a, t_Stack **stack_b, bool print);
void	pb(t_Stack **b, t_Stack **a, bool print);

//Rotate
void	rotate(t_Stack **stack);
void	ra(t_Stack **stack_a, bool print);
void	rb(t_Stack **stack_b, bool print);
void	rr(t_Stack **stack_a, t_Stack **stack_b, bool print);

//Rev_rotate
void	rev_rotate(t_Stack **stack);
void	rra(t_Stack **stack_a, bool print);
void	rrb(t_Stack **stack_b, bool print);
void	rrr(t_Stack **stack_a, t_Stack **stack_b, bool print);

//Errors:
int		syntax_errors(char *str);
int		duplication_errors(t_Stack *stack, int n);
void	free_stack(t_Stack **stack);
void	handle_errors(t_Stack **stack);

//Helpers:

t_Stack	*find_last(t_Stack *stack);
long	ft_atol(const char *str);
int		stack_len(t_Stack *stack);
t_Stack	*find_min(t_Stack *stack);
t_Stack	*find_max(t_Stack *stack);
void	print_stack_a(t_Stack *stack_a);
void	min_on_top(t_Stack **stack_a);

//Sorting:
int		is_sorted(t_Stack *stack);
void	sort_three(t_Stack **stack_a);
void	above_median(t_Stack *stack);
void	perfom_real_magic_sorting(t_Stack **stack_a, t_Stack **stack_b);

//Sort_stacks:
void	move_a_to_b(t_Stack **stack_a, t_Stack **stack_b);
void	move_b_to_a(t_Stack **stack_a, t_Stack **stack_b);
void	rotate_both(t_Stack **stack_a, t_Stack **stack_b,
			t_Stack *cheapest_node);
void	rev_rotate_both(t_Stack **stack_a, t_Stack **stack_b,
			t_Stack	*cheapest_node);
//Init a to b:

void	set_target_a(t_Stack *stack_a, t_Stack *stack_b);
void	cost_analysis_a(t_Stack *stack_a, t_Stack *stack_b);
void	set_cheapest(t_Stack *stack);
void	init_nodes_a(t_Stack *stack_a, t_Stack *stack_b);

//Init b to a

void	set_target_b(t_Stack *stack_a, t_Stack *stack_b);
void	init_nodes_b(t_Stack *stack_a, t_Stack *stack_b);

//Stack_init

t_Stack	*get_cheapest(t_Stack *stack);
void	prep_for_push(t_Stack **stack,
			t_Stack *top_node, char stack_name);
void	free_split(char **split);
// Swap:
void	swap(t_Stack **head);
void	sa(t_Stack	**a, bool print);
void	sb(t_Stack **b, bool print);
void	ss(t_Stack **a, t_Stack **b, bool print);

#endif