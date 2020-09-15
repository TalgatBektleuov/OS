#!/bin/sh
if test ! -f Numbers.txt
then
	echo 0 > Numbers.txt
fi
#loop for 10 times
for i in $(seq 1 10):
do
	a=$(tail -n 1 Numbers.txt)
	expr $a + 1 >> Numbers.txt
done
#The part of the program where the shared memory of two files or two processes is accessed is called the critical region
#Here, race problem is not handled anyhow. 


