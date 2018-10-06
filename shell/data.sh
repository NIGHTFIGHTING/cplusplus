#!/bin/bash
#Author liuqi15 (E-mail: liuqi5@baidu.com)

date=$(date +\%y\%m\d)
size=$(du -sh /etc)

echo "Data: $date!" > /tmp/dbinfo.txt
echo "Data size: $size" >> /tmp/dbinfo.txt
cd /tmp/
tar -zcf etc_$date.tar.gz /etc /tmp/dbinfo.txt &>/dev/null
rm -rf /tmp/dbinfo.txt
