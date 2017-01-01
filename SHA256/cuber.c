/*
######################################################
File Name: Cuber.c
Description: Source code for cube root 
######################################################
*/
#include <math.h>
#include "cuber.h"

double cube(int n){
	short i=0;
	short size=2*n+1;
	double val=1;

	for(; i<size; i++){
		val=val-(pow(val, 3)-n)/(3*pow(val, 2));
	}

	return val;
}
