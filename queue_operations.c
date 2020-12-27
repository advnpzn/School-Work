#include <stdio.h>
#include <stdlib.h>

#define MAX 10



struct queue
{
    int item[MAX];
    int FRONT;
    int REAR;
};
typedef struct queue qu;

void enqueue(qu* q);
void dequeue(qu* q);
int isEmpty(qu* q);
int isFull(qu* q);
void peek(qu* q);
void pQUEUE(qu* q);

void options(qu* q)
{   
    int choose;
    printf("\nQUEUE OPERATIONS\n------------------\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Print QUEUE\n(PRESS 9 TO EXIT)\n");
    scanf("%d",&choose);
    switch (choose)
    {
    case 1:
        enqueue(q);
        options(q);
    case 2:
        dequeue(q);
        options(q);
    case 3:
        peek(q);
        options(q);
    case 4:
        pQUEUE(q);
        options(q);
    case 9:
        exit(0);
    default:
        printf("Invalid Option.");
        options(q);
    }
}

void enqueue(qu* q)
{
    int elem;
    printf("Element to Enqueue : ");
    scanf("%d",&elem);
    if (isFull(q)){
        printf("\nQUEUE IS FULL!\n");
    }
    else
    {   
        q -> REAR++;
        q -> FRONT = 0;
        q -> item[q -> REAR] = elem;
    }
    
}

void dequeue(qu* q)
{
    if (isEmpty(q))
        printf("\nQUEUE IS EMPTY!\n");
    else
    {
        printf("Element Popped : %d",q -> item[q -> FRONT]);
        q -> FRONT++;
        if (q -> FRONT > q -> REAR)
        {
            q -> FRONT = -1;
            q -> REAR = -1;
        }
    }
        
}

int isEmpty(qu* q)
{
    if (q -> FRONT == -1)
        return 1;
    else
        return 0;
}

int isFull(qu* q)
{
    if (q -> REAR == MAX -1)
        return 1;
    else
        return 0;
}

void peek(qu* q)
{
    if (isEmpty(q))
        printf("\nQUEUE IS EMPTY!");
    else
        printf("FRONT ELEMENT : %d",q -> item[q -> FRONT]);
}

void pQUEUE(qu* q)
{
    if (isEmpty(q))
    {
        printf("QUEUE IS EMPTY!");
    }
    else
    {
        printf("\nQUEUE : ");
        for (int i = q -> FRONT; i <= q -> REAR; i++){
            printf("%d,",q -> item[i]);
        }
    }
    
        
}


//Driver code
int main()
{   
    qu* q = (qu*)malloc(sizeof(q));   
    q -> FRONT = -1;
    q -> REAR = -1;
    options(q);
}
