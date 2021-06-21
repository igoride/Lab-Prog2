/*****************************************************************/
/* Nome: Igor Yoshimitsu Ide             	 	 	   			 */
/* RA: 181040387                         	 	 	   			 */
/* Exercício-- 3, 4, 5, 6 ----                                   */
/* Compilador: Dev-C++ v5.11              	 	 	   			 */
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct no{
	
	int elem;
	struct no *prox, *ant;

} lista_duplaC;


void insere(lista_duplaC *L, int x){
	
	lista_duplaC *novo;
	novo = (lista_duplaC *) malloc(sizeof(lista_duplaC));
	
	novo->elem = x;
	novo->ant = L;
	
	if(L->prox == L && L->ant == L) {  
		
		novo->prox = L;
		L->prox = novo;
		L->ant = novo;
	
	}
	else {
	
		novo->prox = L->prox;
		(L->prox)->ant = novo;
		L->prox = novo;
	
	}

}

void imprime(lista_duplaC *L){
	
	lista_duplaC *aux = L->prox;
	
	while(aux != L){
		
		if(aux->prox == L) printf("%d", aux->elem);
		
		else printf("%d -> ", aux->elem);
		
		aux = aux->prox;
	
	}

}


lista_duplaC *busca_e(lista_duplaC *L, int x){
	
	lista_duplaC *aux;
	
	aux=L->prox;
	
	while(aux != L && aux->elem != x) aux = aux->prox;
	
	if(aux->elem == x) return aux;
	else return NULL;

}


void remover(lista_duplaC *L, int x){

	lista_duplaC *aux;
    
	aux=L->prox;
		
	if(L->prox == L){ 
	
		puts("\n--> Erro! Lista vazia.");
	
	}
	else {
		
		while(aux != L && aux->elem != x) aux = aux->prox;
		
		if(aux->elem == x){ 
			
			(aux->ant)->prox = aux->prox;
			
			(aux->prox)->ant = aux->ant;
			
			free(aux);
		
		}
		else puts("\n--> O elemento não foi encontrado!");
	
	}

}

void insere_o(lista_duplaC *L, int x){
	
	lista_duplaC *aux = L->prox, *novo;
	
	novo = (lista_duplaC *) malloc(sizeof(lista_duplaC));
	novo->elem = x;	
	
	if(L->prox == L){
	
		L->prox = novo;
		L->ant = novo;
		novo->prox = L;
		novo->ant = L;
	
	}
	else { 
	    while(aux != L && aux->elem >= x) aux = aux->prox;
		
		if(aux != L) {
		
			novo->prox = aux;
			novo->ant = aux->ant;
			(aux->ant)->prox = novo;
			aux->ant = novo;
		
		}
	
	}

}

int main(){

	lista_duplaC L;

	L.prox = &L;
	L.ant = &L;
	
	int i, x, n;
	
	puts("Digite a quantidade de elementos que voce deseja ter na lista\n");
	scanf("%d", &n);	
	
	for(i=0; i<n; i++){
		
		printf("Digite um novo elemento: ");
		scanf("%d", &x);
	    insere(&L, x);
	}
	imprime(&L);
	
	printf("\n Digite o nó a ser procurado: ");
	scanf("%d", &x);
	
	printf("%d", busca_e(&L, x));
	
	printf("\n Digite o número a ser removido: ");
	scanf("%d", &x);
	
	remover(&L, x);
	
	puts("\n");
	
	imprime(&L);
	
	puts("\n Inserindo Ordenado: ");
	
	n=0;
	
	puts("\n Digite quantos elementos voce deseja inserir na lsita");
	scanf("%d ", &n);
	
	for(i=0; i<n; i++){
		
		printf(" Digite um novo elemento: ");
		scanf("%d", &x);
		insere_o(&L, x);
	
	}
	
	imprime(&L);

}
