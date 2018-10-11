#/bin/bash

for filename in `ls|grep "txt$"`
do
    mv $filename `echo $filename|cut -d . -f1`.gif
done

rename "gif" "txt" *.gif
