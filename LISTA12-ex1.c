/*********************************************************************************/
/*Nome: Igor Yoshimitsu Ide                                                     */
/*RA: 181040387	                                                                */
/*Exercicio- 1 --   Função para conferir se duas listas possuem o mesmo conteúdo*/
/*Compilador: DevC versão 5.11                                                  */
/********************************************************************************/

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
	
	while(L!=NULL)
	{
		printf("%d\n",L->item);
		L=L->prox;	
	}	
}

int ContarElem(lista *L){
	
	lista *p;
	int x=0;
	p=L;
	while(p->prox!=NULL){
		
		x++;
		p=p->prox;	
	}		
	
	return x+1;
}

int Mesmo_Cont(lista *L1, lista *L2, int n){
	
	int c=0;
	if(L1==NULL&&L2!=NULL) return 0;
	else if(L1!=NULL&&L2==NULL) return 0;
	else if(L1==NULL&&L2==NULL) return 1;
	
	if(ContarElem(L1)==ContarElem(L2)){
		
		while(L1!=NULL){
			
			if(L1->item == L2->item) c++;
			L1=L1->prox;
			L2=L2->prox;
		}
		
		if(c==n) return 1;
		else return 0;
	}
	else return 0;
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	int i,n1,n2,x,y,z;
	lista *L1,*L2;
	L1=NULL;
	L2=NULL;
	puts("Insira quantos elementos terá a lista 1:");
	scanf("%d",&n1);
	puts("Insira quantos elementos terá a lista 2:");
	scanf("%d",&n2);
	printf("\n");
	for(i=0;i<n1;i++) 
	{
		printf("Insira o número para colocá-lo na lista 1: ");
		scanf("%d",&x);
		L1=InsereP(L1,x);	
	}
	printf("\n");
	for(i=0;i<n2;i++) 
	{
		printf("Insira o número para colocá-lo na lista 2: ");
		scanf("%d",&y);
		L2=InsereP(L2,y);	
	}
	printf("\n");
	
	puts("Lista 1:");
	ImprimeC(L1);
	
	printf("\n");
	
	puts("Lista 2:");
	ImprimeC(L2);
	
	z=Mesmo_Cont(L1,L2,n1);

	printf("\n");
	
	if(z==0) puts("As listas não possuem o mesmo conteúdo.");
	else if(z==1) puts("As listas possuem o mesmo conteúdo.");
}
