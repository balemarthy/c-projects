/******************************************************************************

This program consolidates all the basic operations that can be done on array
datastructure

*******************************************************************************/
#include <stdio.h>

#define MAX 5

void insert(int *, int pos, int num);
void del(int *, int pos);
void search(int *, int num);
void reverse(int *);
void display(int *);

int main()
{
    int arr[5];
    
    insert(arr, 1, 11);
    insert(arr, 2, 12);
    insert(arr, 3, 13);
    insert(arr, 4, 14);
    insert(arr, 5, 15);
    
    printf("\nElements of Array: ");
    display(arr);
    
    del(arr, 5);
    del(arr, 2);
    printf("\nAfter deletion: ");
    display(arr);
    
    insert(arr, 2, 22);
    insert(arr, 5, 55);
    printf("\nAfter insertion: ");
    
    display(arr);
    reverse(arr);
    printf("\nAfter reversing");
    display(arr);
    search(arr, 222);
    search(arr, 666);
    
    return 0;
}

/* inserts an element num at given position pos */
void insert(int *arr, int pos, int num) {
    /* shift elements to right */
    int i;
    for(i=MAX-1; i>=pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[i] = num;
}

/* deletes an element from the given position pos */
void del(int *arr, int pos) {
    /* skip to the desired position */
    int i;
    for(i=pos; i<MAX; i++) {
        arr[i-1] = arr[i];
    }
    arr[i-1] = 0;
}

/* reverses the entire array */
void reverse(int *arr) {
    int i;
    for(i=0; i<MAX/2; i++) {
        int temp = arr[i];
        arr[i] = arr[MAX-1-i];
        arr[MAX-1-i] = temp;
    }
}

/* searches array for a given element num */
void search(int *arr, int num) {
    /* Traverse the array */
    int i;
    for(i=0; i<MAX; i++) {
        if(num == arr[i]) {
            printf("\nThe element %d is present at %d position",num, i+1);
            return;
        }
    }
    if(MAX == i) {
        printf("\nThe element %d is not present in the array", num);
    }
}

/* displays the contents of the array */
void display(int *arr) {
    /* traverse the entire array */
    int i;
    printf("\n");
    for(i=0; i<MAX; i++) {
        printf("%d\t", arr[i]);
    }
}
