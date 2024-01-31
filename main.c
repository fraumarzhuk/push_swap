/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:43:28 by mzhukova          #+#    #+#             */
/*   Updated: 2024/01/31 12:56:12 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Stack *stack_a;
t_Stack *stack_b;

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

int main(int argc, char **argv)
{
    if (argc < 2 || (argc > 2 && !argv[1][0]))
    // TODO:
    //Handle error handling in all the cases(incorrect input zbs)
    //Error with dublicated inputs
    //Create 2 stacks;
        return (ft_printf("Please compile with arguments. Programm failed. Just like your parents did.\n"));
    //Cover the cases with one ane argument in a string, or arguments provided without strings
    t_Stack *stack_a = malloc(sizeof(t_Stack));
    if (stack_a == NULL)
        exit(2);
    // stack_a->value = ft_atoi(argv[1]);
    stack_a->next = NULL;
    int i = 1;
    char **input;
    while (i < argc) // Skipping the name of the file
    {
        input = ft_split(argv[i], ' ');
        int j = 0;
        while (input[j])
        {
            char *str = input[j];
            for (int k = 0; str[k] != '\0'; k++) {
                if (ft_isalpha(str[k])) {
                    return(printf("Error\n"));
                }
            }

            if (!stack_a->value)
                stack_a->value = ft_atoi(str);
            else
                insert_end(&stack_a, ft_atoi(str));
            
            j++;         
        }
        i++;
    }
    //Print thge initiation of the stack(remove later):
    ft_printf("Init a and b:\n");
    for (t_Stack *curr = stack_a; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->value);
    }
    printf("_ _\na b\n");
    //Don't forget to cover the cases with multiple arguments, placed in one string
    //TODO:
    //1. Sorting 3 numbers;
    //2. Sorting 5 numbers;
    //3. Create an algorithm for large numbers. Create a 3rd stack;
}
