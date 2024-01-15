#include <stdlib.h>

// Defining the linked list
typedef struct Node
{
    int x;
    //Pointer, pointing to the next Node:
    struct Node *next;
}   Node;

void insert_end(Node **root, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
        exit (1);
    new_node->next = NULL;
    new_node->x = value;

    Node *curr = *root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

#include <stdio.h>

// int main(int argc, char **argv)
// {
//     if (!argc || !argv)
//         return (0);
//     Node root;
//     root.x = 15;
//     // Dynamically allocating memory 
//     root.next = malloc(sizeof(Node));
//     root.next->x = -2;
//     root.next-> next = malloc(sizeof(Node));
//     root.next->next->x = 22;
//     root.next->next->next = NULL;

//     Node *curr = &root;

//     //Simple while loop for iterating through Node and printing out the numbers
//     while (curr != NULL)
//     {
//         printf("%d\n", curr->x);
//         curr = curr -> next;
//     }
//     //Freeing used memory
//     // free(root.next->next);
//     // free(root.next);
//     return (0);
// }

int main(int argc, char **argv)
{
    if (!argc || !argv)
        return (0);
    Node *root = malloc(sizeof(Node));
    if (root == NULL)
        exit(2);
    root->x = 15;
    root->next = NULL;

    insert_end(&root, -2);
    insert_end(&root, -11);
    for (Node *curr = root; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->x);
    }
}