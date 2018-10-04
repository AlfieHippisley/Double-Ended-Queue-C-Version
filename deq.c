//
// FIle Name :          	deq.c
// Author : 	        	Alfie Hippisley
// Date Created :       	1/10/2018
// Date Last Modified : 	8/10/2018
//
// Purpose : Code to form the deq data structure operations for use in Assignment 1
//

#include "deq.h"
#include <stdlib.h>

// Function purpose :
// Initialise a new DEQ

// Parameters:
// qPtr - This is a pointer varible for the new DEQ that has been created

int initDEQueue(DEQueue **qPtr){

	// qPtr should contain the address for a DEQ pointer varible, if null, somehting has gone wrong
	if(qPtr = NULL){
		return NULL_PARAM;
	}

	// Before we initialise a new DEQ we must first check if one already exists in the location we are writing to
	if(*qPtr != NULL){
		return BAD_INIT_PARAM;
	}

	// Now that we know the location/pointer is valid lets allocate the memory
	(*qPtr) = (DEQueue*)malloc(sizeof(DEQueue));

	// Lets now check that the DEQ memory has been allocated correctly
	if((*qPtr) == NULL){
		return OUT_OF_MEMORY;
	}

	// Now that the queue has been created we can initalise fields
	(*qPtr) -> head = NULL;
	(*qPtr) -> tail = NULL;

	// Function completed with success
	return SUCCESS;
};

// Function purpose :
// Push data/nodes to the tail of the queue

// Parameters:
// qPtr - This is a pointer varible for the new DEQ that has been created
// data - This is the data to be stored in the queue (In this case an int)

int pushTail(DEQueue *qPtr, int data){

	// Firstly, lets check the pointer to the queue is valid
	if(qPtr == NULL){
		return NULL_PARAM;
	}

	// Now that we know the location/pointer is valid lets allocate the memory
	Node *newNode = (Node*)malloc(sizeof(Node));

	// Lets now check that the node memory has been allocated correctly
	if(newNode == NULL){
		return OUT_OF_MEMORY;
	}

	// Now that the node has been created we can initalise the fields
	newNode->data = data;
	newNode->next = NULL;

	// Now lets check to see if the queue is empty so we know how to join heads & tails
	if((qPtr-> head = NULL) && (qPtr-> tail = NULL)){

		// Queue must be empty so lets set the head and tail to be this new node
		qPtr-> head = newNode;
		qPtr-> tail = newNode;

		return SUCCESS;
	}

	// So... the Queue must not be empty, therefore we must add this node with others
	qPtr->tail->next = newNode;
	qPtr->tail = newNode;

}