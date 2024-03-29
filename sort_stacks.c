/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:35:07 by mzhukova          #+#    #+#             */
/*   Updated: 2024/03/11 18:22:49 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_Stack **stack_a, t_Stack **stack_b,
				t_Stack	*cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
		rr(stack_a, stack_b, false);
	above_median(*stack_a);
	above_median(*stack_b);
}

void	rev_rotate_both(t_Stack **stack_a,
								t_Stack **stack_b,
								t_Stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node
		&& *stack_a != cheapest_node)
		rrr(stack_a, stack_b, false);
	above_median(*stack_a);
	above_median(*stack_b);
}

void	move_a_to_b(t_Stack **stack_a, t_Stack **stack_b)
{
	t_Stack	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		rotate_both(stack_a, stack_b, cheapest_node);
	}
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
	{
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	}
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_b, stack_a, false);
}

void	move_b_to_a(t_Stack **stack_a, t_Stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b, false);
}
