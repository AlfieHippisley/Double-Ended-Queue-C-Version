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

	// The memory has been allocated correctly so now we can set fields
	(*qPtr) -> top = NULL;

	// Function completed with success
	return SUCCESS;
};