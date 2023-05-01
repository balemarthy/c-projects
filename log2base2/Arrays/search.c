#include <stdio.h>

int search(int arr[], int N, int key) {
  assert(N >= 0);
  int i = 0;
  
  for(i=0; i<N; i++) {
    if(arr[i] == key)
      return 1;
  }
  return -1;
}

int main() {
  int N;
  
  scanf("%d", &N);
  int i, arr[N], key;
  
  for(i=0; i<N; i++)
    scanf("%d",&arr[i]);
  
  scanf("%d",&key);
  
  printf("%d\n",search(arr,N,key));
  return 0;
}
