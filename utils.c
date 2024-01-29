/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:20:23 by mzhukova          #+#    #+#             */
/*   Updated: 2024/01/29 18:02:55 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void sa(Stack *stack_a)
{
    int temp;
    
    temp = 0;
    if (stack_a != NULL && stack_a->next != NULL)
    {
        temp = stack_a->value;
        stack_a->value = stack_a->next->value;
        stack_a->next->value = temp;
        ft_printf("sa\n");
    }
}