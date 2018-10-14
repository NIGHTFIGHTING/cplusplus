#/bin/bash

$(mkdir -p ./array)
$(touch ./array/{1..3}.txt)
dir=($(ls ./array))
for((i=0;i<${#dir[*]};++i))
do
    echo ${dir[i]}
done
