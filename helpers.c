/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:26:06 by mzhukova          #+#    #+#             */
/*   Updated: 2024/03/05 13:49:03 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack_a(t_Stack *stack_a) {
	ft_printf("Stack A Contents:\n");
	while (stack_a != NULL) {
		ft_printf("%d\n", stack_a->number);
		stack_a = stack_a->next; // Move to the next node
	}
}
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
    while (ft_isdigit(*str))
        res = res * 10 + (*str++ - '0');
    return (res * sign);
}

t_Stack *find_last(t_Stack *stack)
{
    if (!stack)
        return(NULL);
    while (stack->next)
        stack = stack->next;
    return(stack);
}

t_Stack *find_min(t_Stack *stack)
{
    long min;
    t_Stack *min_node;
    
    if (!stack)
        return (NULL);
    min = LONG_MAX;
    while (stack)
    {
        if (stack->number < min)
        {
            min = stack->number;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}

t_Stack *find_max(t_Stack *stack)
{
    long max;
    t_Stack *max_node;

    if (!stack)
        return (NULL);
    max = LONG_MIN;
    while (stack)
    {
        if (stack->number > max)
        {
            max = stack->number;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}

 void	min_on_top(t_Stack **stack_a) 
{
	while ((*stack_a)->number != find_min(*stack_a)->number)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
	}
}