# CPSC_351_Assignment_1

**_CPSC 351- Section 2(13643)_**
**Spring 2019**


**Group Members:**

	James I Ku
	894841865
	thatoneddrguy@csu.fullerton.edu
    
	Esteban Montelongo
	888847456
	EstebanMontelongo@csu.fullerton.edu
	
	Bony Roy
	898161054
	broy91@csu.fullerton.edu
      
**Purpose:**
Use shared memory, and message queues in order to implement an application which synchronously transfers files between two processes.


**Programming Language Used:**	
	C++

**Extra Credit:**	
	Not Implemented
		 
 
**File Names:**	
	p1=[userid].tar
	sender.cpp
		CPP File that sends the message from the text file gto the receive model
	recv.cpp
		CPP File the receives the message from the sender.cpp
	keyfile.txt
		Text File that holds a "string" type of message. Sender will send this information to receiver.
	msg.h
		Header File that holds a struct of the message relayed through the message queues
	Makefile
		Makefile to build both the sender and receiver files

**To run our program:**	
	Compile: make
	execute: ./sender <FILE NAME>
		./recv



**Sources:** 	
	Professor Yun Tian, Skeleton Code posted on Titanium
		Message Queues: http://beej.us/guide/bgipc/output/html/multipage/mq.html
		Shared Memory: http://beej.us/guide/bgipc/output/html/multipage/shm.html
