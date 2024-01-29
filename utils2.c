/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:19:02 by mzhukova          #+#    #+#             */
/*   Updated: 2024/01/29 14:23:53 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void rb(Stack *stack_a, Stack *stack_b)
{
    ft_printf("rb\n");
}
// rr : ra and rb at the same time.
void rr(Stack *stack_a, Stack *stack_b)
{
    ra(stack_a, stack_b);
    rb(stack_a, stack_b);
}
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void rra(Stack *stack_a, Stack *stack_b)
{
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
