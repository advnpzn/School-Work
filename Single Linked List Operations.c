#include <stdio.h>
#include <stdlib.h>

struct node
{
    int elem;
    struct node *next;
};
typedef struct node n;

void display(n *h);
void insertAtBeginning(n** h, int elem);
void insertAtEnd(n** h, int elem);
void insertAfter(n* node, int elem);
void search(n* h, int elem);

void main(){
    n *head;
    n *one = malloc(sizeof(n));
    n *two = malloc(sizeof(n));
    n *three = malloc(sizeof(n));

    one -> elem = 1;
    two -> elem = 2;
    three -> elem = 3;

    one -> next = two;
    two -> next = three;
    three -> next = NULL;
    head = one;
    display(head);
    insertAtBeginning(&head,37);
    printf("After Inserting at the beginning ...\n");
    display(head);
    insertAtEnd(&head, 6699);
    printf("After Inserting at the End...\n");
    display(head);
    insertAfter(one -> next, 420);
    printf("\nAfter inserting after the specified Node...\n");
    display(head);
    search(head, 37);
}

void display(n *h){
    while (h != NULL){
        printf("%d--->",h -> elem);
        h = h -> next;
    }
}

void insertAtBeginning(n** h, int elem){
    n *newNode = malloc(sizeof(n));
    newNode -> elem = elem;
    newNode -> next = *h;
    *h = newNode;
    return;
}

void insertAtEnd(n** h, int elem){
    n *newNode = malloc(sizeof(n));
    n *temp = *h;
    newNode -> elem = elem;
    newNode -> next = NULL;

    if (*h == NULL){
        *h = newNode;
        return;
    }

    while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    return;
}

void insertAfter(n* node, int elem){
    if (node == NULL){
        printf("The previous node cannot be NULL");
        return;
    }
    n *newNode = malloc(sizeof(n));
    newNode -> elem = elem;
    newNode -> next = node -> next;
    node -> next = newNode;
    return;
}

void search(n* h, int elem){
    int c = 0;
    n* a;
    while (h -> next != NULL){
        if (h -> elem == elem){
            c = 1;
            a = h ;
        }
        h = h -> next;
    }
    if (c == 1)
        printf("\nElement is present in the Linked List.\nThe address is %d",a);
    else 
        printf("\nElement not found in the Linked list.");
}
