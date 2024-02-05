/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:43:20 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/05 14:59:49 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void sb(t_Stack *stack_b)
{
    int temp;
    
    temp = 0;
    if (stack_b != NULL && stack_b->next != NULL)
    {
        temp = stack_b->value;
        stack_b->value = stack_b->next->value;
        stack_b->next->value = temp;
        ft_printf("sb\n");
    }
}
// ss : sa and sb at the same time.
void ss(t_Stack *stack_a, t_Stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
}
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void pa(t_Stack **stack_a, t_Stack **stack_b)
{
    t_Stack *temp;

    if (*stack_b != NULL)
    {
        temp = *stack_b;            // Store the top element of stack_b
        *stack_b = (*stack_b)->next; // Remove the top element from stack_b
        temp->next = *stack_a;       // Push the removed element onto stack_a
        *stack_a = temp;
        ft_printf("pa\n");
    }
}
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void pb(t_Stack **stack_a, t_Stack **stack_b)
{
    t_Stack *top;

    if (*stack_a == NULL)
        return;

    top = *stack_a;
    *stack_a = (*stack_a)->next;
    top->next = *stack_b;
    *stack_b = top;
    ft_printf("pb\n");
}
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void ra(t_Stack **stack_a)
{
    t_Stack *first;
    t_Stack *last;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return; // Do nothing if the stack is empty or has only one element
    first = *stack_a;
    last = *stack_a;
    // Move to the last element of the stack
    while (last->next != NULL)
        last = last->next;
    // Perform the rotation
    *stack_a = first->next;
    first->next = NULL;
    last->next = first;

    ft_printf("ra\n");
}