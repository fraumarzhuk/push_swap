/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:13:27 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/15 18:01:53 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_target_a(t_Stack *stack_a, t_Stack *stack_b)
{
    t_Stack *current_b;
    t_Stack *target_node;
    long    best_match_index;

    while(stack_a)
    {
        best_match_index = LONG_MIN;
        current_b = stack_b;
        while(current_b)
        {
            if (current_b->number > best_match_index)
            {
                best_match_index = current_b->number;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (best_match_index == LONG_MIN)
            stack_a->target_node = find_max(stack_b);
        else
            stack_a->target_node = target_node;
        stack_a = stack_a->next;
    }
}

void cost_analysis_a(t_Stack *stack_a, t_Stack *stack_b)
{
    int len_a;
    int len_b;

    len_a = stack_len(stack_a);
    len_b = stack_len(stack_b);
    while (stack_a)
    {
        stack_a->push_cost = stack_a->index;
        if (!(stack_a->above_median))
            stack_a->push_cost = len_a - (stack_a->index);
        if (stack_a->target_node->above_median)
            stack_a->push_cost += stack_a->target_node->index;
        else
            stack_a->push_cost += len_b - (stack_a->target_node->index);
        stack_a = stack_a->next;
    }
}