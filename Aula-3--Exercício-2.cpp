/******************************************************************/
/* Nome : Igor Yoshimitsu Ide                                     */
/* RA : 181040387                                                 */
/* Exercício-Progama 2 -- repetiçao de x no vetor de n            */
/* Compilador: Dev-C++ versão 5.11                                */
/******************************************************************/

#include <stdlib.h>
#include <stdio.h>

int elemento (int n , float X[]){
	
	int i,count=0;
	
	for(i=0;i<4;i++){
		
		if(X[i]==n){
			
		    count++;
			
		}
		
	}
    
	return count;
}

int main (){
    
	int i,n;
	float X[n];
	
	puts("digite um numero ");
	scanf("%d",&n);
	
	printf("digite um vetor de tamanho %d\n",n);
	for(i==0;i<n;i++){
		
		printf("elemento[%d]:",i+1);
		scanf("%f",&X[i]);
		
	}
	
	puts("vetor :");
	for(i=0;i<n;i++){
		
		printf("\n %f\n",X[i]);
		
	}
	
	printf("\no elemento aparece %d vezes",elemento(n,X));

}
