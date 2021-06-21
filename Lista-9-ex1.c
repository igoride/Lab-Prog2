/*************************************************************************/
/*Nome: Igor Yoshimitsu Ide                                              */
/*RA:181040387                                                           */
/*Exercicio-1- multiplicação de matriz com alocação dinâmica             */
/*Compilador: DevC versão 5.11                                           */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void Read (int n, int m, int **v){
	
	int i, j;
	
	for(i=0;i<n;i++){
		
		for(j=0;j<m;j++){
			
			printf("Matriz[%d][%d]: ", i+1, j+1);
			scanf("%d", &v[i][j]);
		
		}
	
	}

}

void Write (int n, int m, int **v){
	
	int i, j;
	
	for(i=0;i<n;i++){
		
		for(j=0;j<m;j++){
			
			printf("%d ", v[i][j]);
		
		}
		
		printf("\n");
	
	}

}

int **Malloc (int m, int n)
{
	int **v, i;
	
	v=(int**)malloc(m*sizeof(int*));
	
	for(i=0;i<m;i++){

		v[i]=(int*)malloc(n*sizeof(int));
    
	}
	
	return v;	
		
}

void Multiply (int m, int n, int p, int **v, int **v1, int **v2){
	
	int i, j, k;
	
	for(i=0;i<m;i++){
	
		for(j=0;j<p;j++){
			
			v2[i][j]=0;
		
		}
	
    }
    
	for(i=0;i<m;i++){
		
		for(j=0;j<p;j++){
			
			for(k=0;k<n;k++){
				
				v2[i][j]+=v[i][k]*v1[k][j];	
			
			}
		
		}
	
	}
	
}

int **Unlock (int **x){
	
	free(x);
	
	return NULL;	

}

int main(){

	
	int **V, **V1, **V2, m, n, p, i, j;
	
	puts("Digite os tamanhos das matrizes: ");
	scanf("%d %d %d", &m, &n, &p);
	
	V=Malloc(m, n);
	V1=Malloc(n, p);
	V2=Malloc(m, p);
	
	puts("Digite a Matriz A:\n ");
	Read(m, n, V);
	
	puts("Digite a Matriz B:\n ");
	Read(n, p, V1);
	
	puts("Matriz A: ");
	Write(m, n, V);
	
	puts("Matriz B: ");
	Write(n,p,V1);
	
	Multiply(m, n, p, V, V1, V2);
	
	puts("Matriz C:\n ");
	Write(m, p, V2);
	
	V=Unlock(V);
	V1=Unlock(V1);
	V2=Unlock(V2);

}
