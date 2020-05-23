for i in `seq 1 $1`;
do
	mkdir $i
	cp template.cpp $i/$i.cpp
	touch $i/input.txt
done
