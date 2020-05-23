mkdir $1
touch $1/$1.cpp
touch $1/input.txt
printf "all:\n\tg++ $1.cpp -o $1 -std=c++11 -DLOCAL" > $1/Makefile
