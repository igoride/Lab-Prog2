/******************************************************************/
/* Nome : Igor Yoshimitsu Ide                                     */
/* RA : 181040387                                                 */
/* Exercício-Progama 3 -- mescla dois vetores                     */
/* Compilador: Dev-C++ versão 5.11                                */
/******************************************************************/

#include <stdio.h>
#include <stdlib.h>

void ordem(int V[],int n){ // essa função ordena o vetor se necessario
	int i,j,aux;
	
	for(j=0;j<n;j++){
		for(i=0;i<n-1;i++){
			
			if(V[i]>V[i+1]){
			
				aux=V[i];
				V[i]=V[i+1];
				V[i+1]=aux;	
			
			}
		
		}
	}
	
}

void mesclar(int A[],int B[],int C[],int n,int m){ // essa função aloca ordenadamente os elementos dos vetores A e B no vetor C
	
	int i=0,j=0,k=0;
	int g=0,f=0,cont=0,cont2=0;
	
	do
	{
		if(A[i]>B[j]){
		
			C[k]=B[j];
			k++;
		    j++;	
		
		}
		else{
		
			C[k]=A[i];
			k++;
			i++;
			cont++;	
		
		}
		
		cont2++;
	
	}while((cont!=n) || (cont2!=n+m));
		
	i=0;
	
	for(i=0;i<n+m;i++){
		
		printf("%d ",C[i]);
	
	}
	
}

int main(){
	
	int i,n,m;
	int A[n],B[m],C[n+m];
	
	do{
		
	    puts("Insira o tamanho do primeiro (0< n <= 100): ");
	    scanf("%d",&n);
    }while((n<=0) || (n>100));
    
    do{

     	puts("Insira o tamanho do segundo vetor (0 < m <= 100): ");
	    scanf("%d",&m);
    }while((m<=0) || (m>100));
    
	puts("Insira os elementos do primeiro vetor: ");
	for(i=0;i<n;i++){
		
		printf("elemento[%d]",i+1);
		scanf("%d",&A[i]);
	
	}
	
	puts("Insira os elementos do segundo vetor: ");
	for(i=0;i<m;i++){
		
		printf("elemento[%d]",i+1);
		scanf("%d",&B[i]);
	
	}
	
	ordem(A,n);

	ordem(B,m);
	
	mesclar(A,B,C,n,m);

}
