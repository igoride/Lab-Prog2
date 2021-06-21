/***************************************************************/
/*Nome: Igor Yoshimitsu Ide                                    */
/*RA: 181040387                                                */
/*Exercicio-3, 5, 6-- Lista encadeada com cabe�a de lista      */
/*Compilador: DevC vers�o 5.11                                 */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	
	int item;
	struct node *prox;
		
}list;

//Exerc�cio 3 - Lista 10
list *Insere_c (list *le, int x){
	
	list *n;
	n=(list *) malloc (sizeof(list));
	n->item=x;
	n->prox=le->prox;
	le->prox=n;//altera-se o campo proximo do n� de cabe�alho
}

//Exerc�cio 5 - Lista 10
//void ImprimeC(lista L)
//{
//	lista *P;
//	P=L.prox;
//	while(P!=NULL)
//	{
//		printf("%d\n",P->elem);
//		P=P->prox;
//	}	
//}

void Imprime_c (list *le) {
	
    list *p;
    for (p = le->prox; p != NULL; p = p->prox)
        printf ("%d\n", p->item);

}

int main(){
	
	
	list *le;
	le=(list*) malloc (sizeof(list));
	le->prox=NULL; //cria-se a lista com no de cabe�alho.
	
	int x,n,i;
	
	puts("Digite quantos nos ter� na lista:");
	scanf("%d", &n);
	
	for(i=0;i<n;i++) {
		
		puts("Digite o numero para coloca-lo na lista.");
		scanf("%d", &x);
		
		Insere_c(le, x);	
	
	}
	puts("\n\n");
	Imprime_c(le);
	
	free(le);
		
}
