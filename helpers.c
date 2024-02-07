/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:26:06 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/07 15:45:51 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_len(t_Stack *stack) //new one
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

long ft_atol(const char *str) //asci to long
{
    long res;
    int sign;

    res = 0;
    sign = 1;

    while (*str == ' ' || *str == '\t' || *str == '\n'
            || *str == '\r' || *str == '\f' || *str == '\v')
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = - 1;
        str++;
    }
    while (is_digit(*str))
        res = res * 10 + (*str++ - '0');
    return (res);
}