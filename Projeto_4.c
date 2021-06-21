#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>
#include <locale.h>


typedef struct biggo{ 
    int high; 
	int low; 
} BigInt[100000]; 

void copia(BigInt num, BigInt auxiliar);
int create_array(BigInt num);
void print(BigInt num);
void Quick_h(BigInt num, int inicio, int fim);
void insertionSort(BigInt aux);
void Escrever_arq(BigInt num, int seed);


int main(){	
	struct timeval t1, t2, t3, t4;
	double ta, tb;
	BigInt num, auxiliar;
	int seed, aux;
	
	setlocale(LC_ALL, "Portuguese");
		
	seed=create_array(num);
	copia(num, auxiliar);
	
	gettimeofday (&t1, NULL);
	
	Quick_h(num, 0, 100000);
	
	gettimeofday (&t2, NULL);
	
	ta=(t2.tv_sec-t1.tv_sec)+((double)(t2.tv_usec-t1.tv_usec)/1000000);	
	printf ("\n Quick sort: %lf s\n", ta);
	
	gettimeofday (&t3, NULL);
	for(int i=0; i<100000; i++){
		for(int j=0; j<100000; j++){
		if(num[i].high == num[i+1].high){
			if(num[i].low > num[i+1].low){
			      aux=num[j].low;
                  num[j].low=num[j+1].low;
                  num[j+1].low=aux;
			}
		}
	    }
	}
    gettimeofday (&t4, NULL);
    
	tb=(t4.tv_sec-t3.tv_sec)+((double)(t4.tv_usec-t3.tv_usec)/1000000);	
	printf ("\n Quick sort + ordenar low: %lf s\n", tb+ta);	

	
	gettimeofday (&t1, NULL);
	insertionSort(auxiliar);
	gettimeofday (&t2, NULL);
	ta=(t2.tv_sec-t1.tv_sec)+((double)(t2.tv_usec-t1.tv_usec)/1000000);	
	printf ("\n Insertion sort: %lf s\n", ta);
	for(int i=0; i<100000; i++){
		for(int j=0; j<100000; j++){
		if(auxiliar[i].high == auxiliar[i+1].high){
			if(auxiliar[i].low > auxiliar[i+1].low){
			      aux = auxiliar[j].low;
                  auxiliar[j].low = auxiliar[j+1].low;
                  auxiliar[j+1].low = aux;
			}
		}
	    }
	}
	gettimeofday (&t4, NULL);
    
	tb=(t4.tv_sec-t3.tv_sec)+((double)(t4.tv_usec-t3.tv_usec)/1000000);	
	printf ("\n Insertion sort + ordenar low: %lf s\n", tb+ta);

	
	Escrever_arq(auxiliar, seed);
}

void Escrever_arq(BigInt num, int seed){
	
	int i, a;
	
	FILE *arq;
	arq = fopen("quick1.dat", "w");
    
	fprintf(arq,"seed : %d\n", seed);
	fprintf(arq," high     low\n", seed);
    for(i=0;i<100000;i++){
    	if(num[i].high == 0 ){
			fprintf(arq," %d \n", num[i].low);
		}else fprintf(arq," %d             %d \n", num[i].high, num[i].low);
	}
	
	fclose(arq);

}

void insertionSort(BigInt aux) {
   int valueToInsert;
   int holePosition;
   int i, a, j;
   
   for(i=1; i<100000; i++) { 
	
      valueToInsert=aux[i].high;
		
      holePosition = i;
		
      while (holePosition > 0 &&  aux[holePosition-1].high > valueToInsert) {
          aux[holePosition].high =  aux[holePosition-1].high;
         holePosition--;
      }

      if(holePosition != i) {

         
         aux[holePosition].high = valueToInsert;
      }
		
   }  

}

void Quick_h(BigInt num, int inicio, int fim){
   
   int pivo, aux, i, j, meio, aux2;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = num[meio].high;
  
   do{
      while (num[i].high < pivo) i = i + 1;
      while (num[j].high > pivo) j = j - 1;
      
      if(i <= j){
         aux = num[i].high;
         aux2 = num[i].low;
         num[i].high = num[j].high;
         num[i].low = num[j].low;
         num[j].low = aux2;
         num[j].high = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick_h(num, inicio, j);
   if(i < fim) Quick_h(num, i, fim);   
    
}

void copia(BigInt num, BigInt auxiliar){
	
	int i;
	
	for(int i=0; i<100000; i++){
    	auxiliar[i].high = num[i].high;
    	auxiliar[i].low = num[i].low;
	}
}

void print(BigInt num){
	
	int i;
	
	for(i=0;i<100000;i++){
		if(num[i].high == 0 ){
			printf("\n\n%d :   %d ", i, num[i].low);
		}
		printf("\n\n%d :   %d%d ", i, num[i].high, num[i].low);
	}
	
}

int create_array(BigInt num){
    
	int i, seed;

    puts("Qual o valor da semente de geração aleatória (entre 0 e 1000)?");
    scanf("%d",&seed);
    srand(seed);
    
    for (i=0; i < 100000; i++)
       num[i].high = rand( )%1000000000;

    for (i=0; i < 100000; i++)
       num[i].low = rand( )%1000000000;
       
    return seed;
} 
