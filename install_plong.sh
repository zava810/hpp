#!/bin/bash

echo "installing cplong library."
echo "copying libplong.so in /usr/lib/ directory. may need your sudo permission"
sudo cp libplong.so /usr/lib/
echo "copying cplong.h in /usr/include/ directory. may need your sudo permission"
sudo cp cplong.h /usr/include/
echo "finished installing.  to use library, add '-lplong' as a flag as:"
echo "1. in c++ file add line : #include <cplong.h>"
echo "2. use g++ as: g++ -c file.cpp -lplong"
