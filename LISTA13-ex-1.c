/*****************************************************************/
/* Nome: Igor Yoshimitsu Ide              	 	 	   			 */
/* RA: 181040387                        	 	 	   			 */
/* Exercício- 1 ---- Problema de Josephus                        */
/* Compilador: Dev-C++ v5.11              	 	 	   			 */
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no{
	
	char nome[30];
	struct no *prox;

} listaC;

void Imprime(listaC *L){
	listaC *p;
	
	if(L == NULL) return;
	
	p = L;
	
	do{
	
		if(p->prox == L) printf("%s  ", p->nome);
		
		else printf("%s  ->  ", p->nome);
		
		p = p->prox;
	
	}while(p != L);

}

listaC *Insere_f(listaC *L, char info[]){
	
	listaC *novo, *p;
	novo = (listaC *) malloc(sizeof(listaC));
	
	strcpy(novo->nome, info);
	
	if(L == NULL){
	
		novo->prox = novo;
		return novo;
	
	}
	
	novo->prox = L;
	
	p = L;
	
	while(p->prox != L) p = p->prox;
	
	p->prox = novo;
	
	return L;

}

void RemoveC(listaC *L, listaC *ant){ 

	listaC *p;

	p = ant->prox; // p é o nó a ser removido
	
	if(p->prox == L) { // Removendo o último elemento na lista
		
		L->prox = L;
		free(p);
	
	}
	else {
		
		ant->prox = p->prox;
		free(p);
	
	}

}

listaC *prog(listaC *L,int nremover, char nome[]) {  
	
	int cont = 0;
	
	listaC *p = L, *ant;
	
	while(cont < nremover){
		
		ant = p;
		p=p->prox;
		cont++;
	
	}
	
	strcpy(nome, p->nome); 
	
	RemoveC(L, ant); 
	
	return L;

}

int main(){
	
	listaC *L;
	
	L = NULL;
	
	int x, i, n;
	
	char nome[30];
	
	puts("Digite a quantidade de nomes tera a lista\n");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		
		printf("Nome %d: ", i);
		scanf("%[^\n]", nome);
		
		L = Insere_f(L, nome);
		getchar();
		
	}
	
	Imprime(L);
	
	while(L->prox != L){
		
		printf("\n Digite um numero: ");
		scanf("%d", &x);
		
		L = prog(L, x, nome);
		printf("\n O nome removido foi: %s", nome);
	
	}
	printf("\n\n\n O vencedor e: %s ", L->nome);

}
