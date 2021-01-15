#include <stdio.h>
#include <stdlib.h>



struct Node{
    int val;
    struct Node *next;
};
typedef struct Node N;

N* head;



void create(){
    int i,n;
    printf("\nEnter the no.of nodes to be inserted : ");
    scanf("%d",&n);
    N* temp;
    N* newNode;
    for (i=1; i<=n; i++){
        newNode = malloc(sizeof(N));
        printf("\nEnter the Value : ");
        scanf("%d",&newNode->val);
        newNode->next = NULL;
        if (i==1){
            head = newNode;
            temp = head;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
        
    }
}

void display(){
    N* temp = head;
    while (temp!=NULL){
        printf("%d--->",temp->val);
        temp = temp->next;
    }
}

void insert(){
    int choose;
    printf("\n1.Beginning\n2.Middle\n3.End\n\nEnter your Choice : ");
    scanf("%d",&choose);
    switch(choose){
    case 2:     /*MIDDLE*/
    {
        int i=1,pos;
        N* temp = head;
        N* newNode = malloc(sizeof(N));
        printf("\nEnter the Value : ");
        scanf("%d",&newNode->val);
        display();
        printf("\nEnter the position to insert the Node : ");
        scanf("%d",&pos);
        newNode->next = NULL;
        while (i<pos-1){
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode; 
        temp = newNode;
        display();
        break;
    }
    case 1:     /*BEGINNING*/
    {
        N* newNode = malloc(sizeof(N));
        printf("\nEnter the Value : ");
        scanf("%d",&newNode->val);
        newNode->next = head;
        head = newNode;
        printf("\nNode inserted Successfully !");
        break;
    }
    case 3:     /*END*/
    {
        N* temp = head;
        N* newNode = malloc(sizeof(N));
        printf("\nEnter the Value : ");
        scanf("%d",&newNode->val);
        while (temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
        printf("\nNode inserted Successfully !");
        break;
    }
    default:
        printf("\nEnter from the choices 1-3.");
        break;
    }
}

void find(){
    printf("Insert");
}

void delete(){
    printf("Insert");
}


void main(){
    int choose;
    do{
        printf("\n1.Create\n2.Display\n3.Insert\n4.Find\n5.Delete\n6.Exit\n\nEnter your Choice : ");
        scanf("%d",&choose);
        switch (choose){
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            find();
            break;
        case 5:
            delete();
            break;
        case 6:
            exit(0);
        default:
            printf("\nChoose 1-6 .");
            break;
        }
    } while (choose < 7);
}
