/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:07:43 by mzhukova          #+#    #+#             */
/*   Updated: 2024/03/05 13:41:49 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_target_b(t_Stack *stack_a, t_Stack *stack_b)
{
    t_Stack *current_a;
    t_Stack *target_node;
    long    best_match_index;

    while(stack_b)
    {
        best_match_index = LONG_MAX;
        current_a = stack_a;
        while(current_a)
        {
            if (current_a->number > best_match_index && current_a->number < best_match_index)
            {
                best_match_index = current_a->number;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match_index == LONG_MAX)
            stack_b->target_node = find_min(stack_a);
        else
            stack_b->target_node = target_node;
        stack_b = stack_b->next;
    }
}

void init_nodes_b(t_Stack *stack_a, t_Stack *stack_b)
{
   current_index(stack_a);
   current_index(stack_b);
   set_target_b(stack_a, stack_b);
}