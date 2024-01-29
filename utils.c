/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:43:20 by mzhukova          #+#    #+#             */
/*   Updated: 2024/01/29 13:58:36 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void sa(Stack *stack_a, Stack *stack_b)
{
    ft_printf("sa\n");
}
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void sb(Stack *stack_a, Stack *stack_b)
{
    ft_printf("sb\n");
}
// ss : sa and sb at the same time.
void sb(Stack *stack_a, Stack *stack_b)
{
    sa(stack_a, stack_a);
    sb(stack_a, stack_b);
}
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void pa(Stack *stack_a, Stack *stack_b)
{
    ft_printf("pa\n");
}
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void pb(Stack *stack_a, Stack *stack_b)
{
    ft_printf("pb\n");
}
// ra (rotate a): Shift up all elements of stack a by 1.
void ra(Stack *stack_a, Stack *stack_b)
{
    ft_printf("ra\n");
}
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.

