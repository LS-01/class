#!/bin/bash

fliter_types=(mp4 avi gz zip tar)

function fliter(){
    file_name=$1
    type_name=`basename ${file_name} | rev | cut -d "." -f 1 | rev`
    for i in ${filter_types[@]};do
        if [[ ${type_name} == ${i} ]];then
            echo "Fliters On! ${file_name}"
            return 1
        fi
    done
}

function find_max_in_file(){
    if [[ ! -f $1 ]];then
        echo "$1 is not a r_file!"
        return
    fi
    fliter $1
    if [[ $? -eq 1 ]];then
        return 
    fi
    echo "Finding Max_String in file $1"
    words=`cat $1 | tr -s -c "a-zA-Z" "\n"`
    for i in ${words};do
        len_t=`echo -n ${i} | wc -c`
        if [[ ${len_t} -gt ${len_max} ]];then
            len_max=${len_t}
            max_string=${i}
            max_file=$1
        fi
    done
}

function find_max_in_dir(){
    for i in `ls -A $1`;do
        if [[ -d ${1}/${i} ]];then
            echo "${1}/${i} is a dir"
            find_max_in_dir ${1}/${i}
        else
            echo "${1}/${i} is a file"
            find_max_in_file ${1}/${i}
        fi
    done
}

