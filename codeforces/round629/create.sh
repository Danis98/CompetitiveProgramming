#!/bin/sh
if [ ! -z $1 ]
then
    mkdir $1
    cp template.cpp $1/$1.cpp
    touch $1/input.txt
    printf "all:\n\tg++ $1.cpp -o $1 -std=c++11 -DLOCAL" > $1/Makefile
    if [ ! -z $2 ]
    then
        cp test.sh $1/test.sh
        cp -r testcases/$2/data/secret $1/secret
    fi
fi
