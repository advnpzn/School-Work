/* Linked list again! Because i'm addicted to it!! */
/* This time just the creation and printing it */

/* Importing necessary libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Create a Node structure */
struct node
{
    int data;
    struct node* next;
};



/* Function prototype(s) */ 
void printNodes(struct node *n);
void freeNodes(struct node *n);
void insertNode(struct node **n, int pos);
int listLength(struct node *n);


/* Driver function */
int main()
{
    int no_of_nodes, insert_choice;
    struct node *head;
    struct node *temp;

    /* Asking to enter the number of nodes */
    printf("Enter the number of nodes : ");
    scanf("%d", &no_of_nodes);

    /* Create HEAD node if atleast 1 Node, if not exit indicating a failure. */
    if (no_of_nodes >= 1 )
    {
        head = malloc(sizeof(struct node));
        //printf("Head Node address = %d\n", head);
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
    do{
        printf("1.Insert Node\n2.Print Linked List\n3.Exit\nChoose : ");
        scanf("%d", &insert_choice);
        switch (insert_choice){
            case 1:
                    int pos;
                    printNodes(head);
                    printf("Enter the position [Note: Starting Position is 0] : ");
                    scanf("%d", &pos);
                    insertNode(&head, pos);
                    break;
        
            case 2:
                    printNodes(head);
                    break;
            case 3:
                    exit(0);
            default:
                printf("Choose either 1 or 2 or 3.");
                break;
        }

        
    }while(insert_choice > 0);

    printNodes(head);
    freeNodes(head);

    return 0;
}   

/* This function traverses through each Node and prints the Data resides in it. */
void printNodes(struct node *n)
{
    //printf("Head Address (printNodes) : %d\n", n);
    //printf("%d", n -> data);
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


/* Inserting a Node at Nth position */
void insertNode (struct node **head, int pos)
{
    //printf("Head Address (insertNodes) : %d\n", head);

    int len = listLength(*head);
    struct node *n;
    struct node *temp = *head;

    if (pos > len || pos < 0)
    {
        printf("Position you have chosen is out of bounds of the length of the Linked List.\n");
    }

    n = malloc(sizeof(struct node));
    printf("Enter the Node data : ");
    scanf("%d", &(n -> data));

    if (pos == 0)
    {
        n -> next = *head;
        *head = n;
        printNodes(*head);
    }   
    else if ( pos == (len - 1) )
    {
        while ( temp -> next != NULL )
        {

            temp = temp -> next;
        }
        temp -> next = n;
        n -> next = NULL;
        printNodes(*head);
    }
    else
    {

        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp -> next;
        }
        n -> next = temp -> next;
        temp -> next = n;
        printNodes(*head);

    }

    
}


int listLength(struct node *n)
{
    int count = 0;
    while (n != NULL)
    {
        count++;
        n = n -> next;
    }

    return count;
}
