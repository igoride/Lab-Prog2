/*****************************************************************************************/
/*Nome: Tiago Pinheiro Camargo                                                           */
/*RA: 181045631                                                                          */
/*Exercicio-Programa 8 -- Função recursiva para contar quantos elementos tem em uma lista*/
/*Compilador: DevC versão 5.11                                                           */
/*****************************************************************************************/

#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

typedef struct no{
		int elem;
		struct no *prox;
}lista;

lista *InsereP(lista *L, int x)
{
	
	lista *novo;
	novo=(lista *)malloc(sizeof(lista));
	novo->elem=x;
	novo->prox=L;
	return novo;	
}

void ImprimeC(lista *L)
{
	while(L!=NULL)
	{
		printf("%d\n",L->elem);
		L=L->prox;	
	}	
}

lista *Remove_Rec(lista *L , int x)
{
	lista *p;
	p=L->prox;
	if(L==NULL) return NULL;
	if(p->elem==x)
	{
		L->prox=p->prox;
	} 
	else Remove_Rec(L->prox,x);	
}

int main()
{
	setlocale(LC_ALL,"Portuguese");
	
	int i,n,x,y;
	lista *L;
	L=NULL;
	puts("Insira quantos elementos terá a lista:");
	scanf("%d",&n);
	printf("\n");
	for(i=0;i<n;i++) 
	{
		printf("Insira o número para colocá-lo na lista: ");
		scanf("%d",&x);
		L=InsereP(L,x);	
	}
	printf("\n");
	puts("Insira o elemento que você deseja remover da lista.");
	scanf("%d",&y);
	puts("Lista antes de remover o elemento desejado:");
	ImprimeC(L);
	Remove_Rec(L,y);
	
	puts("Lista depois de remover o elemento desejado:");
	ImprimeC(L);
}
