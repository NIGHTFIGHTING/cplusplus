#/bin/bash

echo $1

#awk特点
#文本与数据处理工具
#统计,制表...
#1.awk行处理与格式
#2.内嵌参数应用
#3.内嵌程序应用

#awk一次处理一行内容
#对每行可以切片处理
#命令格式:awk [options] 'command' file(s)
#脚本格式 awk -f awk-script-file file(s)
#基本格式,扩展格式
#command:pattern { awk操作命令 }
#1.pattern:正则表达式;逻辑判断式
#2.操作命令:内置函数:print,printf,getline;
#           指令控制:if...else;while


#awk内置参数使用
#awk内置参数:分隔符
#options:-F field-separator(默认为空格)
#awk -F ':' '{ print $3}' /etc/passwd

#NR:每行的记录号
#NF:字段数量变量
#FILENAME:正在处理文件名
awk -F ':' '{ print NR,NF,FILENAME}' /etc/passwd

#显示/etc/passwd每行的行号,每行的列数,对应行的用户名(print/printf)
awk -F ':' '{printf("Line:%s Col:%s User:%s\n", NR,NF,$1)}' /etc/passwd

#显示/etc/passwd中用户ID大于100的用户行号和用户名(if...else...)
awk -F ':' '{ if($3>100) print "Line:"NR"\tUserID:"$3}' $1
awk -F ':' '$3>100{print $1,$3}' /etc/passwd

#command:pattern { awk操作命令}
#pattern:正则表达式;逻辑判断式
#awk逻辑~,!~匹配正则表达式
#==,!=,<,>:判断逻辑表达式
awk -F ':' '$1~/^m.*/{print "this is match pattern: "$1}' /etc/passwd

#bash count.sh filename
#统计文件中非空行数
#~ !~匹配正则表达式和不匹配正则表达式
awk 'BEGIN{ count=0 } $1 !~ /^$/ {count++}END{ print count}' $1

echo -e
#bash count.sh /etc/passwd
#统计显示/etc/passwd的账户总人数,统计显示UID大于100的用户名
awk -F ':' 'BEGIN{count=0}{ if($3 > 100) { name[count++]=$1; passwd[$1]=$3}}
END{ for(i=0;i<count;++i) { print i"\t"name[i]}; for(i in passwd) { print i,passwd[i]}}' $1

echo -e
#统计netstat -anp状态下为LISTEN和CONNECTED的连接数量
netstat -anp | awk '$6~/LISTEN|CONNECTED/{ sum[$6]++ }END{ for(i in sum) { print i"\t"sum[i]}}' 
