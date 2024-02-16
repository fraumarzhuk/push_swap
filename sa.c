/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:20:23 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/16 12:46:06 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void sa(t_Stack *stack_a)
{
    int temp;
    
    temp = 0;
    if (stack_a != NULL && stack_a->next != NULL)
    {
        temp = stack_a->number;
        stack_a->number = stack_a->next->number;
        stack_a->next->number = temp;
        ft_printf("sa\n");
    }
}