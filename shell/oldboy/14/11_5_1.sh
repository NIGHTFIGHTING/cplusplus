#!/bin/bash

for file in `ls *.jpg`
do
    mv $file `echo $file|sed 's/_finished//g'`
done

ls *.jpg | awk -F "." '{ print "mv",$0,$1"_finished."$2 }' | bash

#rename ".jpg" "_finished.jpg" *.jpg
#rename "_finished" "" *.jpg
