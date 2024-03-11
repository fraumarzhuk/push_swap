/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:39:19 by mzhukova          #+#    #+#             */
/*   Updated: 2024/03/11 14:45:41 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_Stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_Stack **stack_a)
{
	const t_Stack	*biggest_node;

	biggest_node = find_max(*stack_a);
	if (*stack_a == biggest_node)
	{
		ra(stack_a, false);
	}
	else if ((*stack_a)->next == biggest_node)
	{
		rra(stack_a, false);
	}
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a, false);
}

void	above_median(t_Stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	perfom_real_magic_sorting(t_Stack **stack_a, t_Stack **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_b, stack_a, false);
	while (len_a-- > 3 && !is_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	above_median(*stack_a);
	min_on_top(stack_a);
}
