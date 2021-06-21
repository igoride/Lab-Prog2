/*************************************************************/
/*Nome: Igor Yoshimitsu Ide                                  */
/*RA: 181040387                                              */
/*Exercicio- 1   -- Busca e remoção de lista sem cabeça      */
/*Compilador: DevC versão 5.11                               */
/*************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	
	int item;
	struct node *prox;
		
}list;

list *Insere (list *le, int x){
	
	list *n;
	n=(list *) malloc (sizeof(list));
	n->item=x;
	n->prox=le;
	return n;
		
}

void Imprime_l (list *le){
	
	while(le!=NULL){
		
		printf("%d\n", le->item);
		le=le->prox;	
	
	}	
	puts("\n");
}

list *Busca_r (list *le, int x){
	
	list *ant;
	
    while(le != NULL && le->item != x){
    	
    	ant=le;
    	le=le->prox;
    	
	}
	if(le != NULL){
		
		if(ant == NULL){
			
			le=le->prox;
			return le;
			free(le);
			
		}
		else{
			
			ant->prox=le->prox;
			free(le);
			
		}
		
		return le;
		
	}
	
}

int main(){
	
	int x,nos,i;
	int ne;
	
	list *le;
	
	le=(list*) malloc (sizeof(list));
	le=NULL; //lista começa vazia
	
	puts("Digite quantos nos tera o programa:");
	scanf("%d", &nos);
	
	for(i=0; i<nos; i++) {
		
		puts("\nDigite o numero para coloca-lo na lista.");
		scanf("%d", &x);
	
		le=Insere(le, x);	
	
	}
	
	puts("\n\n");
	
	Imprime_l(le);
	
	printf("\nDigite o numero a ser buscado e removido \n");
	scanf("%d", &ne);
	
	Busca_r(le, ne);
	
	puts("\n\n");
	
	Imprime_l(le);
	
	
	free(le);
}
