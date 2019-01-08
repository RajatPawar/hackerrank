#!/bin/bash

for i in `hostips`; do

if [["$i" -eq "22.33.112.12"]]; then
continue
fi

ssh root@$i 'echo 22.147.90.20  time1.net.africa >> /etc/hosts';
echo -e "\nDone at $i";
done
