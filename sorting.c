/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:39:19 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/07 15:47:46 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void push_to_b(t_Stack **stack_a, t_Stack **stack_b)
{
    while (stack_len(*stack_a) > 3)
    {
        pb(stack_a, stack_b);
    }
}

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
    t_Stack *biggest_node;
    
    biggest_node = malloc(sizeof(t_Stack));
    if (*stack_a == biggest_node)
        rra(stack_a);
    else if ((*stack_a)->next == biggest_node)
        rra(stack_a);
    if ((*stack_a)->number > (*stack_a)->next->number)
        sa(stack_a);
    
}

void perfom_real_magic_sorting(t_Stack *stack_a, t_Stack *stack_b)
{
    int len_a;

    len_a = stack_len(*stack_a);
    
}