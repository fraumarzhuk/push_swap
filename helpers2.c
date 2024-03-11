/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:15:05 by mariannazhu       #+#    #+#             */
/*   Updated: 2024/03/11 18:26:40 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Stack	*find_max(t_Stack *stack)
{
	long	max;
	t_Stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	min_on_top(t_Stack **stack_a)
{
	while ((*stack_a)->number != find_min(*stack_a)->number)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}
