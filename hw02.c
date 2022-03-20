#include <stdio.h>

int changeBase(int hit, int base, int *outCount){
	int ihit;
	if(hit == 'O'){
		*outCount += 1;
		if(*outCount ==3){
			base = 0;
		}
	}
	else if(hit == 'H'){
		base = 0;
	}
	else{
		ihit = hit - '0';
		//printf("hit = %d\n", ihit);
		base = base << ihit;
		base = base & 7;
		base = base | (1<<(ihit-1));
		//printf("base = %d\n", base);
	}

	return base;
}

void printBase(int base){
	int temp, len=0;
	while(base != 0){
		temp = base & 1;
		printf("%d\n", temp);
		base = base >> 1;
		len += 1;
	}
	while(len<3){
		printf("0\n");
		len += 1;
	}
}

int main(){
	int i, base, outCount=0;
	char hit;
	for(i=0 ;i<5 ;i++){
		scanf("%c", &hit);
		getchar();
		base = changeBase(hit, base, &outCount);
	}
	//printf("base = %d\n", base);
	printBase(base);
	return 0;
}
