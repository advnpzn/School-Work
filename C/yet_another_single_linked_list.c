/* Linked list again! Because i'm addicted to it!! */
/* This time just the creation and printing it */

/* Importing necessary libraries */
#include <stdio.h>
#include <stdlib.h>


/* Create a Node structure */
struct node
{
    int data;
    struct node *next;
};


/* Function prototype(s) */ 
void printNodes(struct node *n);
void freeNodes(struct node *n);


/* Driver function */
int main()
{
    int no_of_nodes;
    struct node *head, *temp;

    /* Asking to enter the number of nodes */
    printf("Enter the number of nodes : ");
    scanf("%d", &no_of_nodes);

    /* Create HEAD node if atleast 1 Node, if not exit indicating a failure. */
    if (no_of_nodes >= 1 )
    {
        head = malloc(sizeof(struct node));
        printf("Enter Head Node's Data : ");
        scanf("%d", &(head -> data));
        head -> next = NULL;
        temp = head;
    }
    else{
        exit(-1);
    }

    /* Creating the nodes after HEAD */
    for (int i=0; i < no_of_nodes - 1; i++)
    {
        struct node *n = malloc(sizeof(struct node));
        temp -> next = n;
        printf("Enter Node %d data : ", i+1);
        scanf("%d", &(n -> data));

        temp = n;
    }
    temp -> next = NULL;    /* There's no next node to the last node in a single linked list, so giving it NULL. */
    
    printNodes(head);
    freeNodes(head);
    return 0;
}   

/* This function traverses through each Node and prints the Data resides in it. */
void printNodes(struct node *n)
{
    while(n != NULL)
    {   
        if (n -> next != NULL)
            printf("%d%s", n -> data, " -> ");
        else
            printf("%d%s", n -> data, " -> NULL\n");
        n = n->next;
    }
}

/* This function will release the memory allocated to the node structure manually */
/* It traverses through each node and releases their memory after taking note of the pointer to the next node. */
void freeNodes(struct node *n)
{
    struct node *temp;

    while(n != NULL)
    {
        temp = n;
        n = n -> next;
        free(temp);
    }
}
