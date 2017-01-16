#!/bin/bash

n=30
if [[ $# -eq 1 ]]; then
	n=$1
fi

for ((i=1;i<=$n;i++));
do
	./gen.py > in
	./sol < in > out2
	./chcinema < in > out1
	tester out1 out2 1 > /dev/null
	if [[ ! $? -eq 0 ]]; then
		echo -e "\nTest case failed:\n"
		cat in
		exit
	fi
	printf .
done

rm out1
rm out2
echo -e "\nAll $n test(s) passed successfully!"
