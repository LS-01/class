#!/bin/bash
function a(){
    return 12
}
a
echo $?

function aa(){
    echo 12
}
b=`aa`
echo $b
