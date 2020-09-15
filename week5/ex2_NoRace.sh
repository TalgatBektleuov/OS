#!/bin/sh
if test ! -f Numbers2_noRace.txt
then
    echo 0 > Numbers2_noRace.txt
fi
if ln Numbers2_noRace.txt Numbers2_noRace.txt.lock
then
    for i in $(seq 1 10)
    do
        a=$(tail -n 1 < Numbers2_noRace.txt)
        expr $a + 1 >> Numbers2_noRace.txt
    done
    rm Numbers2_noRace.txt.lock
fi
# Here the race problem is handled by locking the file before entering the critical region
# After everything is done, we will unlock the file
