#/bin/bash

char=liuqi15

echo $char|wc -L
echo ${#char}
echo $(expr length $char)
echo $char|awk '{print length($0)}'
