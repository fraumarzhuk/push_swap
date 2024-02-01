/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:39:19 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/01 17:45:42 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void push_back_to_a(t_Stack *stack_a, t_Stack *stack_b)
// {
//     t_Stack *curr_a = stack_a;
//     t_Stack *curr_b = stack_b;
//     while (stack_b)
//     {
//         pa(&stack_a, &stack_b);
//         curr_a = stack_a;
//         curr_b = stack_b;
//     }
// }                                                  

void sorting(t_Stack *stack_a, t_Stack *stack_b)
{
    //1.Push back all elements from stack_b to stack_a, except three
    //2. Sort the 3 elements left in stack_a
    //3. Loop as long as there are elements in stack B:
    //-- Find the current position of every element in stack_a and stack_b
    //-- Calculate the TARGET positiom in stack_a where every element should be in stack_b
    //-- Calculate the cost and the cheapest way to move every element from stack_a to stack_b. Choose the cheapest element to move. Move the cheapest element from stack_a to stack_b
    //-- Execute the sequence of actions needed to move the element from stack B to stack A.
    //4. If stack A is not sorted, chose between ra and rra to rotate it into ascending order.
    

}
