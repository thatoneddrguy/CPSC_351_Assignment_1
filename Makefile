# CPSC 351 Makefile for Assignment 1

# This is the c++ compiler
CC = g++

# Compiler flags
CCFLAGS = -Wall -c -g

# Rule to make recv and sender
all:	sender recv

# Creating object code
recv:	recv.o
	$(CC) recv.o -o recv

sender:	sender.o
	$(CC) sender.o -o sender

# Used to compile the cpp files
recv.o:	recv.cpp
	$(CC) $(CCFLAGS) recv.cpp

sender.o:	sender.cpp
		$(CC) $(CCFLAGS) sender.cpp

# Removes files
clean:
	rm -rf *.o sender recv recvfile
