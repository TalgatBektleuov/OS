#include <stdlib.h>
#include <stdio.h>

int* my_realloc(int *arr, int old_size, int new_size){
  int *new_arr=malloc(new_size*sizeof(int));
  if(old_size<=new_size){
    for(int i=0;i<old_size;i++){
        new_arr[i]=arr[i];
    }
  }
  else{
    for(int i=0;i<new_size;i++){
        new_arr[i]=arr[i];
    }
  }
  free(arr);
  return new_arr;

}
int main(){
	
	printf("Enter original array size:");
	int n1;
	scanf("%d",&n1);
	
	int* a1 = malloc(n1 * sizeof(int));
	int i;
	for(i=0; i<n1; i++){
	
		a1[i] = i;
		printf("%d ",a1[i] );
	}


	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	a1 = my_realloc(a1,n1, n2*sizeof(int));

	for(i=0; i<n2;i++){
		
		printf("%d ",a1[i]);
	}
	printf("\n");

	return 0;
}

