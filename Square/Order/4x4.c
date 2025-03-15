/* THIS FILE DOESN'T INCLUDE FILE READING */
#include<stdio.h>

#define MAX 900 // Max thinkable magic coefficient for a 4x4 magic square

void calculateterm(int a, int b, int c, int d);
void checkforterms(int *m);
void print(int *m);
void indent(){printf("\n");}

int num=0; int value[MAX]; int amount[MAX];

void calculateterm(int a, int b, int c, int d){
	int out=(d*c)+(d*b)+(c*b)+(d*a)+(c*a)+(a*b); // 4x4 formula to calculate the magic coefficient
	value[out]=out; amount[out]++; // Input the number and it's amount it appears into the arrays value[] and amount[] accordingly
}

void checkforterm(int *m){
	for(int i=0; i<4; i++){calculateterm(m[0+(4*i)], m[1+(4*i)], m[2+(4*i)], m[3+(4*i)]);}; // Rows
	for(int i=0; i<4; i++){calculateterm(m[0+i], m[4+i], m[8+i], m[12+i]);}; // Columns
	calculateterm(m[0], m[5], m[10], m[15]); // Right diagonal
       	calculateterm(m[3], m[6], m[9], m[12]); // Left diagonal
}

void print(int *m){
	for(int i=0; i<MAX; i++){if(amount[i]==1){value[i]=0;}}; // Remove Duplicates
	for(int i=0; i<MAX; i++){if(value[i]!=0){num++; printf("tally: %d total: %d ", num, amount[i]); printf("coefficient: %d\n", value[i]);}}; // List the coefficients with quantity and count
}

void main(){
	int s4[]={
		2, 16, 13, 3,
		11, 5, 8, 10,
		7, 9, 12, 6,
		14, 4, 1, 15}; // A vaild 4x4 magic square
	checkforterm(s4); print(value);
}
