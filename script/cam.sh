#!/bin/sh
LD_LIBRARY_PATH=./ ./mjpg_streamer -i "input_raspicam.so -fps 5 -rot 180" -o "output_http.so -w ./www"