#!/bin/bash
num=100
while [[ $num -ge 0 ]]; do
    echo ${num}
    num=$[ ${num} - 1 ]
done
