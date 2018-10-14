#/bin/bash

name=(liuqi15 wangshuai23)

for((i=0;i<${#name[*]};++i))
do
    if [ ${#name[i]} -ge 6 ];then
        echo ${name[i]}
    fi
done
