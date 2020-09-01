#include <stdio.h>
void swap(int *a, int *b){
  int t=*a;
  *a=*b;
  *b=t;
}
void bubble_sort(int array[],int size){
  for(int i=0;i<(size)-1;i++){
    for(int i=0;i<(size)-1;i++){
      if(array[i]>array[i+1]){
        swap(&array[i],&array[i+1]);
      }
    }
  }

}
int main(){
  int arr[1000];
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  bubble_sort(arr,n);

  for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
  }
}
