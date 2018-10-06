#!/bin/bash
#Author: liuqi15 (E-mail: liuqi15@baidu.com)

read -p "Please input a filename:" file

if [ -z $file ]
    then
        echo "Error, please input a filename"
        exit 1
elif [ ! -e "$file" ]
    then
        echo "Your input is not a file!"
        exit 2
elif [ -f $file ]
    then
        echo "file is a regular file!"
elif [ -d $file ]
    then
        echo "file is a directory!"
else
    echo "file is an other file!" 
fi
