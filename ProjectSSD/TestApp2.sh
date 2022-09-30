#! /bin/bash

(for((var=0; var<30; var++))
do
	for((i=0; i<6; i++))
	do
		echo write $i 0xAAAABBBB
	done
done; echo exit) | ./Test	

(echo fullread; echo exit) | ./Test


(for((var=0; var<6; var++))
 do
 	echo write $var 0x12345678
done; echo exit) | ./Test

(for((var=0; var<6; var++))
 do
 	echo read $var
done; echo exit) | ./Test

