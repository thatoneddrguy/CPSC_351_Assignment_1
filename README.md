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
		 
Markup :  - - - -

**File Names:**	
   Markup : 1. p1=[userid].tar
   2. sender.cpp: CPP File that sends the message from the text file gto the receive model
   3. recv.cpp : CPP File the receives the message from the sender.cpp
   4. keyfile.txt: Text File that holds a "string" type of message. Sender will send this information to receiver.
   5. msg.h: Header File that holds a struct of the message relayed through the message queues
   6. Makefile: Makefile to build both the sender and receiver files

Markup :  - - - -

**To run our program:**	
    
    1. Download tar files.
    2. Unzip files.
    3. Open terminal in directory where files are located.
    4. In terminal type make and press enter.
    5. Sender: open termimal in directory that contains the sender file. run : type ./sender keyfile.txt, press enter.
    6. Reciver: open new terminal in directory containing file. run: type ./recv, press enter.
    7. If no errors occur, type ./main to execute program.



**Sources:** 	
	Professor Yun Tian, Skeleton Code posted on Titanium and relevant links posted in document.
