#!/bin/bash

for i in `seq 1 100`; do
	echo -e "Testing $i..."
	./gen.py > in
	./GAMEBALL < in > out
	if ! [[ $? -eq 0 ]]; then
		echo "Something went wrong!"
		break
	fi

	./tester.py
	if ! [[ $? -eq 0 ]]; then
		echo "Incorrect!"
		break
	fi
done
