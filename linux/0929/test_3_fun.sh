#!/bin/bash
age=$1
function _print_ {
    echo $1
    return
}

if [[ age -gt 18 ]]; then
    echo "> 18"
elif [[ age -le 18 ]]; then
    echo "<= 18"
fi

_print_ "hello, ls!"
