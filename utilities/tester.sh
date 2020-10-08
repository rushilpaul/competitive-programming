#!/bin/bash

while true
do
	./gen.py > in
	java Codechef < in > correct
	java ELOMAX < in > out
	diff correct out
	if [ $? != 0 ]
	then
		break
	fi
done
