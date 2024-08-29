/*
 * myMemory.c
 *
 *  Created on: 29-Aug-2024
 *      Author: jondurrant
 */

#include "pico/stdlib.h"
#include <wolfssl/wolfcrypt/memory.h>





void *myMalloc(size_t n, void* heap, int type){

	return malloc(n);
}

void myFree(void *p, void* heap, int type){
	free(p);
}
void *myRealloc(void *p, size_t n, void* heap, int type){

	return realloc(p, n);
}
