/*
######################################################
File Name: Hex.h
Description: header file for hex conversion
	-for more info see hex.c
######################################################
*/

typedef union {
  double f;
  struct {
  	unsigned long mantisa : 52;
    unsigned int exponent : 11;
    unsigned int sign : 1;
  } parts;
} double_cast;

long hex(double n);