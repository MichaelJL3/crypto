/*
######################################################
File Name: Hex.c
Description: file converts double structure to hex
######################################################
*/
#include "hex.h"

long hex(double n){
	double_cast d;
	d.f = n;
	return d.parts.mantisa;
}