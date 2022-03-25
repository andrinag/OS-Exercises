#!/bin/bash/
#the following command returns the number of arguments
#hint $? will be 0 if there are no errors after any bash command
 
args=$#
if [ $args -lt 2 ]
then
	echo Usage sh T2.sh folder_path link.
	exit
fi
folder_path=$1
link=$2
#your implementation goes here
mkdir $folder_path
if [ $? == 0 ]; then
	ln -s $folder_path $link
fi
