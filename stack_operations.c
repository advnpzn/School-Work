#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct stack
{
    int item[MAX];
    int TOP;
};
typedef struct stack st;


void push(st* s);
void pop(st* s);
int isEmpty(st* s);
int isFull(st* s);
void peek(st* s);
void pSTACK(st* s);


void options(st* s)
{   
    int choose;
    printf("\nSTACK OPERATIONS\n------------------\n1.Push\n2.Pop\n3.Peek\n4.Print STACK\n(PRESS 9 TO EXIT)\n");
    scanf("%d",&choose);
    switch (choose)
    {
    case 1:
        push(s);
        options(s);
    case 2:
        pop(s);
        options(s);
    case 3:
        peek(s);
        options(s);
    case 4:
        pSTACK(s);
        options(s);
    case 9:
        exit(0);
    default:
        printf("Invalid Option.");
        options(s);
    }
}


void push(st* s)
{
    int elem;
    printf("Element to push : ");
    scanf("%d",&elem);
    if (isFull(s)){
        printf("\nSTACK IS FULL!\n");
    }
    else
    {   
        s -> TOP++;
        s -> item[s -> TOP] = elem;
    }  
}


void pop(st* s)
{
    if (isEmpty(s))
        printf("\nSTACK IS EMPTY!\n");
    else
    {
        printf("Element Popped : %d",s -> item[s -> TOP]);
        s -> TOP--;
    } 
}


int isEmpty(st* s)
{
    if (s -> TOP == -1)
        return 1;
    else
        return 0;
}


int isFull(st* s)
{
    if (s -> TOP == MAX -1)
        return 1;
    else
        return 0;
}


void peek(st* s)
{
    printf("TOP ELEMENT : %d",s -> item[s -> TOP]);
}


void pSTACK(st* s)
{
    printf("\nSTACK : ");
    for (int i = 0; i<=s -> TOP; i++){
        printf("%d,",s -> item[i]);
    }
    printf("\n");
}


//Driver code
int main()
{   
    st* s = (st*)malloc(sizeof(st));    //Allocating memory for the structure st aka struct stack
    s -> TOP = -1;
    options(s);
    return 0;
}
