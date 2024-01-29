/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:19:02 by mzhukova          #+#    #+#             */
/*   Updated: 2024/01/29 17:01:58 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void rb(Stack **stack_b)
{
    Stack *first;
    Stack *last;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    first = *stack_b;
    last = *stack_b;
    
    while(last->next != NULL)
        last = last->next;
    *stack_b = first->next;
    first->next = NULL;
    last->next = first;
    ft_printf("rb\n");
}
// rr : ra and rb at the same time.
void rr(Stack *stack_a, Stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void rra(Stack **stack_a)
{
    Stack *last, *second_to_last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return; // Do nothing if the stack is empty or has only one element

    last = *stack_a;
    second_to_last = NULL;

    // Find the last and second-to-last elements
    while (last->next != NULL)
    {
        second_to_last = last;
        last = last->next;
    }

    // Perform the reverse rotation
    if (second_to_last != NULL)
    {
        second_to_last->next = NULL;
        last->next = *stack_a;
        *stack_a = last;
    }

    ft_printf("rra\n");
}
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void rrb(Stack *stack_a, Stack *stack_b)
{
    ft_printf("rrb\n");
}
// rrr : rra and rrb at the same time.
void rrr(Stack *stack_a, Stack *stack_b)
{
    rra(stack_a, stack_b);
    rrb(stack_a, stack_b);
}
