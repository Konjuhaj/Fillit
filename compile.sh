#!/bin/sh
make
make re
make clean
./fillit test1 | cat -e
./fillit test2 | cat -e
./fillit test3 | cat -e
./fillit test4 | cat -e
./fillit test5 | cat -e
