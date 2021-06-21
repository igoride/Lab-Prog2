/************************************************************************/
/*Nome: Igor Yoshimitsu Ide                                             */
/*RA:181040387                                                          */
/*Exercicio-2 - sequencial -- struct com alocação dinamica              */
/*Compilador: DevC versão 5.11                                          */
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
	
	char nome[50],data_nascimento[30],cpf[20];

}pe[30];

void Inserir (pe *p, int n){
	
	int i;
	
	for(i=0;i<n;i++){
		
		printf("Pessoa %d: \n",i+1);
		puts("Nome:");
		getchar();
		scanf("%[^\n]",p[i]->nome);
		
		puts("Data de Nascimento:");
		getchar();
		scanf("%[^\n]",p[i]->data_nascimento);
		
		puts("CPF:");
		getchar();
		scanf("%[^\n]",p[i]->cpf);

	}

}

void Imprimir (pe *p, int n){
	
	int i;
	
	for(i=0;i<n;i++){
		
		printf("Pessoa %d: \n",i+1);
		
		printf("Nome: %s \n",p[i]->nome);
	
		printf("Data de Nascimento: %s \n",p[i]->data_nascimento);
		
		printf("CPF: %s \n",p[i]->cpf);
	
	}
	
}

int main(){
	
	int n;
	
	puts("Digite a quantidade de pessoas para inserir os dados:");
	scanf("%d",&n);

	pe *p = NULL;
	p=(pe*)malloc(sizeof(pe));
	
	printf("\n");
	
	Inserir(p,n);
	
	printf("\n");
		
	Imprimir(p,n);
	
	free(p);	
}
