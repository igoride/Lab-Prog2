/****************************************************************************/
/* Nome : Igor Yoshimitsu Ide                                               */
/* RA : 181040387                                                           */
/* Exercício-Progama 6 -- leitura e multiplicaçao de matrizes com ponteiros */
/* Compilador: Dev-C++ versão 5.11                                          */
/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void read (float x[][50],int n, int m, float *p){
	
	int i,j;
	
	p=&x[0][0];
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			
			printf("Elemento [%d,%d]= ",i,j);
			scanf("%f",&(*(p+(i*n+j))));
		
		}
	}

}

void write (float x[][50],int n, int m, float *p){
	
	int i,j;
	
	p=&x[0][0];
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			
			printf("%6.2f",*(p+(i*n+j)));
		}
		
		printf("\n");
	
	}	

}

void mult (float x[][50], float y[][50], float z[][50], int n, int m, int l, float *p, float *p2, float *p3){
	
	int i,j,k;

	p=&x[0][0];

	p2=&y[0][0];

	p3=&z[0][0];

	for(i=0;i<n;i++){
		for(j=0;j<l;j++){
			
			z[i][j]=0;
			
			for(k=0;k<m;k++){
				
				*(p3+(i*n+j))+=*(p+(i*n+k))*(*(p2+(k*n+j)));
			
			}
		
		}
	}	

}

int main(){
	
	float A[50][50],B[50][50],C[50][50];
	float *p1,*p2,*p3;
	int m,n,l;
	
	puts("De 3 valores inteiros: ");
	scanf("%d %d %d",&n,&m,&l);
	
	puts("Digite a Matriz A: ");
	read(A,n,m,p1);
	
	puts("Digite a Matriz B: ");
	read(B,m,l,p1);
	
	printf("\n");
	
	puts("Matriz A: ");
	write(A,n,m,p1);
	
	printf("\n");
	
	puts("Matriz B: ");
	write(B,m,l,p1);
	
	printf("\n");
	
	mult(A,B,C,n,m,l,p1,p2,p3);
	
	puts("Matriz Produto: ");
	write(C,n,l,p1);
	
	return 0;	
}
