#!/bin/bash
if [ $# -eq 0 ]; then
	echo "No arguments supplied"
else
	first=true
	for i in $@
		do
			if [ "$first" = true ] ; then
				dir=$i
				if [ ! -d "../cpp_0$dir" ]; then
					mkdir ../cpp_0$dir
				else
					echo "Directory ../cpp_0$dir already exists"
				fi
				first=false
			else
				if [ ! -d "../cpp_0$dir/ex0$i" ]; then
					mkdir ../cpp_0$dir/ex0$i
				else
					echo "Directory ../cpp_0$dir/ex0$i already exists"
				fi
				touch ../cpp_0$dir/ex0$i/Makefile
				if [ -f "Makefile.txt" ]; then
					cat Makefile.txt > ../cpp_0$dir/ex0$i/Makefile
				else
					echo "Makefile.txt not found"
				fi
			fi
		done
fi