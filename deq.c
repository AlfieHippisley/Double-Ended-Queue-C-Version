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

// Parameters :
// qPtr - This is a pointer varible for the new DEQ that has been created

int initDEQueue(DEQueue **qPtr){

	// qPtr should contain the address for a DEQ pointer varible, if null, somehting has gone wrong
	if(qPtr == NULL){
		return NULL_PARAM;
	}

	// Before we initialise a new DEQ we must first check if one already exists in the location we are writing to
	if(*qPtr != NULL){
		return BAD_INIT_PARAM;
	}

	// Now that we know the location/pointer is valid lets allocate the memory
	(*qPtr) = (DEQueue*)myMalloc(sizeof(DEQueue));

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
// Push data/nodes to the head of the queue

// Parameters :
// qPtr - This is a pointer varible for the new DEQ that has been created
// data - This is the data to be stored in the queue (In this case an int)

int pushHead(DEQueue *qPtr, int data){

	// Firstly, lets check the pointer to the queue is valid
	if(qPtr == NULL){
		return NULL_PARAM;
	}

	// Now that we know the location/pointer is valid lets allocate the memory
	Node *newNode = (Node*)myMalloc(sizeof(Node));

	// Lets now check that the node memory has been allocated correctly
	if(newNode == NULL){
		return OUT_OF_MEMORY;
	}

	// Now that the node has been created we can initalise the fields
	newNode -> data = data;
	newNode -> next = NULL;

	// Now lets check to see if the queue is empty so we know how to join heads & tails
	if((qPtr -> head == NULL) && (qPtr -> tail == NULL)){

		// Queue must be empty so lets set the head and tail to be this new node
		qPtr -> head = newNode;
		qPtr -> tail = newNode;

		return SUCCESS;
	}

	// Lets set the next reference of this node to the head
	newNode -> next = qPtr -> head;

	// Then we set the queue head to this node as it is infront
	qPtr -> head = newNode;

	return SUCCESS;

}

// Function purpose :
// Push data/nodes to the tail of the queue

// Parameters :
// qPtr - This is a pointer varible for the new DEQ that has been created
// data - This is the data to be stored in the queue (In this case an int)

int pushTail(DEQueue *qPtr, int data){

	// Firstly, lets check the pointer to the queue is valid
	if(qPtr == NULL){
		return NULL_PARAM;
	}

	// Now that we know the location/pointer is valid lets allocate the memory
	Node *newNode = (Node*)myMalloc(sizeof(Node));

	// Lets now check that the node memory has been allocated correctly
	if(newNode == NULL){
		return OUT_OF_MEMORY;
	}

	// Now that the node has been created we can initalise the fields
	newNode -> data = data;
	newNode -> next = NULL;

	// Now lets check to see if the queue is empty so we know how to join heads & tails
	if((qPtr -> head == NULL) && (qPtr -> tail == NULL)){

		// Queue must be empty so lets set the head and tail to be this new node
		qPtr -> head = newNode;
		qPtr -> tail = newNode;

		return SUCCESS;
	}

	// So... the Queue must not be empty, therefore we must add this node with others
	qPtr -> tail->next = newNode;
	qPtr -> tail = newNode;

	return SUCCESS;

}

// Function purpose :
// Pop a data/node from the head of the queue

// Parameters :
// qPtr - This is a pointer varible for the new DEQ that has been created
// dataPtr - This is a pointer varible to store the data being popped off the queue

int popHead(DEQueue *qPtr, int *dataPtr){

	// Firstly, lets check the pointer to the queue is valid
	if(qPtr == NULL){
		return NULL_PARAM;
	}

	// Then lets check the data pointer is not null
	if(dataPtr == NULL){
		return NULL_PARAM;
	}

	// And then check that this queue is not empty
	if((qPtr -> head == NULL) && (qPtr -> tail == NULL)){
		return POP_EMPTY_DEQ;
	}

	// We need to use a tempory pointer to store the current head of the queue 
	Node *nodeToBeRemoved = qPtr -> head;

	// We now also store the data currently being stored in that node
	*dataPtr = nodeToBeRemoved -> data;

	// Now we change the head to be the next node in the queue
	qPtr -> head = nodeToBeRemoved -> next;

	// Now we can safely remove the node from the queue
	nodeToBeRemoved -> next = NULL;
	nodeToBeRemoved -> data = 0;

	if(qPtr -> head == NULL){
		qPtr -> tail = NULL;
	}

	free(nodeToBeRemoved);

	return SUCCESS;
}

// Function purpose :
// To peek/get the value being stored at the head of the queue

// Parameters :
// qPtr - This is a pointer varible for the new DEQ that has been created
// dataPtr - This is a pointer varible to store the data being popped off the queue

int peekHead(DEQueue *qPtr, int *dataPtr){

	// FIrstly, lets check the pointer to the queue is valid
	if(qPtr == NULL){
		return NULL_PARAM;
	}

	// Then lets check the data pointer is not null
	if(dataPtr == NULL){
		return NULL_PARAM;
	}

	// And then check that this queue is not empty
	if((qPtr -> head == NULL) && (qPtr -> tail == NULL)){
		return PEEK_EMPTY_DEQ;
	}

	// Then lets go get the data from the head node
	*dataPtr = qPtr -> head -> data;

	return SUCCESS;
}

// Function purpose :
// To peek/get the value being stored at the tail of the queue

// Parameters :
// qPtr - This is a pointer varible for the new DEQ that has been created
// dataPtr - This is a pointer varible to store the data being popped off the queue

int peekTail(DEQueue *qPtr, int *dataPtr){

	// FIrstly, lets check the pointer to the queue is valid
	if(qPtr == NULL){
		return NULL_PARAM;
	}

	// Then lets check the data pointer is not null
	if(dataPtr == NULL){
		return NULL_PARAM;
	}

	// And then check that this queue is not empty
	if((qPtr -> head == NULL) && (qPtr -> tail == NULL)){
		return PEEK_EMPTY_DEQ;
	}

	*dataPtr = qPtr -> tail -> data;

	return SUCCESS;
}

// Function purpose :
// To free the memory currently being allocated for the queue

// Parameters :
// qPtr - This is a pointer varible for the new DEQ that has been created

int freeDEQueue(DEQueue *qPtr){

	// Check that the pointer to the queue is valid
	if(qPtr == NULL){
		return NULL_PARAM;
	}

	// While the head and tail are not NULL then the queue must have content
	while(qPtr -> head != NULL){

		// Get pointer to current head node
		Node *currentHead = qPtr -> head;

		// Set head to next node
		qPtr -> head = qPtr -> head -> next;

		// Free the current head
		free(currentHead);

	}

	// Free the memory for the queue itself
	free(qPtr);
}