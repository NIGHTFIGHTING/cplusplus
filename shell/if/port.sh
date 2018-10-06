#!/bin/bash
#Author: liuqi15 E-mail: liuqi15@baidu.com

port=$(nmap -sT 140.143.24.75 | grep tcp | grep http | awk '{ print $2 }')
echo $port
if [ "$port" == "open" ]
    then
        echo "$(date) httpd is ok"
else
    service httpd start > /dev/null 2>&1
    echo "$(date) httpd reboot!!"
fi
