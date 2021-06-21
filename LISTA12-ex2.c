/*************************************************************************************/
/*Nome: Igor Yoshimitsu Ide                                                          */
/*RA: 181040387	                                                                      */
/*Exercicio-  2 --        Intersecçao eentre 2 listas                                */
/*Compilador: DevC versão 5.11                                                       */
/*************************************************************************************/

#include <stdlib.h>
#include <stdio.h>

typedef struct no{
		
		int item;
		struct no *prox;

}lista;

lista *InsereP(lista *L, int x){
	
	lista *novo;
	novo=(lista *)malloc(sizeof(lista));
	novo->item=x;
	novo->prox=L;

	return novo;	

}

void ImprimeC(lista *L){
	
	while(L!=NULL){
		
		printf("%d\n",L->item);
		L=L->prox;	
	
	}	

}

int ContarElem(lista *L){
	
	lista *p;
	
	int x=0;
	
	p=L;
	
	while(p->prox!=NULL){
		
		x++;
		p=p->prox;	
	
	}			
	
	return x+1;

}

lista *Intersec(lista *L1, lista *L2){
	
	lista *L,*p,*q;
	
	int c=0,b=0;
	
	L=NULL;
	
	if(L1 == NULL && L2 != NULL) return L2;
	
	if(L1 != NULL && L2 == NULL) return L1;
	
	if(L1 == NULL && L2 == NULL) return NULL;
	
	while(L2!=NULL){
		
		p=L1;
		
		while(p!=NULL){
			
			q=L;
			
			if(p->item==L2->item) L=InsereP(L,L2->item);
			
			p=p->prox;	
		
		}
		
		L2=L2->prox;
	
	}
	
	return L;

}

int main(){
	
	int i,n1,n2,x,y,z;
	
	lista *L1,*L2,*L;
	
	L1=NULL;
	L2=NULL;
	L=NULL;
	
	puts("Digite a quantidade de itens da lista 1:");
	scanf("%d",&n1);
	
	puts("Digite a quantidade  de itens da lista 2:");
	scanf("%d",&n2);
	
	printf("\n");
	for(i=0;i<n1;i++){
		
		printf("Digite o numero para coloca-lo na lista 1: ");
		scanf("%d",&x);
		L1=InsereP(L1,x);	
	
	}
	printf("\n");
	for(i=0;i<n2;i++) {
		
		printf("Digite o numero para coloca-lo na lista 2: ");
		scanf("%d",&y);
		L2=InsereP(L2,y);	
	
	}
	printf("\n");
	
	puts("Lista 1:");
	ImprimeC(L1);
	
	printf("\n");
	
	puts("Lista 2:");
	ImprimeC(L2);
	
	L=Intersec(L1,L2);

	printf("\n");
	
	puts("Lista Interseccao:");
	ImprimeC(L);

}
