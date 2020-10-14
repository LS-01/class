#!/bin/bash
sum=0
until [[ ${sum} -gt 100 ]]; do
    echo $sum
    sum=$[ $sum + 1 ]
done
