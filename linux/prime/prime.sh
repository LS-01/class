#!/bin/bash

array=(0 0)
sum_count=1000
sum=0

for ((i = 2; i <= sum_count; i++)); do
    if [[ ${array[${i}]} -eq 0 ]]; then
        array[0]=${array[0]}+1
        array[${array[0]}]=${i}
        sum=$[ ${sum} + ${i} ]
    fi
    for ((j = 1; j <= ${array[0]}; j++)); do
        index=$[ ${array[${j}]} * ${i} ]
        if [[ index -gt sum_count ]];then
            break
        fi
        array[index]=1
        if [[ $[ ${i} % ${array[${j}]} ] -eq 0 ]];then
            break
        fi
    done
done

echo ${sum}
