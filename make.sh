#!/bin/bash
rm -rf build
mkdir build; cd build; cmake ..
make -j
if [ $? -eq 0 ];
then
	echo "compile passed"
else
	echo "compile failed"
	exit
fi

# -e enable \n escape char
echo -e "\n-------------->> start running ..."
./hello
status=$?

if [ $status -eq 0 ] 
then
	echo -e "\n--------------<< run passed"
else
	echo -e "\n--------------<< run error"
	echo $status
fi