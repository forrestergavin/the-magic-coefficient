// REFINED CODE
#include<stdio.h>

#define MAX 10000
#define LIM 880*16

int tally, val[MAX], qty[MAX]; char dir[MAX]; 
int id=0; int dat[LIM]; int ids[LIM];

void calcoef(int ort, int a, int b, int c, int d){
	int cal=(d*c)+(d*b)+(c*b)+(d*a)+(c*a)+(a*b);
	if(ids[cal]==id || ids[cal]==0){val[cal]=cal; qty[cal]++; ids[cal]=id;}
	switch(ort){
		case 1:
			dir[cal]='r'; //Row
			break;
		case 2:
			dir[cal]='c'; //Column
			break;
		case 3:
			dir[cal]='d'; //Diagonal
			break;
		default:
			dir[cal]='~'; //Invaild
	}
}

void searchcoef(int *s){
	for(int i=0; i<16; i+=4){
		calcoef(1, s[0+i], s[1+i], s[2+i], s[3+i]);
	} for(int j=0; j<4; j++){
		calcoef(2, s[0+j], s[4+j], s[8+j], s[12+j]);}
	calcoef(3, s[0], s[5], s[10], s[15]);
	calcoef(3, s[3], s[6], s[9], s[12]);
}

void readout(int *m){
	for(int i=0; i<MAX; i++){
		if(qty[i]<2){val[i]=0;};
		if(val[i]!=0){tally++; printf("tally: %d | quantity: %d | direction: %c | coefficient: %d\n", tally, qty[i], dir[i], val[i]);}}
}

void feed(char file[]){
	FILE *fptr=fopen(file, "r");
	char line[100];

	if(fptr!=NULL){
		int i=0; while(fgets(line, sizeof(line), fptr)){dat[i]=atoi(&line); i++;}
		fclose(fptr);
	} else{printf("\nERROR: Unable to open %s\n", file);};
}

void filereadin(){
	int step=16;
	int matrix[step];
	for(int i=0; i<LIM; i+=step){for(int j=0; j<step; j++){
			matrix[j]=dat[i+j];
		}; searchcoef(matrix); id++;
  }
}

int main(){
	/*int magic[]={
		2, 16, 13, 3,
		11, 5, 8, 10,
		7, 9, 12, 6,
		14, 4, 1, 15}; //A vaild magic square
	searchcoef(magic); readout(val);*/
	feed("squares.txt"); filereadin(); readout(val);
	return 0;
}
