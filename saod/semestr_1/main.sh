#!/bin/bash

pattern='^[123]$'

if [[ ${#} -ne 1 ]]; then
        echo "ERROR: please enter 1 parameters"
else
        mod="$1"
        if ! [[ "$mod" =~ $pattern ]]; then
                echo "ERROR: please enter 1 or 2 or 3"
        else
                if [[ "$mod" == "1" ]]; then
                        str=""
                        while read p; do
                                str_tmp=$(echo "$p" | awk -F / '{print "/"$2"/"$3}')
                                #echo "$str_tmp"
                                if [[ "$str" != "$str_tmp" ]]; then
                                        str="$str_tmp"
                                        echo "delete: $str"
                                        rm -rf $str
                                fi
                        done < ../02/log.txt

                else if [[ "$mod" == "2" ]]; then
                        #dirs=($(find . -type d))
                        #for dir in  "${dirs[@]}"; do
                #               echo "dir: $dir"
                #       done
                        echo "OK"
                fi
        fi
fi


