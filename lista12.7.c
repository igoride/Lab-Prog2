/*******************************************************/
/*Nome:Igor yoshimitsu ide                             */
/*RA:181041596										   */
/*Exercicio -7 - 						   */
/*Compilador: DevC 5.11								   */
/*******************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no{
	
	int item;
	struct no *prox, *ant;

}lista_dupla;

lista_dupla *Insere(lista_dupla *L, int x){
	
	lista_dupla *novo,*p;
	
	novo=(lista_dupla *) malloc (sizeof(lista_dupla));
	novo->item=x;
	
	if(L == NULL){
		
		novo->ant=NULL;
		novo->prox=NULL;	
	
	}
	else{
		
		if(x < L->item){ //insere no inicio da lista.
		
			novo->prox=L;
			novo->ant=NULL;
			L->ant=novo;
			return novo;
		
		}
		else{ //insere no meio/final da lista.
		
			p=L;
			
			while(p->prox != NULL && (p->prox)->item <= x) p=p->prox;
			
			novo->prox=p->prox;
			novo->ant=p;
			if(p->prox!=NULL){ //insere no meio da lista
	
				(p->prox)->ant=novo;	
			
			}
			
			p->prox=novo;
			return L;	
		
		}	
	}
}

lista_dupla *Busca (lista_dupla *L, int x){
	
	lista_dupla *p;
	p=L->prox;
	
	while(p != NULL && p->item < x) p=p->prox;

	if(p != NULL && p->item == x) return p;

	else return NULL;

}

lista_dupla *InsereDepois(lista_dupla *L, int x, int y){
	
	lista_dupla *novo, *p;
	
	novo = (lista_dupla *) malloc (sizeof(lista_dupla));
	
	novo->item = y;
	p = L;
	
	while(p!=NULL && p->item !=x) p=p->prox;
	
	if(p != NULL && p->item == x){
		
		novo->ant = p;
		novo->prox = p->prox;
		p->prox = novo;
	
	}
	
	return L;

}

void ImprimeC(lista_dupla *L){
	
	while(L != NULL){
		
		printf("%i  ", L->item);
		L = L->prox;
	
	}
}



int main(){
	
	int i,n,x,y,z;
	
	lista_dupla *L;
	L=NULL;
	
	puts("Digite quantos itens tera a lista:");
	scanf("%d",&n);
	printf("\n");
	
	for(i=0;i<n;i++){
		
		printf("Digite o numero para coloca-lo na lista: ");
		scanf("%d",&z);
		L=Insere(L,z);	
	
	}
	puts("Digite o numero que voce quer inserir na lista.");
	scanf("%d",&y);
	puts("Insira o elemento cujo no que sera o anterior ao numero que voce inseriu.");
	scanf("%d",&x);
	printf("\n");
	
	puts("Lista:");
	ImprimeC(L);
	printf("\n");
	
	L=InsereDepois(L,x,y);
	printf("\n");
	puts("Lista após a inserçao do item:");
	ImprimeC(L);
	
}
