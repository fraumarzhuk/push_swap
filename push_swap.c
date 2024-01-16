#include <stdio.h>
#include <stdlib.h>


typedef struct Stack
{
    int x;
    //Pointer, pointing to the next Node:
    struct Stack *next;
}   Stack;

Stack *stack_a;
Stack *stack_b;

void insert_end(Stack **stack_a, int value)
{
    Stack *new_node = malloc(sizeof(Stack));
    if (!new_node)
        exit (1);
    new_node->next = NULL;
    new_node->x = value;

    Stack *curr = *stack_a;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (printf("Please compile with argument. Programm failed. Just like your parents did.\n"));
    //Cover the cases with one ane argument in a string, or arguments provided without strings
    Stack *stack_a = malloc(sizeof(Stack));
    if (stack_a == NULL)
        exit(2);
    stack_a->x = atoi(argv[1]);
    stack_a->next = NULL;
    int i = 2;
    while (i < argc) //skipping the name of the file
    {
        insert_end(&stack_a, atoi(argv[i]));
        i++;
    }
    //print the values for testing purposes:
    for (Stack *curr = stack_a; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->x);
    }
    //Cover the cases with multiple arguments, placed in one string
}