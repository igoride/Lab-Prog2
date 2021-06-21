/******************************************************************/
/* Nome : Igor Yoshimitsu Ide                                     */
/* RA : 181040387                                                 */
/* Exercício-Progama 5     --  mostra a subsequência de um numero */
/* Compilador: Dev-C++ versão 5.11                                */
/******************************************************************/

#include <stdlib.h>
#include <stdio.h>

void sub(int n, int v[]){
	
	int a=1;
	int b=0;
	int count=1;
	
	do{
		
		printf("\nSubsequência %d \n",count);
		
		while(v[a-1]<=v[a]){       
			
			printf("%d ",v[a-1]);
			a++;
			
		}
		
		printf("%d ",v[a-1]);
		b=a;
		count++;
		a++;
	
	}while(b<n);
		
}

int main(){
	
	int i,n;
	int v[n];
	
	do{
		
		system("cls");	
	    puts("Insira o numero de elementos que o vetor ter (0 < n <= 100): ");	
	    scanf("%d",&n);
			
	}while((n<=0) || (n>100));
		
	puts("Insira os elementos do vetor: ");
		
	for(i=0;i<n;i++){
			
		printf("elemento[%d]",i+1);
		scanf("%d",&v[i]);
			
	}	
		
	sub(n,v);


}
