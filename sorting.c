/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:39:19 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/16 12:39:18 by mzhukova         ###   ########.fr       */
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
    t_Stack *biggest_node;
    
    biggest_node = malloc(sizeof(t_Stack));
    if (*stack_a == biggest_node)
        rra(stack_a, false);
    else if ((*stack_a)->next == biggest_node)
        rra(stack_a, false);
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

void perfom_real_magic_sorting(t_Stack **stack_a, t_Stack **stack_b)
{
    int len_a;

    len_a = stack_len(*stack_a);
    if (len_a-- > 3 && !is_sorted(*stack_a))
        pb(stack_a, stack_b, false);
    if (len_a-- > 3 && !is_sorted(*stack_a))
        pb(stack_a, stack_b, false);
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
}