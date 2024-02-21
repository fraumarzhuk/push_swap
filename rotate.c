/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:49:06 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/21 13:56:58 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_Stack **stack)
{
	t_Stack	*last_node;

	if (!*stack || !(*stack)->next) 
		return ;
	last_node = find_last(*stack); 
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}		

void	ra(t_Stack **stack_a, bool print)
{
	rotate(stack_a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_Stack **stack_b, bool print)
{
	rotate(stack_b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_Stack **stack_a, t_Stack *stack_b, bool print)
{
	rotate(stack_a);
	rotate(&stack_b);
	if (!print)
		ft_printf("rr\n");
}