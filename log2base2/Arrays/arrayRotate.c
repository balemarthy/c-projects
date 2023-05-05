#include <stdio.h>

void rightRotate(int arr[], int n) {
    
    int i = 0;
    int temp = arr[n-1];
    
    for(i=n-1; i>0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

void arrayRotate(int arr[], int n, int k)
{
    int i=0;
    
    for(i=0; i<k; i++) {
        rightRotate(arr, n);
    }
    
}

int main()
{
    int arr[] = {1,2,3,4};
    
    arrayRotate(arr, 4, 2);
    
    printf("%d %d %d %d\n",arr[0],arr[1],arr[2],arr[3]);
    
    return 0;
}
