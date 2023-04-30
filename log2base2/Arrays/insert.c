
#include <stdio.h>
#include <assert.h>
  
void insert(int arr[], int N, int pos, int element)
{
    //Write your logic here
    assert(N >= 0);
    assert(pos >= 0);
    
    if(pos > N) return;
    int i = 0;
    
    for(i=N; i>pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = element;
    
}

//Don't change the below code
int main()
{
    int N;
    scanf("%d",&N);

    int i, arr[N], pos, element;

    for(i = 0; i < N; i++)
        scanf("%d",&arr[i]);

    scanf("%d%d",&pos, &element);

    insert(arr, N, pos, element);

    for(i = 0; i <= N; i++)
        printf("%d ",arr[i]);

    return 0;
}



