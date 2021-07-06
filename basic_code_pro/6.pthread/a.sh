#!/bin/bash
#time bash a.sh 
for i in `seq 1 100`;do
    ./a.out | cut -d " " -f 3 | sort -n | uniq -c | awk '{print $1}' | sort -n -r | uniq -c
done
