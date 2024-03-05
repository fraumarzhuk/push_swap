/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:39:19 by mzhukova          #+#    #+#             */
/*   Updated: 2024/03/05 13:30:22 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void push_to_b(t_Stack **stack_a, t_Stack **stack_b)
// {
//     while (stack_len(*stack_a) > 3)
//     {
//         pb(stack_a, stack_b);
//     }
// }

int is_sorted(t_Stack *stack) //new one
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

void sort_three(t_Stack **stack_a) //new one
{
    const t_Stack *biggest_node = find_max(*stack_a);
    
    if (*stack_a == biggest_node)
    {
        ra(stack_a, false);
    }
    else if ((*stack_a)->next == biggest_node)
    {
        rra(stack_a, false);
    }
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(*stack_a); 
}

void current_index(t_Stack *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return;
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

void perfom_real_magic_sorting(t_Stack **stack_a, t_Stack **stack_b) {
	int len_a; //To store the length of stack `a`

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !is_sorted(*stack_a)) //If stack `a` has more than three nodes and aren't sorted
		pb(stack_b, stack_a, false);
	if (len_a-- > 3 && !is_sorted(*stack_a)) //If stack `a` still has more than three nodes and aren't sorted
		pb(stack_b, stack_a, false);
	while (len_a-- > 3 && !is_sorted(*stack_a)) //If stack `a` still has more than three nodes and aren't sorted
	{
		init_nodes_a(*stack_a, *stack_b); //Iniate all nodes from both stacks
		move_a_to_b(stack_a, stack_b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
	}
	sort_three(stack_a);
	while (*stack_b) //Until the end of stack `b` is reached
	{
		init_nodes_b(*stack_a, *stack_b); //Initiate all nodes from both stacks
		move_b_to_a(stack_a, stack_b); //Move all `b` nodes back to a sorted stack `a`
	}
	current_index(*stack_a); //Refresh the current position of stack `a`
	min_on_top(stack_a); //Ensure smallest number is on top
}