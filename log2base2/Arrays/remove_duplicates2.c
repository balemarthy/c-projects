#include <stdio.h>

int rmDuplicates(int arr[], int n)
{
    int i = 0;
    int j = 0;
    
    if((n == 0) || (n == 1)) return n;
    
    for(i=0; i<n-1; i++) {
        if(arr[i] != arr[i+1]) {
            arr[j++] = arr[i];
        } 
    }
    arr[j++] = arr[n-1];
    
    return(j);
}

int main()
{
    int arr[3] = {1,1,1};
    
    rmDuplicates(arr, 3);

    return 0;
}
