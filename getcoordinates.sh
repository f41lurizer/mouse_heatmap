#! /bin/bash

xrandr --current | sed '2q;d' | cut -f 4 -d ' ' | cut -f 1 -d '+' 
while :
    do
        xdotool getmouselocation | cut -f 1,2 -d ' '
        sleep 1
    done
