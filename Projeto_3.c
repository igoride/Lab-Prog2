#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Table{

	int mat[32][32];
	
}tab;


int sol = 1;
int MAX = 10000;

void mostrarTabuleiro(tab p[], int N){
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			
			if(p[0].mat[i][j] == 1)
				printf(" R ");
			else
				printf(" 0 ");
		
		}
		printf("\n");
	}
	printf("\n\n");
}

bool seguro(tab p[], int N, int lin, int col){
	int i, j;

	// verifica se ocorre ataque na linha
	for(i = 0; i < N; i++){
		
		if(p[0].mat[lin][i] == 1)
			return false;
	
	}
	//verifica se ocorre ataque na coluna
	for(i = 0; i < N; i++){
		
		if(p[0].mat[i][col] == 1)
			return false;
	
	}

	// verifica se ocorre ataque na diagonal principal
	// acima e abaixo
	for(i = lin, j = col; i >= 0 && j >= 0; i--, j--){
		
		if(p[0].mat[i][j] == 1)
			return false;
	
	}
	for(i = lin, j = col; i < N && j < N; i++, j++){
		
		if(p[0].mat[i][j] == 1)
			return false;
	
	}

	// verifica se ocorre ataque na diagonal secundária
	// acima e abaixo
	for(i = lin, j = col; i >= 0 && j < N; i--, j++){
		
		if(p[0].mat[i][j] == 1)
			return false;
	
	}
	for(i = lin, j = col; i < N && j >= 0; i++, j--){
		
		if(p[0].mat[i][j] == 1)
			return false;
	
	}

	// se chegou aqui, então está seguro (retorna true)
	return true;
}

void executar(tab p[], int N, int col){
	
	if(col == N){
		
		printf("Solução %d\n\n", sol);
	//	mostrarTabuleiro(p, N);
		
		for(int i=0; i < N; i++){
			for(int j=0; j < N; j++){
				p[sol].mat[i][j] = p[0].mat[i][j];
			}
		}
		sol++;
		return;
	
	}

	for(int i = 0; i < N; i++){
		
		// verifica se é seguro colocar a rainha naquela coluna
		if(seguro(p, N, i, col)){
			
			// insere a rainha (marca com 1)
			p[0].mat[i][col] = 1;
           
			// chamada recursiva
			executar(p, N, col + 1);
            
			// remove a rainha (backtracking)
			p[0].mat[i][col] = 0;
		    
		}
	}
	
	
}
void Escrever_arq(tab p[], int N){
	int i, j, k;
	FILE *arq;
	arq = fopen("rainha.out", "w");
	
	fprintf(arq,"%d \n", sol-1);
	
    for(i = 1;i < sol;i++){
    	for(j = 0; j < N; j++){
    		for(k = 0; k < N; k++){
    			fprintf(arq,"%d ", p[i].mat[j][k]);
			}fprintf(arq, "\n");
		}fprintf(arq,"\n\n");
	}

	
	fclose(arq);

}

int main(){
	
	int N;
	
	tab *p; 
	p = (tab*) malloc (MAX * sizeof(tab));
		
	setlocale(LC_ALL, "Portuguese");
	
	scanf("%d", &N);
	
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			p[0].mat[i][j] = 0;
		}
	}
	
	executar(p, N, 0);
	
	Escrever_arq(p, N);
	
//	for(int a=1; a<sol; a++){
//	    for(int i=0; i < N; i++){
//		    for(int j=0; j < N; j++){
//			    printf("%d", p[a].mat[i][j]);
//		    }puts("\n");
//	    }puts("\n-----------\n");
//	}

	// imprime a quantidade de soluções
	printf("\n %d soluções", sol-1);
     
}
