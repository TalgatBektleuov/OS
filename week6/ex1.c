#include <stdio.h>

int main(void) {
  int arrivalTime[100], executeTime[100];
  int n;
  int completionTime[100],waitingTime[100],turnaroundTime[100];
  float averageTurnaroundTime=0.0,AverageWaitingTime=0.0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d %d",&arrivalTime[i],&executeTime[i]);
  }

  completionTime[0]=executeTime[0]-arrivalTime[0];
  waitingTime[0]=0;
  turnaroundTime[0]=executeTime[0];
  averageTurnaroundTime=executeTime[0];
  for(int i=1;i<n;i++){
    if(completionTime[i-1]>=arrivalTime[i]){
      completionTime[i]=completionTime[i-1]+executeTime[i];
      
    }
    else{
      completionTime[i]=arrivalTime[i]+executeTime[i];
    }
    if(completionTime[i-1]-arrivalTime[i]>=0)
      waitingTime[i]=completionTime[i-1]-arrivalTime[i];
    else
      waitingTime[i]=0;
    turnaroundTime[i]=completionTime[i]-arrivalTime[i];
    averageTurnaroundTime=averageTurnaroundTime+turnaroundTime[i];
    AverageWaitingTime=AverageWaitingTime+waitingTime[i];
  }
  
  AverageWaitingTime=AverageWaitingTime/n;
  printf("Process completionTime WaitingTime TurnaroundTime\n");
  for(int i=0;i<n;i++){
    printf("P%d              %d           %d         %d\n",i,completionTime[i],waitingTime[i],turnaroundTime[i]);
  }
  printf("Turnaround time: %0f\nAverage turnaround time: %2f\nAverage waiting time: %f", averageTurnaroundTime,averageTurnaroundTime/n,AverageWaitingTime);
  return 0;
}

