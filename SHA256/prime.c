/*
######################################################
File Name: Prime.c
Description: Source code for prime
	-checks if int is prime
######################################################
*/
#include <math.h>
#include "prime.h"

int prime(int i){
	short j=3;

	for(; j<sqrt(i)+1; j+=2)
		if(i%j==0)
			return 0;

	return 1;
}