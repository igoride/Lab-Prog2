/***********************************************************/
/*Nome:Igor Yoshimitsu Ide                                 */
/*RA:181041596					  	    				   */
/*Exercicio --3 --	Ordena lista						   */
/*Compilador: DevC 5.11							    	   */
/***********************************************************/
#include <stdio.h>
#include <stdlib.h>

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

void ImprimeP(lista *L){
	
	while(L != NULL){
		
		printf("%d  ", L->item);
		L = L->prox;
	
	}
}

int contar(lista *L){
	
	if(L==NULL)
		return 0;
	else
		return 1+ contar(L->prox);

}

lista *Remove_Rec(lista *L , int x){
	
	lista *p;
	
	p=L->prox;
	if(L==NULL) return NULL;
	if(p->item==x){
		
		L->prox=p->prox;
	} 
	else Remove_Rec(L->prox,x);	

}


void Ordena(lista *L){
	
	lista *i, *j;
	int aux;
	
	for(i=L;i->prox!=NULL;i=i->prox){
		for(j=i->prox;j!=NULL;j=j->prox){
			if(i->item > j->item){
				
				aux = i->item;
				i->item = j->item;
				j->item =  aux; 
			
			}
		}
	}
}

int main(){

	int x,n,i;
	
	lista *L;
	L = NULL;

	puts("Digite quantos elementos tera a lista:");
	scanf("%d",&n);
	printf("\n");
	
	for(i=0;i<n;i++){
		
		printf("Digite o numero para coloca-lo na lista: ");
		scanf("%d",&x);
		
		L=InsereP(L,x);	
	
	}
	printf("\n");
	
	puts("Lista antes de remover os itens repetidos:");
	ImprimeP(L);
	
	Ordena(L);
	
	puts("\nLista depois de ordenada:");
	ImprimeP(L);
	
}
