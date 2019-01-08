#!/bin/bash

for i in `hostips`; do

if [["$i" -eq "22.33.112.12"]]; then
continue
fi

sed -i '$ d' /etc/hosts
echo -e "\nDone at $i";
done
