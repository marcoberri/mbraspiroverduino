#!/bin/sh
sudo raspistill -w 640 -h 480 -q 5 -rot 180 -o /tmp/pic.jpg -tl 10 -t 9999999 -th 0:0:0 -n &
sudo LD_LIBRARY_PATH=./ ./mjpg_streamer -i "input_file.so -f /tmp/ -n pic.jpg" -o "output_http.so -p 9000 -w ./www" &
