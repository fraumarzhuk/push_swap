/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:24:23 by mzhukova          #+#    #+#             */
/*   Updated: 2024/03/11 15:26:27 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_errors(char *str)
{
	if (!(*str == '+'
			|| *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-'))
	{
		if (!(str[1] >= '1' && str[1] <= '9'))
			return (1);
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	duplication_errors(t_Stack *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->number == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_Stack **stack)
{
	t_Stack	*temp;
	t_Stack	*curr;

	if (!stack)
	{
		return ;
	}
	curr = *stack;
	while (curr)
	{
		temp = curr->next;
		curr->number = 0;
		free(curr);
		curr = temp;
	}
}

void	handle_errors(t_Stack **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}
