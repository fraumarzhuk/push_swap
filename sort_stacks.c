/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:35:07 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/21 14:37:10 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_Stack **stack_a, t_Stack **stack_b, t_Stack *cheapest_node) 
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node) 
		rr(stack_a, *stack_b, false);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	rev_rotate_both(t_Stack **stack_a,
								t_Stack **stack_b,
								t_Stack *cheapest_node) 
{
	while (*stack_b != cheapest_node->target_node
		&& *stack_a != cheapest_node) 
		rrr(stack_a, stack_b, false); 
	current_index(*stack_a);
	current_index(*stack_b);
}

void move_a_to_b(t_Stack **stack_a, t_Stack **stack_b)
{
    t_Stack *cheapest_node;

    cheapest_node = get_cheapest(*stack_a);
    t_Stack *temp = *stack_a;
    int i = 0;
    while (temp){
		ft_printf("stack a %i: %i\n", i, temp->number);
		temp = temp->next;
        i++;
	}
    if (cheapest_node->above_median && cheapest_node->target_node->above_median){
        rotate_both(stack_a, stack_b, cheapest_node);
    }
    else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median)) {
        rev_rotate_both(stack_a, stack_b, cheapest_node);}
    ft_printf("Target_node: %i\n", cheapest_node->number);
    prep_for_push(stack_a, cheapest_node, 'a');
    prep_for_push(stack_b, cheapest_node->target_node, 'b');
    pb(stack_b, stack_a, false);
    ft_printf("Move a to b\n");
}

void move_b_to_a(t_Stack **stack_a, t_Stack **stack_b)
{
    prep_for_push(stack_a, (*stack_b)->target_node, 'a');
    pb(stack_a, stack_b, false);
}