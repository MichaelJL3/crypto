#include <stdlib.h>
#include <stdio.h>

//INDEX OF COINCIDENCE FUNCTION
double ic(int c, char **str, int len, char alpha[], int N, int start){
	int n, sum=0, j, i=0;
	double total=0;
	for(; i<c; i++){
		j=0;
		n=0;
		for(; j<len; j++){
			str[start][j] = tolower(str[start][j]);
			if(alpha[i]==str[start][j])n++;
		}
		sum+=(n*(n-1)); 
	}
	total=N*(N-1);
	total=total/c;
	total=sum/total;
	return total;
}

//MUTUAL INDEX OF COINCIDENCE	
double mic(){
	return 0;
}

//SUBSTRINGS BASED ON KEY VALUE
void substring(char string[], int key, int start, int len, char **str){
	int place = start;
	int i = 0;
	for(; i<len; i++){
		str[start][i]=string[place];
		place+=key;
	}
}

/*int[] cf(){
	int[] fact;
	return fact;
}

//KASISKI TESTING FOR KEY
int[] key(){
	return cf();
}*/

int main(){
	char alpha[]={"abcdefghijklmnopqrstuvwxyz"};
	int c = sizeof(alpha)/ sizeof(alpha[0])-1;

	char string[]={"WERXEHJVYSOSPKMUVCOGSIXFUFLTHTVYCBTWPTMCLHTRGCMGQEAGRDVFEGTDJPFP"
				   "WPGVLIASCSGABHAFDIASEFBTVZGIIIHDGIDDKAVYCCXQGJQPKMVIYCLTQIKPMWQE"
				   "QDYHGEMCTPCKRAXTKVJSPWVYJXMHNVCFNWRDCCMVQNCKXFVYCSTBIVPDYOEFBTVZ"
				   "GIIQXWPXAPIHWICSUMVYCTGSOPFPLACUCXMSUJCCMWCCRDUSCSJTMCEYYCZSVYCR"
				   "KMRKMVKOJZABXHJFBXGGVRLIEMKWLTXRDV"};

	int orig_len = sizeof(string)/ sizeof(string[0])-1;

	int i=0, key=6;
	int rem = orig_len % key;
	int len = orig_len / key;
	int hold = len;
	char **str;

	str = malloc(key * sizeof *str);
	for(i=0; i<key; i++){
		str[i]=malloc(len+1 * sizeof *str[i]);
	}

	i=0;
	for(; i<key; i++){
		if(rem>0){
			len++;
			rem--;
		}
		else{
			len=hold;
		}
		printf("%d ", len);

		substring(string, key, i, len, str);
		int j=0;
		for(; j<len; j++){
			printf("%c", str[i][j]);
		}
		
		double index = ic(c, str, len, alpha, orig_len, i);
		printf(" %f\n", index);

		len--;
	}

	i=0;
	for(; i<key; i++){
		free(str[i]);
	}
	free(str);

	return 0;
}
