#!/bin/bash
#Author: liuqi15 E-mail: liuqi15@baidu.com

date=$(date +%y%m%d)
echo $date
size=$(du -sh /etc)
echo $size

dbbak() {
    echo "Date is $date" > ./dbbak/db.txt
    echo "Size is $size" >> ./dbbak/db.txt
    tar -zcf db_$date.tar.gz ./dbbak/db.txt > /dev/null
    rm -rf ./dbbak
}

if [ -d ./dbbak ];then
    echo "dbbak is not null"
    dbbak
else
    echo "dbbak is null !!!"
    mkdir ./dbbak
    dbbak
fi 
