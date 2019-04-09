
#include <sys/shm.h>
#include <sys/msg.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "msg.h"    /* For the message struct */


/* The size of the shared memory chunk */
#define SHARED_MEMORY_CHUNK_SIZE 1000

/* The ids for the shared memory segment and the message queue */
int shmid, msqid;

/* The pointer to the shared memory */
void *sharedMemPtr;

/* The name of the received file */
const char recvFileName[] = "recvfile";


/**
 * Sets up the shared memory segment and message queue
 * @param shmid - the id of the allocated shared memory
 * @param msqid - the id of the shared memory
 * @param sharedMemPtr - the pointer to the shared memory
 */

void init(int& shmid, int& msqid, void*& sharedMemPtr)
{
	key_t key;
	if(key = ftok("keyfile.txt", 'a') == -1)
	{
		perror("ftok");
		exit(1);
	}

	/* TODO: Allocate a piece of shared memory. The size of the segment must be SHARED_MEMORY_CHUNK_SIZE. */
	if(shmid = shmget(key, SHARED_MEMORY_CHUNK_SIZE, 0666 | IPC_CREAT) == -1)
	{
		perror("shmget");
		exit(1);
	}

	/* TODO: Attach to the shared memory */
	sharedMemPtr = shmat(shmid, (void*)0, 0);
	if(sharedMemPtr == (void*) -1)
	{
		perror("shmat");
		exit(1);
	}

	/* TODO: Create a message queue */
	if(msqid = msgget(key, 0666 | IPC_CREAT) == -1)
	{
		perror("msgget");
		exit(1);
	}

	/* Store the IDs and the pointer to the shared memory region in the corresponding parameters */


	/* TODO: 1. Create a file called keyfile.txt containing string "Hello world" (you may do
 		    so manually or from the code).
	         2. Use ftok("keyfile.txt", 'a') in order to generate the key.
		 3. Use the key in the TODO's below. Use the same key for the queue
		    and the shared memory segment. This also serves to illustrate the difference
		    between the key and the id used in message queues and shared memory. The id
		    for any System V object (i.e. message queues, shared memory, and sempahores)
		    is unique system-wide among all System V objects. Two objects, on the other hand,
		    may have the same key.
	 */






}


/**
 * The main loop
 */
void mainLoop()
{
	/* The size of the mesage */
	int msgSize = 0;

	/* Open the file for writing */
	FILE* fp = fopen(recvFileName, "w");

	/* Error checks */
	if(!fp)
	{
		perror("fopen");
		exit(-1);
	}

    /* TODO: Receive the message and get the message size. The message will
     * contain regular information. The message will be of SENDER_DATA_TYPE
     * (the macro SENDER_DATA_TYPE is defined in msg.h).  If the size field
     * of the message is not 0, then we copy that many bytes from the shared
     * memory region to the file. Otherwise, if 0, then we close the file and
     * exit.
     *
     * NOTE: the received file will always be saved into the file called
     * "recvfile"
     */
		 message rcvMsg;
		 message sndMsg;


    msgSize=1;

	/* Keep receiving until the sender set the size to 0, indicating that
 	 * there is no more data to send
 	 */

	while(msgSize != 0)
	{

		if (msgrcv(msqid,&rcvMsg,sizeof(rcvMsg),SENDER_DATA_TYPE,0)==-1){
 		 perror("msgrcv");
 		 exit(1);
 	  }else{
 		 printf("Ready to receive data.\n");
 	  };
		msgSize=rcvMsg.size;
		/* If the sender is not telling us that we are done, then get to work */
		if(msgSize != 0)
		{
			/* Save the shared memory to file */
			if(fwrite(sharedMemPtr, sizeof(char), msgSize, fp) < 0)
			{
				perror("fwrite");
			}

			/* TODO: Tell the sender that we are ready for the next file chunk.
 			 * I.e. send a message of type RECV_DONE_TYPE (the value of size field
 			 * does not matter in this case).
 			 */
			 sndMsg.mtype=RECV_DONE_TYPE;
			 if(msgsnd(msqid, &sndMsg, 0, 0)==-1){
				 perror("msgsend");
	       exit(1);

			 }else{
				 printf("Ready for next file chunk.\n");
			 };
		}
		/* We are done */
		else
		{
			/* Close the file */
			fclose(fp);
		}
	}
}



/**
 * Perfoms the cleanup functions
 * @param sharedMemPtr - the pointer to the shared memory
 * @param shmid - the id of the shared memory segment
 * @param msqid - the id of the message queue
 */

void cleanUp(const int& shmid, const int& msqid, void* sharedMemPtr)
{
	/* TODO: Detach from shared memory */
	if(shmdt(sharedMemPtr) == -1)
	{
		perror("shmdt");
		exit(1);
	}
	/* TODO: Deallocate the shared memory chunk */
	if(shmctl(shmid, IPC_RMID, NULL) == -1)
	{
		perror("shmctl");
		exit(1);
	}
	/* TODO: Deallocate the message queue */
	if(msgctl(msqid,IPC_RMID,NULL) == -1)
	{
		perror("msgctl");
		exit(1);
	}
}

/**
 * Handles the exit signal
 * @param signal - the signal type
 */

void ctrlCSignal(int signal)
{
	/* Free system V resources */
	cleanUp(shmid, msqid, sharedMemPtr);
}

int main(int argc, char** argv)
{

	/* TODO: Install a singnal handler (see signaldemo.cpp sample file).
 	 * In a case user presses Ctrl-c your program should delete message
 	 * queues and shared memory before exiting. You may add the cleaning functionality
 	 * in ctrlCSignal().
 	 */
	if(signal(SIGINT, ctrlCSignal) == SIG_ERR)
	{
		perror("signal");
		exit(1);
	}
	
	/* Initialize */
	init(shmid, msqid, sharedMemPtr);

	/* Go to the main loop */
	mainLoop();

	/** TODO: Detach from shared memory segment, and deallocate shared memory and message queue (i.e. call cleanup) **/
	cleanUp(shmid, msqid, sharedMemPtr);
	return 0;
}
