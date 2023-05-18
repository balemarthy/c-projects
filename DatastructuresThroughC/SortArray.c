/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX1 5
#define MAX2 7

int *arr;

int *create(int);
void sort(int *, int);
void display(int *, int);
int *merge(int *, int);

int main(void)
{
    int *a, *b, *c;
    
    printf("\nEnter elements for first array\n\n");
    a = create(MAX1);
    
    printf("\nEnter elements for second array:\n\n");
    b = create(MAX2);
    
    sort(a, MAX1);
    sort(b, MAX2);
    
    printf("\nFirst array: \n");
    display(a, MAX1);
    
    printf("\n\nSecond array:\n");
    display(b, MAX2);
    
    return 0;
}

/* creates array of given size, dynamically */
int *create(int size) {
    int *arr, i;
    
    arr = (int *)malloc(sizeof(int) * size);
    
    for(i=0; i<size; i++) {
        printf("Enter the element no. %d:", i+1);
        scanf("%d",&arr[i]);
    }
    
    return arr;
}

/* sorts array in ascending order */
void sort(int *arr, int size) {
    int i, temp, j;
    
    for(i=0; i<size; i++) {
        for(j=i+1; j<size; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] =  arr[j];
                arr[j] = temp;
            }
        }
    }
}

/* displays the contents of array */
void display(int *arr, int size) {
    int i;
    
    for(i=0; i<size; i++) {
        printf("%d\t", arr[i]);
    }
}
