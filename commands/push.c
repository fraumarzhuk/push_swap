/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:43:20 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/16 11:58:09 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_Stack **dst, t_Stack **src) 
{
	t_Stack	*push_node; 

	if (!*src) 
		return ;
	push_node = *src; 
	*src = (*src)->next; 
	if (*src) 
		(*src)->prev = NULL; 
	push_node->prev = NULL;
	if (!*dst) 
	{
		*dst = push_node; 
		push_node->next = NULL; 
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node; 
	}
}

void	pa(t_Stack **stack_a, t_Stack **stack_b, bool print)
{
	push(stack_a, stack_b); 
	if (!print) 
		ft_printf("pa\n");
}

void	pb(t_Stack **b, t_Stack **a, bool print) 
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}