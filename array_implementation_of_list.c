#include <stdio.h>

#define MAX 10
int list[MAX],n,i;

void display();
void insert();
void delete();
void search();

int main(){
    printf("Enter the no.of elements to be added in the list : ");
    scanf("%d",&n);
    printf("Enter the Array elements : \n");
    for (i=0; i<n; i++){
        scanf("%d",&list[i]);
    }
    display();
    insert();
    display();
    delete();
    display();
    search();
    
    return 0;
}


void display(){
    for (i=0; i<n; i++){
        printf("[%d]",list[i]);
    }
}


void insert(){
    int pos,elem;
    printf("\nEnter the element to be inserted : ");
    scanf("%d",&elem);
    printf("\nEnter the Position : ");
    scanf("%d",&pos);
    if (pos > n){
        printf("\nArray Overflow\n");
    }
    else{
        for (i = n -1; i>= pos - 1; i--){
            list[i+1] = list[i];
        }
        list[pos - 1] = elem;
        n = n+1;
    }
}


void delete(){
    int pos;
    printf("\nEnter the Position to Delete : ");
    scanf("%d",&pos);
    for(i=pos-1; i<n; i++){
        list[i] = list[i+1];
    }
    n = n-1;
}


void search(){
    int search;
    int pos = n;
    printf("\nEnter the Element to search in the list : ");
    scanf("%d",&search);
    for (i=0; i<n; i++){
        if (list[i] == search){
            pos = i;
        }
    }
    if (pos < n )
        printf("\nElement is present in the list.\nPosition : %d",pos+1);
    else
        printf("\nElement is not present in the list .");
}
