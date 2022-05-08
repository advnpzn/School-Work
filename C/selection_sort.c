// Selection sort using pointers in C language.
#include <stdio.h>


void print_array( int *arr)
{
    for (int i = 0; i < sizeof(arr); i++)
    {
        printf("%d\n", *(arr + i));
    }
}


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selection_sort(int *arr)
{
    int min_index;
    int length = sizeof(arr);
    for (int i = 0; i < length - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (*(arr + j) < *(arr + min_index)) 
            {
                min_index = j;
            }
        }
        
        if (min_index != i)
        {
            swap(arr + i, arr + min_index);
        }
    }
}


int main(int argc, char const *argv[])
{
    int arr[] = {1, 5, 2, 3, 9, 7, 6, 8};
    
    selection_sort(arr);
    print_array(arr);

    return 0;
}
