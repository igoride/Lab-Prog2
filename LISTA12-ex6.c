/***************************************************************************/
/*Nome: Igor Yoshimitsu Ide                                                */
/*RA: 181040387	                                                           */
/*Exercicio- 6 -- Função que faz a fusão entre duas litas ordenadas        */
/*Compilador: DevC versão 5.11                                             */
/***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

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

lista *BuscaRemocao(lista *L, int x){
	
	lista *ant,*p;
	ant=NULL;
	p=L;
	
	while(p!=NULL && p->item != x){
		ant=p;
		p=p->prox;
	}		
	if(p != NULL){
		if(ant == NULL){
			L=L->prox;
			free(p);	
		}
		else{
			ant->prox=p->prox;
			free(p);
		}
	}
	
	return L;
}

lista *Ordena(lista *L, int n){
	
	lista *K,*p,*q,*a;
	int ma,c=0,flag=0;
	
	K=NULL;
	
	if(L==NULL) return NULL;
	while(n!=c){
	
		p=L;
		q=L->prox;
		ma=p->item;
	
		while(q != NULL){
			if(q->item > ma) ma=q->item;
			q=q->prox;
		}
	
		K=InsereP(K,ma);
		c++;
		a=L;
	
		while(a != NULL){
			if(a->item == ma){
				flag=1;
				L=BuscaRemocao(L,ma);	
			}
	
			a=a->prox;
	
		}
	
	}
	return K;
}

lista *Fusao(lista *L, lista *L1, lista *L2, int n1, int n2){
	
	lista *p,*q;
	L=NULL;
	p=L1;
	q=L2;
	while(p != NULL && q != NULL){ 
		if(p->item < q->item){
			L=InsereP(L, p->item);
			p=p->prox;
		}
		else if(p->item > q->item){
			L=InsereP(L, q->item);
			q=q->prox;
		}
		else if(p->item == q->item){
			L=InsereP(L, p->item);
			L=InsereP(L, q->item);
			p=p->prox;
			q=q->prox;
		} 	
	}
	if(p == NULL && q != NULL){
		while(q != NULL){
			L=InsereP(L, q->item);
			q=q->prox;
		}	
	} 
	if(q == NULL && p != NULL){
		while(p != NULL){
			L=InsereP(L, p->item);
			p=p->prox;
		}
				
	}
	
	return L;

}

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int i,n1,n2,x,y;
	lista *L1,*L2,*L;
	L=NULL;
	L1=NULL;
	L2=NULL;
	
	puts("Digite a quantidade de elementos da lista 1:");
	scanf("%d",&n1);
	
	puts("Digite a quantidade de elementos da lista 2:");
	scanf("%d",&n2);
	printf("\n");
	
	for(i=0;i<n1;i++) {
		
		printf("Digite um numero para coloca-lo na lista 1: ");
		scanf("%d",&x);
		L1=InsereP(L1,x);	
	
	}
	printf("\n");
	
	for(i=0;i<n2;i++) {
		
		printf("Digite um numero para coloca-lo na lista 2: ");
		scanf("%d",&y);
		L2=InsereP(L2,y);	
	
	}
	printf("\n");
	
	L1=Ordena(L1,n1);
	L2=Ordena(L2,n2);
	
	puts("Lista 1:");
	ImprimeC(L1);
	printf("\n");
	
	puts("Lista 2:");
	ImprimeC(L2);
	
	L=Fusao(L,L1,L2,n1,n2);
	printf("\n");
	
	puts("Listas Fundidas:");
	ImprimeC(L);

}
