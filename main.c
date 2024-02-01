/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:43:28 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/01 15:14:11 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insert_end(t_Stack **stack_a, int value)
{
    t_Stack *new_node = malloc(sizeof(t_Stack));
    if (!new_node)
        exit (1);
    new_node->next = NULL;
    new_node->value = value;

    t_Stack *curr = *stack_a;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

int init_stack_a(t_Stack *stack_a, char *argv)
{
    char **input; 
    input = ft_split(argv, ' ');
    int j = 0;
    while (input[j])
    {
        char *str = input[j];
        for (int k = 0; str[k] != '\0'; k++) {
            if (!ft_isdigit(str[k])) {
                return(0);
            }
        }

        if (!stack_a->value)
            stack_a->value = ft_atoi(str);
        else
            insert_end(&stack_a, ft_atoi(str));
        
        j++;         
    }
    return (1);
}
int main(int argc, char **argv)
{
    t_Stack *stack_a;
    t_Stack *stack_b;

    stack_b = NULL;
    
    stack_a = malloc(sizeof(t_Stack));
    if (stack_a == NULL)
        exit(2);
    if (argc < 2 || (argc > 2 && !argv[1][0]))
        return (ft_printf("Error\n"));
    int i = 1;
    while (i < argc) // Skipping the name of the file
    {
       if (!init_stack_a(stack_a, argv[i]))
            return(ft_printf("Error\n"));
       i++;
    }
    ft_printf("Init a and b:\n");
    for (t_Stack *curr = stack_a; curr != NULL; curr = curr->next)
    {
        ft_printf("%d\n", curr->value);
    }
   ft_printf("_ _\na b\n");
}