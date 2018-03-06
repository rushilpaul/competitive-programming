#!/bin/bash

for i in `seq 1 100`; do
	echo Checking test case $i...
	./gen.py > in
	./correct < in > out1
	./WSITES01 < in > out2
	diff out1 out2
	if ! [[ $? -eq 0 ]]; then
		diff out1 out2
		break
	fi
	echo 'Correct'
done
