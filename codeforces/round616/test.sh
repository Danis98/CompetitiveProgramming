#!/bin/bash
for fname in ./secret/*.in; do
    echo "$fname"
    cp $fname input.txt
    ./$1 > out.txt
    diff ${fname%.in}.ans out.txt
done
