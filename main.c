/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:43:28 by mzhukova          #+#    #+#             */
/*   Updated: 2024/01/29 13:43:33 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack *stack_a;
Stack *stack_b;

void insert_end(Stack **stack_a, int value)
{
    Stack *new_node = malloc(sizeof(Stack));
    if (!new_node)
        exit (1);
    new_node->next = NULL;
    new_node->value = value;

    Stack *curr = *stack_a;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

int main(int argc, char **argv)
{
    if (argc < 2 || (argc > 2 && !argv[1][0]))
    // TODO:
    //Handle error handling in all the cases(incorrect input zbs)
    //Error with dublicated inputs
    //Create 2 stacks;
        return (ft_printf("Please compile with arguments. Programm failed. Just like your parents did.\n"));
    //Cover the cases with one ane argument in a string, or arguments provided without strings
    Stack *stack_a = malloc(sizeof(Stack));
    if (stack_a == NULL)
        exit(2);
    // stack_a->value = ft_atoi(argv[1]);
    stack_a->next = NULL;
    int i = 1;
    char **input;
    while (i < argc) //skipping the name of the file
    {
       input = ft_split(argv[i], ' ');
        while (*input)
        {
            if(!stack_a->value)
                stack_a->value = ft_atoi(*input);
            else
                insert_end(&stack_a, ft_atoi(*input));
            input++;         
        }
        i++;
    }
    //print the values for testing purposes:
    for (Stack *curr = stack_a; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->value);
    }
    //Don't forget to cover the cases with multiple arguments, placed in one string
}