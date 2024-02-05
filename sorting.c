/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:39:19 by mzhukova          #+#    #+#             */
/*   Updated: 2024/02/05 16:37:47 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void push_to_b(t_Stack **stack_a, t_Stack **stack_b)
{
    while (stack_len(*stack_a) > 3)
    {
        pb(stack_a, stack_b);
    }
}
void sorting(t_Stack **stack_a, t_Stack **stack_b)
{
    push_to_b(stack_a, stack_b);
    //1.Push all elements from stack_a to stack_b, except three
    //2. Sort the 3 elements left in stack_a
    //3. Loop as long as there are elements in stack B:
    //-- Find the current position of every element in stack_a and stack_b
    //-- Calculate the TARGET positiom in stack_a where every element should be in stack_b
    //-- Calculate the cost and the cheapest way to move every element from stack_a to stack_b. Choose the cheapest element to move. Move the cheapest element from stack_a to stack_b
    //-- Execute the sequence of actions needed to move the element from stack B to stack A.
    //4. If stack A is not sorted, chose between ra and rra to rotate it into ascending order.
    

}
