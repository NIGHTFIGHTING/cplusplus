#/bin/bash
#Author: liuqi15 (E-mail: liuqi15@baidu.com)

ls *.sh > ls.log

for i in $(cat ls.log)
    do
        echo $i
    done

rm -rf ls.log
