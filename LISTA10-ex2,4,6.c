/******************************************************/
/*Nome: Igor Yoshimitsu Ide                           */
/*RA: 181040387                                       */
/*Exercicio-2, 4, 6-- Lista encadeada sem cabeça      */
/*Compilador: DevC versão 5.11                        */
/******************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	
	int item;
	struct node *prox;	

}list;

//Exercício 2 - Lista 10
list *Insere (list *le, int x){
	
	list *n;
	n=(list *) malloc (sizeof(list));
	n->item=x;
	n->prox=le;
	return n;
		
}

//Exercício 4 - Lista 10
void Imprime_l (list *le){
	
	while(le!=NULL){
		
		printf("%d\n", le->item);
		le=le->prox;	
	
	}	
}

int main(){
	
	int x,m,i;
	
	list *le;
	le=NULL; //lista começa vazia
	
	puts("Digite quantos nos tera o programa:");
	scanf("%d", &m);
	
	for(i=0; i<m; i++) {
		
		puts("Digite o numero para coloca-lo na lista.");
		scanf("%d", &x);
		le=Insere(le, x);	
	
	}
	
	Imprime_l(le);	
	
	free(le);
}
