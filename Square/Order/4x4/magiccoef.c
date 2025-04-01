// REFINED CODE WITH MEMORY LEAK, BUT SEEMS TO STILL WORK!
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000
#define LIM 880*16

int tally, id, *val, *qty, *out;
int dat[LIM];

void calcoef(int a, int b, int c, int d){
	int cal=(d*c)+(d*b)+(c*b)+(d*a)+(c*a)+(a*b);
	val[cal]=cal; qty[cal]++;
}

void searchcoef(int *s){
	for(int i=0; i<16; i+=4){
		calcoef(s[0+i], s[1+i], s[2+i], s[3+i]);
	} for(int j=0; j<4; j++){
		calcoef(s[0+j], s[4+j], s[8+j], s[12+j]);}
	calcoef(s[0], s[5], s[10], s[15]); calcoef(s[3], s[6], s[9], s[12]);
}


void reset(int *m){for(int i=0; i<MAX; i++){m[i]=0;}}

void readout(){
	for(int i=0; i<MAX; i++){
		if(qty[i]<2){val[i]=0; out[val[i]]=0;};
		if(val[i]!=0){printf("[%d, %d, %d]\n", id, qty[i], val[i]); out[val[i]]=val[i];}};
}

void complete(){
	printf("\n"); for(int j=0; j<MAX; j++){if(out[j]!=0){tally++; printf("[%d, %d]\n", tally, out[j]);}}
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
	val=(int*)malloc(MAX*sizeof(int));
	qty=(int*)malloc(MAX*sizeof(int));
	out=(int*)malloc(MAX*sizeof(int));
	for(int i=0; i<LIM; i+=step){for(int j=0; j<step; j++){
			matrix[j]=dat[i+j];
		}; searchcoef(matrix); readout(); id++;
			reset(val);
			reset(qty);
			printf("\n");
  	} complete(); free(val); free(qty);
	free(out);
}

int main(){
	/*int magic[]={
		2, 16, 13, 3,
		11, 5, 8, 10,
		7, 9, 12, 6,
		14, 4, 1, 15}; //A vaild magic square
	searchcoef(magic); readout(val);*/
	feed("squares.txt"); filereadin();
	return 0;
}
