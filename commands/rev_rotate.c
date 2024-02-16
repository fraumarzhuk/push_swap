/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:20:23 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/16 12:43:29 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate(t_Stack **stack)
{
	t_Stack	*last; 

	if (!*stack || !(*stack)->next) 
		return ;
	last = find_last(*stack);
	last->prev->next = NULL; 
	last->next = *stack; 
	last->prev = NULL; 
	*stack = last;  
	last->next->prev = last;
}

void	rra(t_Stack **stack_a, bool print)
{
	rev_rotate(stack_a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_Stack **stack_b, bool print) 
{
	rev_rotate(stack_b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_Stack **stack_a, t_Stack **stack_b, bool print)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!print)
		ft_printf("rrr\n");
}
