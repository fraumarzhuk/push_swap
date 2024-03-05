/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:24:23 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/16 11:52:09 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int syntax_errors(char *str)
{
    if (!(*str == '+'
          || *str == '-'
          || (*str >= '0' && *str <= '9')))
        return (1);
    if ((*str == '+'
         || *str == '-')
        && !(str[1] >= '0' && str[1] <= '9'))
        return (1);
    while (*++str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return (1);
    }
    return (0);
}

int duplication_errors(t_Stack *stack, int n)
{
    if (!stack)
        return(0);
    while (stack)
    {
        if (stack->number == n)
            return (1);
        stack = stack->next;
    }
    return (0);
    
}

void free_stack(t_Stack *stack)
{
    t_Stack *temp;
    t_Stack *curr;

    if (!stack)
        return ;
    while (stack)
    {
        temp = curr->next;
        // curr->number = 0; (May help with debugging)
        free(curr);
        curr = temp;
    }
}

void handle_errors(t_Stack **stack)
{
    free_stack(*stack);
    ft_printf("Error\n");
    exit(1);
}