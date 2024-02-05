/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:26:06 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/05 14:52:24 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_len(t_Stack *stack)
{
    int count = 0;
    t_Stack *current = stack;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}