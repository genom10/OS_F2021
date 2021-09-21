#!/bin/bash

file=ex2
loop=true

if ! [ -f $file ];then
	echo $file created
	echo "1" >> $file
fi

#Race condition manifested itself right away resulting in multiple twos, threes, and so on.
#It later occurs 2-5 times for each dezen of numbers. 
#Firstly it occured because both treads were scheduled next to each other,
#which resulted in race when their turn has come.
#However the later it gets the greater the gap in schedule between the threads, which resulted in less common races.
while : ; do
if ln $file $file.lock;then
	#***critical region begin***
	i=`cat $file | tail -n 1`
	echo $((i+1)) >> $file
	#***critical region end***
	echo appended $((i+1))
	rm $file.lock
	[ $loop = true ] || break
fi
done
