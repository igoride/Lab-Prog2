/******************************************************************/
/* Nome : Igor Yoshimitsu Ide                                     */
/* RA : 181040387                                                 */
/* Exercício-Progama 4 --  soma matrizes                          */
/* Compilador: Dev-C++ versão 5.11                                */
/******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int soma(int A[][100], int B[][100],int C[][100],int m,int n){
	
	int i,j;
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		
			C[i][j]=A[i][j]+B[i][j];
		
		}	
	}
	
}

int main(){
		
	int i,j,m,n;
	int A[n][m],B[n][m],C[n][m];
	
	puts(" Insira a quantidade de linhas e colunas que aw matrizes terao: ");
	do{
		
		scanf("%d%d",&n,&m);
		
	}while((n<=0) && (m>100));
	
	
	puts(" Insira a A: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			
			printf("elemento [%d][%d]: ",i+1,j+1);
			scanf("%d",&A[i][j]);
			printf("\n");
		
		}	
	}
	
	puts(" Insira a B: ");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			
			printf("elemento[%d][%d]: ",i+1,j+1);
			scanf("%d",&B[i][j]);
			printf("\n");
		
		}	
	}	
	
	puts(" matriz A :");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			
			printf("%d ",A[i][j]);
		
		}
		
		printf("\n");	
	
	}
	
	puts(" matriz B :");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			
			printf("%d ",B[i][j]);
		
		}
		
		printf("\n");	
	
	}	
	
	soma(A,B,C,m,n);
    
    puts("\n Matriz soma :");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			
			printf("%d ",C[i][j]);
		
		}
		
		printf("\n");	
	
	}	
			
}
