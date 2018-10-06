#!/bin/bash
#Author: liuqi15 (E-mail: liuqi15@baidu.com)

rate=$(df -h | grep /dev/vda1 | awk  '{ print $5 }' | awk -F "%" '{print $1 }' )
rate=$(df -h | grep /dev/vda1 | awk  '{ print $5 }' | cut -d "%" -f1)
if [ $rate -ge 1 ]
    then
        echo "/dev/vda1 is null !!!"
fi
