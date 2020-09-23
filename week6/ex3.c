#include <stdio.h>
void swap(int *a, int *b){
  int t=*a;
  *a=*b;
  *b=t;
}
int main(void) {
  int n,q;
  scanf("%d %d",&n,&q);
  int arr[100][5], arr2[100][5];
  int timeLine=0;
  for(int i=0;i<n;i++){
    scanf("%d %d",&arr[i][0], &arr[i][1]);
  }
  for(int i=0;i<n;i++){
    arr[i][2]=i;
    arr2[i][0]=arr[i][0];
    arr2[i][1]=arr[i][1];
    arr2[i][2]=i;
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
  int overallBurstTime=0;
  for(int i=0;i<n;i++){
    overallBurstTime=overallBurstTime+arr[i][1];
  }
  int completionTime[100], turnaroundTime[100], waitingTime[100];
  float totalTurnaroundTime=0.0, totalWaitingTime=0.0;
  int c;
  while(overallBurstTime!=0){
    for(int i=0;i<n;i++){
      if(arr[i][1]>0 && q>=arr[i][1] && timeLine>=arr[i][0]){
        timeLine=timeLine+arr[i][1];
        overallBurstTime=overallBurstTime-arr[i][1];
        arr[i][1]=0;
        
      }
      else if(q<arr[i][1] && timeLine>=arr[i][0]){
        timeLine=timeLine+q;
        arr[i][1]=arr[i][1]-q;
        overallBurstTime=overallBurstTime-q;
        
      }
      if(arr[i][1]==0){
        completionTime[arr2[i][2]]=timeLine;
        turnaroundTime[arr2[i][2]]=completionTime[arr2[i][2]]-arr[arr2[i][2]][0];
        waitingTime[arr2[i][2]]=turnaroundTime[arr2[i][2]]-arr2[arr2[i][2]][1];
        arr[i][1]=-1;
        c=i;
      }
      if(arr[i][0]>timeLine && c!=i){
        
        i=-1;
      }
      if(arr[i][0]>timeLine && c!=i-1){
        
        i=-1;
      }
      if(arr[i][0]>timeLine && c==i-1){
        timeLine=timeLine+1;
        i--;
      }
    // printf("%d\n",timeLine);
    }
  }
  printf("Process\tCompletionTime\tWaitingTime\tTurnaround Time\n");
  for(int i=0;i<n;i++){
    printf("P%d\t\t\t %d\t\t\t\t%d\t\t\t\t\%d\n",i+1,completionTime[i],waitingTime[i],turnaroundTime[i]);
    totalWaitingTime=totalWaitingTime + waitingTime[i];
    totalTurnaroundTime=totalTurnaroundTime+turnaroundTime[i];
  }
  printf("Average waiting time: %f\nAverage turnaround time: %f",totalWaitingTime/n,totalTurnaroundTime/n);
  // for(int i=0;i<n;i++){
  //   printf("%d %d\n",arr[i][0], arr[i][1]);
  // }'


  //Let's look on the example of Shortest Job First
  // 14
// 0 1
// 0 1
// 0 1
// 3 1
// 3 2
// 3 3
// 7 3
// 7 2
// 7 1
// 13 1
// 13 2
// 13 3
// 17 1
// 17 2

/*SJF:
Process CompletionTime  WaitingTime Turnaround Time
P1           1              0               1
P2           2              1               2
P3           3              2               3
P4           4              0               1
P5           6              1               3
P6           9              3               6
P7           15             5               8
P8           12             3               5
P9           10             2               3
P10          16             2               3
P11          18             3               5
P12          24             8               11
P13          19             1               2
P14          21             2               4
Average waiting time: 2.357143
Average turnaround time: 4.071429

And now let's look on output of Round Robin algorithm, q=1:

Process CompletionTime  WaitingTime Turnaround Time
P1           1              0               1
P2           2              1               2
P3           3              2               3
P4           4              0               1
P5           7              2               4
P6           12             6               9
P7           20             10              13
P8           14             5               7
P9           11             3               4
P10          15             1               2
P11          21             6               8
P12          24             8               11
P13          18             0               1
P14          23             4               6
Average waiting time: 3.428571
Average turnaround time: 5.142857

As we can see because q is so low. Waiting time and turnaround of each process will increase. This is obvius because each process will not be able to finish very fastly due to quantum restriction. If we increase the quantum quantity, waiting time and turnaround time will decrease. Whereas SJF gives us opportunity to finish all tasks fastly with low waiting time and turnaround time. 

Now let's look on the FCFS algorithm: 
Process completionTime WaitingTime TurnaroundTime
P0              1           0         1
P1              2           1         2
P2              3           2         3
P3              4           0         1
P4              6           1         3
P5              9           3         6
P6              12           2         5
P7              14           5         7
P8              15           7         8
P9              16           2         3
P10              18           3         5
P11              21           5         8
P12              22           4         5
P13              24           5         7
Average turnaround time: 4.571429
Average waiting time: 2.857143

Average turnaround time and Average waiting time are higher than that of SJF algorithm. 

But overall performance is same for all cases. This is because they all finish at the same time.
*/
}
