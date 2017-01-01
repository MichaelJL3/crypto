#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "prime.h"
#include "cuber.h"
#include "hex.h"

typedef union{
	char *p;
	struct{
		unsigned short w1: 16;
		unsigned short w2: 16;
		unsigned short w3: 16;
		unsigned short w4: 16;
	}bits;
}str;

int main(){
	long sqrt_hx[8];
	long cuber_hx[64];
	short total_p=64;
	short inc=1;
	short is_prime=3;
	short first_eight=total_p-7;
	unsigned char inp[65];

	sqrt_hx[0]=(hex(sqrt(2)))>>20;
	cuber_hx[0]=(hex(cube(2)))>>20;

	while(inc<total_p){
		if (prime(is_prime)){
			if(inc<8){
				sqrt_hx[inc] = (hex(sqrt(is_prime)))>>20;
			}
			cuber_hx[inc] = (hex(cube(is_prime)))>>20;
			inc++;
		}
		is_prime+=2;
	}

	inc=0;
	for(; inc<64; inc++){
		printf("PRIME # %d, %x\n", inc, cuber_hx[inc]);
	}

	puts("");
	inc=0;
	for(; inc<8; inc++){
		printf("PRIME # %d, %x\n", inc, sqrt_hx[inc]);
	}

	printf("\nENTER INPUT: ");
	scanf("%s", &inp);
	printf("\nMsg = %s\n", inp);

	inc=0;
	while(inp[inc]!=0)
		inc++;

	inp[inc]=1;
	inp[inc+1]=0;

	while((inc*8)%512!=448){
		inp[inc+1]=0;
		inc++;
	}

	printf("%d\n", inc);
	printf("%x\n", inp[0]);
	str w;
	w.p=&(inp[0]);
	printf("%x\n", w.p);
	printf("%x\n", w.bits.w1);
	printf("%x\n", w.bits.w2);
	printf("%x\n", w.bits.w3);
	printf("%x\n", w.bits.w4);

	inc=16;
	for(; inc<63; inc++){
		
	}


	inc=0;
	for(; inc<63; inc++){

	}

	return 0;
}