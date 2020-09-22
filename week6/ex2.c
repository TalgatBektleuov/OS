#include <stdio.h>
void swap(int *a, int *b){
  int t=*a;
  *a=*b;
  *b=t;
}
int main(void) {
  int n;
  scanf("%d",&n);
  int arr[100][5], arr2[100][5];
  int timeLine=0;
  for(int i=0;i<n;i++){
    scanf("%d %d",&arr[i][0], &arr[i][1]);
  }
  for(int i=0;i<n;i++){
    arr[i][2]=i;
    arr2[i][0]=arr[i][0];
    arr2[i][1]=arr[i][1];
    
  }
  printf("\n");
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      if(arr[i][0]>arr[i+1][0] && i!=n-1){
        for(int j=0;j<3;j++){
          swap(&arr[i][j], &arr[i+1][j]);
        }
      }
    }
  }

  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      if(arr[i][0]==arr[i+1][0] && arr[i][1]>arr[i+1][1] && i!=n-1){
        for(int j=0;j<3;j++){
          swap(&arr[i][j], &arr[i+1][j]);
        }
      }
    }
  }
  int c=1;
  while(c!=n){
    timeLine=timeLine+arr[c-1][1];
    for(int k=c;k<n;k++){
      for(int i=c;i<n;i++){
        if(timeLine>=arr[i][0] && timeLine>=arr[i+1][0] && arr[i][1]>arr[i+1][1] && i!=n-1){
          for(int j=0;j<3;j++){
            swap(&arr[i][j], &arr[i+1][j]);
          }
        }
      }
    }
    c++;
  }
  int completionTime[100], turnaroundTime[100], waitingTime[100];
  int totalTurnaroundTime, totalWaitingTime;

  completionTime[arr[0][2]]=arr[0][1];
  waitingTime[arr[0][2]]=0;
  turnaroundTime[arr[0][2]]=completionTime[arr[0][2]]-arr2[arr[0][2]][0];
  for(int i=1;i<n;i++){
    completionTime[arr[i][2]]=completionTime[arr[i-1][2]]+arr[i][1];
    waitingTime[arr[i][2]]=completionTime[arr[i][2]]-arr2[arr[i][2]][0]-arr2[arr[i][2]][1];
    turnaroundTime[arr[i][2]]=completionTime[arr[i][2]]-arr2[arr[i][2]][0];
  }
  printf("Process\tCompletionTime\tWaitingTime\tTurnaround Time\n");
  for(int i=0;i<n;i++){
    printf("P%d\t\t %d\t\t%d\t\t\%d\n",i+1,completionTime[i],waitingTime[i],turnaroundTime[i]);
  }
  // for(int i=0;i<n;i++){
  //   printf("%d %d\n",arr[i][0], arr[i][1]);
  // }

  return 0;
}

