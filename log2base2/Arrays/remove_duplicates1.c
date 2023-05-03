#include <stdio.h>

int rmDuplicates(int arr[], int n) {
    
    int i = 0;
    int j = 0;
    int arr2[n];
    
    if((n == 0) || (n == 1)) return n;
    
    for(i=0; i<n; i++) {
        if(arr[i] != arr[i+1]) {
            arr2[j] = arr[i];
            j++;
        } 
    }
    
    arr[j] = arr[n-1];
    
    
    for(i=0; i<j; i++) {
        printf("%d, ",arr2[i]);
    }
    
    printf("\nsize-%d",j);
}

int main()
{
    int arr[7] = {1,1,1,3,3,5,5};
    
    rmDuplicates(arr, 7);

    return 0;
}
