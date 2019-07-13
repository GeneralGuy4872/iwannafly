#!/bin/sh
cp conf.ini old_conf.ini
cp defaults.ini conf.ini
touch date.tmp
touch date
if cc main.c -g -lX11 -lXaw -lXt -lm -lGL -lGLU; then
printf "12s/.*/" > date.tmp;
printf -- "- last segfault build : " >> date.tmp;
date "+%H:%M:%S %a %b %d %Y %Z" >> date.tmp;
else
printf "14s/.*/" > date.tmp;
printf -- "- last failed build : " >> date.tmp;
date "+%H:%M:%S %a %b %d %Y" >> date.tmp;
fi
tr '\n' '/' <date.tmp >date
printf "g" >> date
rm date.tmp
sed -i -f date README.md
rm date
