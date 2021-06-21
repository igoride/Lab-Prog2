/*****************************************************************/
/* Nome: Igor Yoshimitsu Ide              	 	 	   			 */
/* RA: 181040387                           	 	 	   			 */
/* Exercício-  2---             Funções em uma lista circular    */
/* Compilador: Dev-C++ v5.11              	 	 	   			 */
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct no{
	int info;
	struct no *prox;
} listaC;


void insere_final(listaC *L, int x){
	
	listaC *novo, *aux;
	aux=L->prox;
	novo = (listaC *) malloc(sizeof(listaC));
	
	novo->info = x;
	
	if(L->prox == L){
		
		novo->prox = L;
		L->prox = novo;
	
	} else {
		
		while(aux->prox != L) aux = aux->prox;
		
		novo->prox = L;
		aux->prox = novo;
	
	}

}

int conta(listaC *L){
	
	int cont = 0;
	listaC *aux;
	aux=L -> prox;
	
	do{
		
		cont++;
		aux = aux->prox;
	
	}while(aux != L);
	
	return cont;

}

void insere_inicio(listaC *L, int x){
	
	listaC *novo;
	novo =(listaC *) malloc(sizeof(listaC));
	novo->info = x;
	
	if(L->prox == L) { 
	
		L->prox = novo;
		novo->prox = L;
	
	}
	else {
		
		novo->prox = L->prox;
		L->prox = novo;
	
	}

}

void imprime_c(listaC *L){
	
	listaC *aux;
	aux = L->prox;
	
	while(aux != L){
		if(aux->prox == L)	printf("%d ", aux->info);
		
		else printf("%d -> ", aux->info);
		
		aux = aux->prox;
	}

}

void remove_c(listaC *L, int x){
	
	listaC *aux, *ant;
	
	aux=L->prox;
	ant=L;
	
	while(aux->info != x && aux != L){
		
		ant = aux;
		aux = aux->prox;
	
	}
	
	if(aux->info == x){ 
	
		ant->prox = aux->prox;
		free(aux);
	
	}
	else {
	
		puts("--> O elemento não foi encontrado.");
	
	}

}

void concatena_circular(listaC *L1, listaC *L2){
	listaC *aux1, *aux2;
	
	aux1=L1->prox;
	aux2=L2->prox;
	
	while(aux1->prox != L1) aux1 = aux1->prox;
	
	aux1->prox = L2->prox;
	
	
	while(aux2->prox != L2) aux2 = aux2->prox;
	
	aux2->prox = L1;

}

void copia_c(listaC *L1, listaC *L2){
	
	listaC *aux1, *auxL2;
	
	aux1=L1->prox;
	
	while(aux1 != L1){
	
		insere_final(L2, aux1->info);
		aux1 = aux1->prox;
	
	}

}

void intercala(listaC *L1, listaC *L2, listaC *L3){

	listaC *aux1, *aux2;
	aux1 = L1->prox;
	aux2 = L2->prox;
	
	while(aux1 != L1 && aux2 != L2){
	
		insere_final(L3, aux1->info);
		insere_final(L3, aux2->info);
		aux1 = aux1->prox;
		aux2 = aux2->prox;
	
	}
	
	while(aux1 != L1){
	
		insere_final(L3, aux1->info);
		aux1 = aux1->prox;
	
	}
	while(aux2 != L2){
	
		insere_final(L3, aux2->info);
		aux2 = aux2->prox;
	
	}

}

int main(){
		
	listaC L1, L2, L3, L4, L5;
	
	L1.prox = &L1;
	L2.prox = &L2;
	L3.prox = &L3;
	L4.prox = &L4;
	L5.prox = &L5;
	
	int i, x = 0, n;
	
	puts("Digite quantos numeros voce deseja colocar na lista-1\n");
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		
		printf("Digite um numero para inserir na lista1: ");
		scanf("%d", &x);
		insere_inicio(&L1, x);
	
	}
    
    n=0;
    
	puts("Digite quantos numeros voce deseja colocar na lista-2\n");
	scanf("%d", &n);	
	
	for(i=0; i<n; i++){
		printf("Digite um numero para inserir na lista2: ");
		scanf("%d", &x);
		insere_inicio(&L2, x);
	}
	
	puts("\n");
	
	imprime_c(&L1);
	
	puts("\n");
	
	imprime_c(&L2);
	
	puts("\n");
	
	printf("\n A lista 1 tem %d elementos.", conta(&L1));
	printf("\n A lista 2 tem %d elementos.\n", conta(&L2));
	
	
	printf("\n Digite um numero para remover da lista 1: ");
	scanf("%d", &x);
	remove_c(&L1, x);
	
	puts("\n--> Lista 1 após a remoção:");
	imprime_c(&L1);
	
	puts("Realizando uma cópia da lista L1:");
	copia_c(&L1, &L3);
	
	copia_c(&L2, &L4);
	
	imprime_c(&L3);
	
	puts("Concatenando as duas listas:");
	
	concatena_circular(&L1, &L2);
	
	imprime_c(&L1);

	puts("Intercalando as duas listas:");
	
	intercala(&L3, &L4, &L5);
	
	imprime_c(&L5);

}
