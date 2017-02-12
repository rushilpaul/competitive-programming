#!/bin/bash

for i in `seq 1 100`;
do
	echo "Generating test file $i..."
	./generate.py > in
	echo "Testing..."
#	java Main < in.txt > out.txt
	./a.out < in > out
	if [[ $? -ne 0 ]]; then
		echo "Runtime error for the below input!"
		cat in
		break
	fi
	./verify.py < out
	if [[ $? -ne 0 ]]; then
		echo "WA for the below input!"
		cat in
		break
	fi
	echo "OK"
done
