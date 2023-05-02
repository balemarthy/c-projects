
#include<stdio.h>
#include<assert.h>
  
void remove_mid(int arr[], int N)
{
    //Write your logic here
    assert(N >= 2);
    int mid = 0;
    if(N%2) {
        mid = N/2;
    } else {
        mid = N/2;
        mid = mid-1;
    }
    int i = 0;
    
    for(i=mid; i<N; i++) {
        arr[i] = arr[i+1]; 
    }
}

//Do not edit the below code
int main()
{
    int N;

    scanf("%d",&N);

    int i, arr[N];

    for(i = 0; i < N; i++)
        scanf("%d",&arr[i]);

    remove_mid(arr,N);

    for(i = 0; i < N-1; i++)
        printf("%d ",arr[i]);

    return 0;
}



