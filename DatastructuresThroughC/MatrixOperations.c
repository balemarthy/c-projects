/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX 3 

void create(int[3][3]);
void display(int[3][3]);
void matadd(int[3][3], int[3][3], int[3][3]);
void matmul(int[3][3], int[3][3], int[3][3]);
void transpose(int[3][3], int[3][3]);

int main()
{
    int mat1[3][3], mat2[3][3], mat3[3][3], mat4[3][3], mat5[3][3];
    
    printf("Enter elements of first array:\n");
    create(mat1);
    
    printf("Enter elements for second array:\n");
    create(mat2);
    
    printf("First Array:\n");
    display(mat1);
    
    printf("Second Array:\n");
    display(mat2);
    
    matadd(mat1, mat2, mat3);
    
    printf("After Addition:\n");
    display(mat3);
    
    matmul(mat1, mat2, mat4);
    
    printf("After Multiplication:\n");
    display(mat4);
    
    transpose(mat1, mat5);
    
    printf("Transpose of first matrix:\n");
    display(mat5);
    
    return 0;
}


