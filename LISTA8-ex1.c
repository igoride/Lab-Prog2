#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "locale.h"

/***************************************************/
/*Nome:Igor Yoshimitsu Ide                         */
/*RA:181040387		    						   */
/*Exercicio 1--Lista-8-  						   */
/*Compilador: DevC 5.11							   */
/***************************************************/

int f (int x){
	
	if(x+1==1)
		return 1;
	
	return 3 * f(x-1)+1;

}

int GC(int n){
	
	int x, i, c;

	for(i=1; i<=n; i++){
		
		x = f(i);
		
		if(x>=n){
			
			c = x-2;
		
			break;
		
		}
	
	}	
	
	return c;

}

void OH (int H[], int c, int n){
	
	int i;
	
	c = GC(n);

	for(i=1; i<=c-1; i++){

		H[i]=f(c-i+1);
		
	}

}



void ShellSort(int *v, int n){

	//com 3 ciclos e h={4,3,1}
	
	int i, j, H, c, x, k, h[500];
	
	c = GC(n);
	
	OH(h,c,n);
	
	printf("\n C: %d\n", c);
	
	for(i=0; i<c-1; i++){
		
		printf("h [%i]: %d\n", i, h[i]);
	
	}
	for(k=0; k<c; k++){
		
		H = h[k];	
		
		for(i=H; i<n; i++){
			
			x=v[i];
			
			for(j=i-H; j>=0 && x<v[j]; j=j-H){
			
				v[j+H]=v[j];
			
			}
			
			v[j+H]=x;
		
		}
	
	}

}

void scanv (int n, int *p){
	
	int i;
	
	for(i=0; i<n; i++){
		
		printf("[%i]:", i+1);
		scanf("%i", p+i);
	
	}

}

void printv (int n, int *p){
	
	int i;
	for(i=0; i<n; i++){
		
		printf("%d  ", *(p+i));
	
	}

}

int main(){
	
	int n;
	
	printf("Digite o tamanho do vetor:");
	scanf("%d", &n);
	
	int v[n];
	
	scanv(n, v);
	
	ShellSort(v, n);
	
	printf("\n");
	
	printv(n, v);
	
}
