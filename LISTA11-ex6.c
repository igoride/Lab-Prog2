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
	
	if(le == NULL) printf("\nNULL\n");
	
	while(le!=NULL){
		
		printf("%d\n", le->item);
		le=le->prox;
			
	
	}	
	puts("\n");
}

list *Concatena (list *l1, list *l2){
	
	list *nex;
	nex=(list*) malloc (sizeof(list));
    //Verifica se l1 ou l2 e nulo
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;
	
	while(l1){//passa l1 para nex e chega no ultimo elemento de l1
			
			nex=l1;
			l1=l1->prox;
		
	}
	
	nex=l2;
	 
    return nex;
	
	
}

int main(){
	
	int x,nos,i;

	
	list *l1, *l2, *n;
	
	l1=(list*) malloc (sizeof(list));
	l1=NULL; //lista começa vazia
	
	l2=(list*) malloc (sizeof(list));
	l2=NULL;
	
	puts("Digite quantos nos tera a lista 1:");
	scanf("%d", &nos);
	
	for(i=0; i<nos; i++) {
		
		puts("\nDigite o numero para coloca-lo na lista.");
		scanf("%d", &x);
	
		l1=Insere(l1, x);	
	
	}
	
	puts("\n\n");
	
		puts("Digite quantos nos tera a lista 2:");
	scanf("%d", &nos);
	
	for(i=0; i<nos; i++) {
		
		puts("\nDigite o numero para coloca-lo na lista.");
		scanf("%d", &x);
	
		l2=Insere(l2, x);	
	
	}
	
	puts("\nlista 1\n");
	Imprime_l(l1);
	
	puts("\nlista 2\n");
	Imprime_l(l2);
    
	puts("");
	
	Imprime_l(Concatena(l1, l2));
	
	free(l1);
	free(l2);
}
