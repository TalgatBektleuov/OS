#include <stdio.h>
#include <stdlib.h>
int main(void) {
 	int n;
	scanf("%d",&n);

	//Create a new array of n1 ints
	int* arr = malloc(n * sizeof(int));
  for(int i=0; i<n; i++){
	
	  arr[i] = i;
	
	}
  for(int i=0; i<n; i++){
    printf("%d ",arr[i]);
	}
  if(arr!=NULL){
    free(arr);
  }
  return 0;
}
