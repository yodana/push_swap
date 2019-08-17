#!/bin/bash

echo -e '\033[0mTesting validity a Hundred Times in a range from 0 to 4'
ERR=0

for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
		tab[i]=`./push_swap $ARG | wc -l`
done
let "a = 0"
for i in range {0..99}
    do
        let "a = a + ${tab[$i]}"
done

let "a = a / 100"

echo $a