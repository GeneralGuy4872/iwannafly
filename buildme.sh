#!/bin/sh
cp defaults.ini conf.ini
cc main.c -g -lX11 -lXaw -lXt -lm -lGL -lGLU
