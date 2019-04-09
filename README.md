# CPSC_351_Assignment_1

CPSC 351- Section 2(13643)
Spring 2019


Group Members:
      James Ku
			894841865
      thatoneddrguy@csu.fullerton.edu

      Bony Roy
			898161054
      broy91@csu.fullerton.edu




Purpose: Use shared memory, and message queues in order to implement an application which
		 synchronously transfers files between two processes.


Programming Language Used:
		 C++

Extra Credit:
		 Not Implemented

File Names:
	  p1-[userid].tar
		sender.cpp
			CPP File that sends the message from the text file to the receive model
		recv.cpp
			CPP File that receives the message from the sender.cpp
		keyfile.txt
			Text File that holds a "string" type of message
		msg.h
			Header File that holds a struct of the message relayed through message queues
		Makefile
			Makefile to build both the sender and receiver files

To run our program:
	compile: make
	execute: ./sender <FILE NAME>
		 ./recv



Sources: Yun Tian, Skeleton Code posted on Titanium
		 Message Queues: http://beej.us/guide/bgipc/output/html/multipage/mq.html
		 Shared Memory: http://beej.us/guide/bgipc/output/html/multipage/shm.html
