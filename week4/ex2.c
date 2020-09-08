#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    for (int i = 1; i <= 5; i++) {
    fork();
      
  }
  sleep(5);
  /*
     When I run the program with for loop for 3 times, it showed me this:
    [3] 3632
    [2]+ ./ex3_o &
    after pstree command in ubuntu, I got this:
    init─┬─init───bash─┬─ex3_o
     │             ├─nano
     │             └─pstree
     └─{init}

    [2]+  Stopped                 ./ex3_o
    [3]   Done                    ./ex2_o

    After that, I changed my for loop to run it 5 time, and I got this:
    [3] 3653
    [2]+ ./ex3_o &
    after pstree command in ubuntu, I got this:
    init─┬─init───bash─┬─ex3_o
     │             ├─nano
     │             └─pstree
     └─{init}

[2]+  Stopped                 ./ex3_o
[3]   Done                    ./ex2_o1
  Conclusion: it does not work on my machine, but the result should depend on how many times we call function fork(). After each call, processes will create other processes.
  For example, after 3 forks there should be 8 processes; after 5 forks there should be 32 processes
  Finally, one can say that (Number of created processes)=2^(number of forks)
  */
    
  return 0;
}
