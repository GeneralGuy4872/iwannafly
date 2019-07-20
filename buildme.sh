#!/bin/sh
cp conf.ini old_conf.ini
cp defaults.ini conf.ini
if cc main.c -g -lX11 -lXaw -lXt -lm -lGL -lGLU -lncurses -lncursesw -lmenu -trigraphs; then
printf "12s/.*/" > date.tmp;
printf -- "- last faulty build : " >> date.tmp;
date "+%H:%M:%S %a %b %d %Y %Z" >> date.tmp;
else
printf "13s/.*/" > date.tmp;
printf -- "- last failed build : " >> date.tmp;
date "+%H:%M:%S %a %b %d %Y %Z" >> date.tmp;
fi
tr '\n' '/' <date.tmp >date
printf "g" >> date
rm date.tmp
sed -n '8,13p' README.md > README-old.md
sed -i -f date README.md
rm date
