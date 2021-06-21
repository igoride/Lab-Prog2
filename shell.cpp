#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>


void shellSort(int *vet, int size) {
    int i, j, value;
 
    int h = 1;
    while(h < size) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < size; i++) {
            value = vet[i];
            j = i;
            while (j > h-1 && value <= vet[j - h]) {
                vet[j] = vet[j - h];
                j = j - h;
                for(int k=0; k<10;k++){
            	printf("%d ", vet[k]);
		    }puts("\n");
            }
            
            
            vet[j] = value;
            
        }
        
        h = h/3;
    }
}

int main(){
	int vet[10];
	vet[0]=4;
	vet[1]=9;
	vet[2]=8;
	vet[3]=2;
	vet[4]=3;
	vet[5]=5;
	vet[6]=1;
	vet[7]=8;
	vet[8]=6;
	vet[9]=7;
	
	shellSort(vet, 10);
	
	
}
