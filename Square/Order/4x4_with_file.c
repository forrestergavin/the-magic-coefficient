/* WARNNING THE CODE IN THIS FILE IS NOT REFINED FOR NOW */
#include<stdio.h>
#include<stdlib.h>

#define MAX 900 // Max thinkable magic coefficient for a 4x4 magic square
#define LIM 880*16

void calculateterm(int a, int b, int c, int d);
void checkforterms(int *m);
void print(int *m);
void indent(){printf("\n");}

int num=0; int value[MAX]; int amount[MAX]; int cell[LIM];

void calculateterm(int a, int b, int c, int d){
	int out=(d*c)+(d*b)+(c*b)+(d*a)+(c*a)+(a*b); // 4x4 formula to calculate the magic coefficient
	value[out]=out; amount[out]++; // Input the number and it's amount it appears into the arrays value[] and amount[] accordingly
}

void reset(int *m){for(int i=0; i<MAX; i++){m[i]=0;}}

void checkforterm(int *m){
	for(int i=0; i<4; i++){calculateterm(m[0+(4*i)], m[1+(4*i)], m[2+(4*i)], m[3+(4*i)]);}; // Rows
	for(int i=0; i<4; i++){calculateterm(m[0+i], m[4+i], m[8+i], m[12+i]);}; // Columns
	calculateterm(m[0], m[5], m[10], m[15]); // Right diagonal
       	calculateterm(m[3], m[6], m[9], m[12]); // Left diagonal
}

void print(int *m){
	for(int i=0; i<MAX; i++){if(amount[i]<2){value[i]=0;}}; // Remove Duplicates
	for(int i=0; i<MAX; i++){if(value[i]!=0){num++; printf("tally: %d total: %d ", num, amount[i]); printf("coefficient: %d\n", value[i]);}}; // List the coefficients with quantity and count
	reset(amount);
}

void feed(char file[]){
	FILE *fptr=fopen(file, "r");
	char line[100];

	if(fptr!=NULL){indent();
		int i=0; while(fgets(line, sizeof(line), fptr)){cell[i]=atoi(&line); i++;}
		//for(int i=0; i<LIM; i++){if(cell[i]!=0){printf("%d ", cell[i]);};};
		indent(); fclose(fptr);
	} else{printf("\nERROR: Unable to open %s\n", file);};
}

void checkforterminfile(){
	int matrix[16];
	for(int i=0; i<(LIM/16); i+=16){for(int j=0; j<16; j++){
			matrix[j]=cell[i+j];
		}; checkforterm(matrix);
	};
}

void main(){
	int s4[]={
		2, 16, 13, 3,
		11, 5, 8, 10,
		7, 9, 12, 6,
		14, 4, 1, 15}; // A vaild 4x4 magic square
	//checkforterm(s4); print(value);
	//checkforterm(s4); print(value);
	feed("4x4_880.txt");
	checkforterminfile();
	print(value);
}
