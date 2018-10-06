#/bin/bash
#Brief: 批量添加指定数量的用户
#Author: liuqi15 (E-mail: liuqi15@baidu.com)

read -p "Please input user name:" -t 30 name
read -p "Please input the number of users:" -t 30 num
read -p "Please input the password of users:" -t 30 pass

if [ ! -z "$name" -a ! -z "$num" -a ! -z "$pass" ]
    then
    y=$(echo $num| sed 's/^[0-9]*$//g')
    if [ -z "$y" ]
        then
            for ((i=1;i<=$num;i=i+1))
                do
                    echo $name$i, $pass
                    #useradd $name$i & >/dev/null
                    #echo $pass | passwd --stdin $name$i & /dev/null
                done
    fi
fi
