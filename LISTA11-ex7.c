/********************************************************/
/*Nome: Igor Yoshimitsu Ide                             */
/*RA: 181040387                                         */
/*Exercicio-   7     --    Inverter uma lista           */
/*Compilador: DevC versão 5.11                          */
/********************************************************/

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

list *Inverte(list *le){
	
	list *p,*ant,*p2,*pro;
	int i=0,j,aux,aux2;
	ant=NULL;
	pro=NULL;
	p=le;
	p2=le;
	
	while(p2->prox!=NULL){
		p2=p2->prox;
		aux=p2->item;
	}
	while(le->item!=aux){
		if(i==1){
			pro=p2;
			p2=le;
			aux2=le->item;
			while(p2->prox!=pro){
				p2=p2->prox;	
			}
			for(p=le;p!=p2;p=p->prox){
				p->item=p->prox->item;
				ant=p;	
			}
			p2->item=aux2;
		}
		if(i==0){
			aux2=le->item;
			for(p=le;p!=p2;p=p->prox){
				p->item=(p->prox)->item;
				ant=p;	
			} 
			p2->item=aux2;
			i=1;	
		}
			
	}
	
	return le;
}

int main(){
	
	int x,m,i;
	int ne, g;
	
	list *le, *nl;
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
	
	Inverte(le);
	
	puts("\n\n");
	
	puts("A lista invertida :");
	Imprime_l(le);
	
	
	free(le);
}
