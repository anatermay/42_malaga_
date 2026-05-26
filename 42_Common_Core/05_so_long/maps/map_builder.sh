#!/bin/bash

if [ $# -eq 0 ]; then
	echo "No arguments supplied"
else
	for i in $@
		do
			touch "level_$i.txt"
			touch "level_$i.ber"
		done
fi