/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:39:19 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/05 16:48:08 by mzhukova         ###   ########.fr       */
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

int is_sorted(t_Stack *stack)
{
    while (stack->next != NULL)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void sort_stack_a(t_Stack **stack_a)
{

    while (!is_sorted(*stack_a))
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
            sa(*stack_a);
        else
            ra(stack_a);
    }
}
void sorting(t_Stack **stack_a, t_Stack **stack_b)
{
    push_to_b(stack_a, stack_b);
    sort_stack_a(stack_a);
    //1.Push all elements from stack_a to stack_b, except three - done
    //2. Sort the 3 elements left in stack_a
    //3. Loop as long as there are elements in stack B:
    //-- Find the current position of every element in stack_a and stack_b
    //-- Calculate the TARGET positiom in stack_a where every element should be in stack_b
    //-- Calculate the cost and the cheapest way to move every element from stack_a to stack_b. Choose the cheapest element to move. Move the cheapest element from stack_a to stack_b
    //-- Execute the sequence of actions needed to move the element from stack B to stack A.
    //4. If stack A is not sorted, chose between ra and rra to rotate it into ascending order.
    

}
