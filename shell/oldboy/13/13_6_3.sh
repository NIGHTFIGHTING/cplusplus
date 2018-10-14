#/bin/bash

path=./server/scripts
MAIL_GROUP="1151378791@qq.com"
PAGER_GROUP="15304650195"
LOG_FILE="/tmp/web_check.log"

[ ! -d "${path}" ] && mkdir -p ${path}

function CheckDb() {
    echo 
}

function PAGER() {
    for PAGER_USER in `echo ${PAGER_GROUP}`
    do
        TITLE=$1
        CONTACT=${PAGER_USER}
    done 
}

function SendMsg() {
    echo $1 
    if [ $1 -ne 0 ];then
        RETVAL=1
        NOW_TIME=`date +"%Y-%m-%d %H:%M:%S"`
        echo ${NOW_TIME}
        SUBJECT_CONTENT="mysql slave is error,errorno is $2,${NOW_TIME}"
        echo -e "${SUBJECT_CONTENT}"|tee ${LOG_FILE}
    fi
}

function main() {
    while true
    do
        CheckDb
        kk
        SendMsg $?
        sleep 3
    done
}

main
