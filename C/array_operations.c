#include<stdio.h>
#include<stdlib.h>

int lim,array[10000];


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


void displayArray(){
    printf("Array = ");
    for (int i = 0; i<lim; i++)
    {
        printf(" %d ",array[i]);
    }
}


void createArray(){
    
    printf("\nEnter the size of the Array : ");
    scanf("%d",&lim);
    array[lim];
    printf("\nEnter %d elements to the Array : \n",lim);
    for (int i=0 ;i<lim ;i++){
        scanf("%d",&array[i]);
    }
    displayArray();
}


void deleteArray(){
    int posDel,i;
    printf("\nEnter the Position of the element which you want to delete : ");
    scanf("%d",&posDel);
    if(posDel>=lim+1){
        printf("There's no elements in that position.");
        deleteArray();
    }
    else
    {
        for(i = posDel-1; i<lim-1; i++){
            array[i] = array[i+1];
        }
        printf("Array = ");
        for(i=0; i<lim-1; i++)
            printf(" %d ",array[i]);
    }
    lim-=1;
}


void insertArray(){
    int posIns,i,elem;
    printf("\nEnter the element that you want to Insert : ");
    scanf("%d",&elem);
    printf("\nEnter the Position where you want to insert the element : ");
    scanf("%d",&posIns);
    if(posIns>=lim+1){
        printf("\nThat Position is invalid.");
        insertArray();
    }
    else
    {
        for( i=lim-1; i>=posIns-1; i--){
            array[i+1] = array[i];
        }
        array[posIns-1] = elem;
        printf("Array = ");
        for( i=0; i<=lim; i++){
            printf(" %d ",array[i]);
        }
    }
    lim+=1;
}


void sortArray(){
    printf("\nArray before Sorting : \n");
    displayArray();
    qsort(array, lim, sizeof(int), cmpfunc);
    printf("\nArray after Sorting : \n");
    displayArray();
}


void operations(){
    int choose;
    printf("\nWhat would you like to do?(PRESS 9 to exit)\n1.Delete an Element\n2.Insert an element at the end\n3.Sort the Array\n4.Display the Array\n");
    scanf("%d",&choose);
    switch (choose)
    {
    case 1:
        deleteArray();
        operations();

        break;
    case 2:
        insertArray();
        operations();

        break;
    case 3:
        sortArray();
        operations();
        
        break;
    case 4:
        displayArray();
        operations();
        break;
    case 9:
        exit(0);
    default:
        printf("\nChoose either 1,2,3 or 4.");
        operations();
    }
}


int main(){
    createArray();
    operations();
    return 0;
}
