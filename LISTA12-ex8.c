/***************************************************************************************************/
/*Nome: Igor Yoshimitsu ide                                                                        */
/*RA: 181040387                                                                                    */
/*Exercicio- 8 -- Inserção, busca e remoção para uma lista duplamente encadeada com nó de cabeçalho*/
/*Compilador: DevC versão 5.11                                                                     */
/***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int item;
	struct no *ant,*prox;
} lista_dupla;

void ImprimeC(lista_dupla *L){
	
	lista_dupla *p;
	p=L->prox;
	while(p!=NULL){
		
		printf("%d\n",p->item);
		p=p->prox;
	
	}	
}

lista_dupla *Insere (lista_dupla *L, int x){
	
	lista_dupla *novo,*p,*q;
	novo=(lista_dupla *) malloc (sizeof(lista_dupla));
	novo->item=x;
	q=L->prox;
	if(L->prox==NULL){
		
		novo->ant=L;
		L->prox=novo;
		novo->prox=NULL;	
	
	}
	else{
		if(x < q->item){ //inser no inici da lista.
		
			novo->prox=q;
			novo->ant=L;
			q->ant=novo;
			L->prox=novo;
		
		}
		else{ //insere no meio/final da lista.
		
			p=L->prox;
			
			while(p->prox != NULL && (p->prox)->item <= x) p=p->prox;
			
			novo->prox=p->prox;
			novo->ant=p;
			
			if(p->prox != NULL){ //insere no meio da lista
			
				(p->prox)->ant=novo;	
			
			}
			
			p->prox=novo;	
		
		}	
	}
	
	return L;

}

lista_dupla *Busca (lista_dupla *L, int x){
	
	lista_dupla *p;
	p=L->prox;
	
	while(p != NULL && p->item < x) p=p->prox;

	if(p != NULL && p->item == x) return p;

	else return NULL;

}

lista_dupla *Remove (lista_dupla *L, int x){
	
	lista_dupla *p,*q1,*q2;

	p=Busca(L,x);
	if(p!=NULL){
		
		q1=p->ant;
		q2=p->prox;
		
		if(p == L->prox) L->prox=q2; //remoção do 1° elemento da lista L, neste caso o inicio passa a ser o nó q2
		
		if(q1 != NULL) q1->prox=q2; //remoção do elemento dp meio ou final da lista
		
		if(q2 != NULL) q2->ant=q1;
		
		free(p);	
	
	}
	
	return L;	

}

int main(){
	
	int i,n,x,y,z;
	
	lista_dupla *L,*e;
	
	L=(lista_dupla *)malloc(sizeof(lista_dupla));
	
	L->ant=NULL;
	L->prox=NULL;
	
	puts("Digite o numero de elementos da lista:");
	scanf("%d",&n);
	printf("\n");
	
	for(i=0;i<n;i++){
		
		printf("Digite um numero para o inser na lista: ");
		scanf("%d",&x);
		
		L=Insere(L,x);	
	
	}
	printf("\n");
	puts("Lista:");
	ImprimeC(L);
	printf("\n");
	
	puts("Digite o item que voce quer saber o endereço.");
	scanf("%d",&y);
	
	e=Busca(L,y);
	printf("O item %d esta na alocado no endereço %d",y,e);
	printf("\n");
	
	puts("Insira o item que voce quer remover.");
	scanf("%d",&z);
	printf("\n");
	L=Remove(L,z);
	
	puts("Lista apos a remoção do item:");
	ImprimeC(L);
	
	
}
