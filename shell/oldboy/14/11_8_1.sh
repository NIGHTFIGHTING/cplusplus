#/bin/bash

COLOR='\E[47;30m'
RES='\E[0m'

for ((i=1;i<=9;++i))
do
    for ((j=1;j<=9;j++))
    do
        if [ $j -le $i ]
            then 
                echo -en "${COLOR}$i*$j=$(($i*$j))$RES "
        fi
    done
    echo 
done
