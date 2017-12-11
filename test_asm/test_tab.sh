#!/bin/bash

rm asm_our/*.cor asm_zaz/*.cor diff/*.txt

for champion in `ls *.s`
do
	echo _____________________________________________
	echo Champion : $champion
	echo "____ O U R      A S M ____"
	./$1 $champion
	mv *.cor asm_our
	echo "____ Z A Z      A S M ____"
	./$2 $champion
	mv *.cor asm_zaz
done

for champion in `ls asm_our/*.cor`
do
	hexdump $champion > $champion.txt
done

mv asm_our/*.txt diff

for champion in `ls asm_zaz/*.cor`
do
	hexdump $champion > $champion-zaz.txt
done

mv asm_zaz/*.txt diff

i=0
j=0

nb_diff=($(ls diff | wc -w))
let 'nb_diff = nb_diff / 2'

array=($(ls diff/*.txt))

for j in `seq 1 $nb_diff`
do
	echo diff ${array[i]} --------- ${array[i+1]} 
	diff -q ${array[i]} ${array[i+1]}
	let 'i += 2'
done
