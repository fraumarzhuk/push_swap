/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:43:28 by mzhukova          #+#    #+#             */
/*   Updated: 2024/03/11 19:16:30 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_end(t_Stack **stack, int number)
{
	t_Stack	*new_node;
	t_Stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_Stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->number = number;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack_a(t_Stack **stack_a, char **argv)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_errors(argv[i]))
			handle_errors(stack_a);
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			handle_errors(stack_a);
		if (duplication_errors(*stack_a, (int)number))
			handle_errors(stack_a);
		insert_end(stack_a, (int)number);
		i++;
	}
}

// void print_stack(t_Stack **stack_a) {
//     // Check if the stack pointer is NULL
//     if (stack_a == NULL || *stack_a == NULL) {
//         ft_printf("The stack is empty.\n");
//         return;
//     }

//     // Pointer to traverse the stack
//     t_Stack *current = *stack_a;

//     // Traverse the stack and print each element
//     while (current != NULL) {
//         ft_printf("%d\n", current->number);
//         current = current->next; // Move to the next element
//     }
// }

void	argc_init(int argc, char **argv, t_Stack **stack_a, t_Stack **stack_b)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack_a(stack_a, argv);
		free_split(argv);
	}
	else
		init_stack_a(stack_a, (argv +1));
	if (!is_sorted(*stack_a))
	{
		if (stack_len(*stack_a) == 2)
			sa(stack_a, false);
		else if (stack_len(*stack_a) == 3)
			sort_three(stack_a);
		else
			perfom_real_magic_sorting(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	argc_init(argc, argv, &stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
