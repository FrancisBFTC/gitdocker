cls
ECHO OFF
::mingw32-make.exe -f "C:\gitdocker\Makefile.win" all
g++.exe -std=c++11 -c main.cpp -o main.o
g++.exe -std=c++11 main.o -o ../gitd/GitDocker.exe