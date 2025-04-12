#include<stdio.h>

int lim=15;
int forms(int i){
	for(int j=1; j<lim; j++){for(int k=1; k<lim; k++){
		if(i + j + k == lim){
			if(i != j && i != k && j != i && j != k && k != i && k != j){
					printf("%d | %d | %d\n", i, j, k);
				}
			}
		}
	}
}

void main(){
	for(int i=1; i<lim; i++){forms(i); printf("\n");}
}
