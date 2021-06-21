#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "locale.h"

/*******************************************************/
/*Nome:Lucca Augusto Torres Tambor                     */
/*RA:181041596										   */
/*Exercicio 2 -- Lista 12--							   */
/*Compilador: DevC 5.11								   */
/*******************************************************/

typedef struct no
{
	int item;
	struct no *prox;
}lista;

lista *InsereP(lista *L, int x)
{
	
	lista *novo;
	novo=(lista *)malloc(sizeof(lista));
	novo->item=x;
	novo->prox=L;
	return novo;	
}

void ImprimeP(lista *L)
{
	while(L!=NULL)
	{
		printf("%i  ", L->item);
		L = L->prox;
	}
}

lista *Intersec(lista *L, lista *M)
{
	lista *P,*aux;
	P=NULL;
	while(L!=NULL)
	{
		aux = M;
		while(aux!=NULL)
		{
			if(aux->item == L->item)
				P = InsereP(P,aux->item);
			aux = aux->prox;
		}
		L= L->prox;
	}
	return P;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int x,op,n,prova;
	lista *L, *M, *P;
	L = NULL;
	M = NULL;
	P = NULL;
	printf("\nInserira os  elemento da primeira lista:\n");
	do
	{
		printf("\nInsira o elemento que desejá(insira 0 para parar):");
		scanf("%i",&x);
		if(x!=0)
		{
			L = InsereP(L,x);
			printf("Elemento inserido.");
		}
	}while(x!=0);
	printf("\nInserira os  elemento da segunda lista:\n");
	do
	{
		printf("\nInsira o elemento que desejá(insira 0 para parar):");
		scanf("%i",&x);
		if(x!=0)
		{
			M = InsereP(M,x);
			printf("Elemento inserido.");
		}
	}while(x!=0);
	P = Intersec(L,M);
	ImprimeP(P);
}
