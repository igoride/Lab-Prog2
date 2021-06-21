/******************************************************/
/*Nome: Igor Yoshimitsu Ide                           */
/*RA: 181040387                                       */
/*Exercicio- 7     -- Lista encadeada sem cabeça      */
/*Compilador: DevC versão 5.11                        */
/******************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	
	int item;
	struct node *prox;
		
}lista;

lista *Insere (list *le, int x){
	
	lista *n;
	n=(list *) malloc (sizeof(list));
	n->item=x;
	n->prox=le;
	return n;
		
}

void Imprime_l (lista *le){
	
	while(le!=NULL){
		
		printf("%d\n", le->item);
		le=le->prox;	
	
	}	
	puts("\n");
}

lista *Remove_Recursiva (lista *le , int x){
	
	list *aux;
	aux=le->prox;
	if(le==NULL) return NULL;
	if(aux->item==x)
	{
		le->prox=aux->prox;
	} 
	else Remove_Recursiva(le->prox, x);	
}

int main(){
	
	int x,m,i;
	int ne, g;
	
	lista *le, *nl;
	nl=(list*) malloc (sizeof(list));
	le=(list*) malloc (sizeof(list));
	le=NULL; //lista começa vazia
	
	puts("Digite quantos nos tera o programa:");
	scanf("%d", &m);
	
	for(i=0; i<m; i++) {
		
		puts("\nDigite o numero para coloca-lo na lista.");
		scanf("%d", &x);
		le=Insere(le, x);	
	
	}
	
	puts("\n\n");
	
	Imprime_l(le);
	
	printf("\nDigite o numero a ser buscado e removido \n");
	scanf("%d", &ne);
	
	Remove_Recursiva(le, ne);
	
	puts("\n\n");
	
	Imprime_l(le);
	
	
	free(le);
}
