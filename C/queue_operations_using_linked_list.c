#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};
typedef struct Node N;


N *FRONT = NULL;
N *REAR = NULL;


void enQUEUE()
{
    int value;
    N *newNode = malloc(sizeof(N));
    printf("\nEnter the Value to Insert : ");
    scanf("%d", &value);
    newNode->val = value;
    newNode->next = NULL;
    if (FRONT == NULL)
    {
        FRONT = newNode;
        REAR = FRONT;
    }
    else
    {
        REAR->next = newNode;
        REAR = newNode;
    }
    printf("\nSuccessfull!\n");
}


void deQUEUE()
{
    if (FRONT == NULL)
    {
        printf("QUEUE IS EMPTY!");
    }
    else
    {
        N *temp = FRONT;
        printf("Dequeued %d .", temp->val);
        FRONT = FRONT->next;
        free(temp);
        printf("\nSuccessful!\n");
    }
}


void display()
{
    if (FRONT == NULL)
    {
        printf("QUEUE IS EMPTY!");
    }
    else
    {
        N *temp = FRONT;
        while (temp != NULL)
        {
            printf("%d--->", temp->val);
            temp = temp->next;
        }
    }
}


int main()
{
    int choose;
    do
    {
        printf("\n-------CHOOSE----------\n");
        printf("1.enQUEUE\n2.deQUEUE\n3.Display\n4.EXIT\n ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            enQUEUE();
            break;
        case 2:
            deQUEUE();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nChoose 1-4.");
        }
    } while (1);
    
    return 0;
}
