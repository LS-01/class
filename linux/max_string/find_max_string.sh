#!/bin/bash

max_len_1=0
max_len_2=0
max_len_3=0

max_string_1=''
max_string_2=''
max_string_3=''

if [[ $# -lt 1 ]];then
    printf "Usage: %s file[...]\n" $0
fi

function find_max_string_in_one_file() {
    for i in `cat $1 | tr -s -c "a-zA-Z" " "`;do
        len=${#i}
        if [[ $len -ge ${max_len_1} ]];then
            max_len_3=${max_len_2}
            max_string_3=${max_string_2}
            max_len_2=${max_len_1}
            max_string_2=${max_string_1}
            max_len_1=$len
            max_string_1=$1" : "$i" "$len
        elif [[ $len -ge ${max_len_2} ]];then
            max_len_3=${max_len_2}
            max_string_3=${max_string_2}
            max_len_2=$len
            max_string_2=$1" : "$i" "$len
        elif [[ $len -ge ${max_len_3} ]];then
            max_len_3=$len
            max_string_3=$1" : "$i" "$len
        fi
    done
}

function view_files() {
    is_text=`file $1 | grep text | wc -l`
    is_directory=`file $1 | grep directory | wc -l`
    if [[ ${is_text} -gt 0 ]];then
        find_max_string_in_one_file $1
    elif [[ ${is_directory} -gt 0 ]];then
        for i in `ls -a $1`;do
            if [[ $i != "." && $i != ".." ]];then
                view_files $1"/"$i
            fi
        done
    fi
}

#for (( i=1; i<=$#; i++ ));do
#    echo "$i"
#done

for i in $*;do
#    echo ${i}
    view_files ${i}
done

echo $max_string_1
echo $max_string_2
echo $max_string_3
