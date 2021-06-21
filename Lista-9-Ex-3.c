/*************************************************************/
/*Nome: Igor Yoshimitsu Ide                                  */
/*RA:181040387                                               */
/*Exercicio-3 - cadastro alocação dinamica                   */
/*Compilador: DevC versão 5.11                               */
/*************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	
	    int matricula;
	    char sobrenome[50];
	    int ano;
	
}aluno[30];	

    aluno*a=NULL;
    
int main (){
	
	int i, n;
	
	puts("Digite a quantidade de alunos na sala\n");
	scanf("%d", &n);
	
    a= (aluno*) malloc (n*sizeof(aluno)); 
	
	for(i=0; i<n; i++){

    	puts("\n|-------------------- Cadastro ---------------------|"); 
    	puts("\n|----------- Digite a matricula do aluno -----------|\n");
	    scanf("%d", &a[i]->matricula);
	    puts("\n|----------- Digite o sobrenome do aluno -----------|\n");
	    scanf("%s", a[i]->sobrenome);
	    fflush(stdin);
		puts("\n|--------- Digite a data de nascimento do aluno ----|\n");
	    scanf("%d", &a[i]->ano);
	    puts("\n\n");
	    
    }
    
    for(i=0; i<n; i++){

    	puts("\n|--------------------------------------- Cadastro -----------------------------------------|\n"); 
    	puts("\n|--------------------------------- Matricula do aluno : -----------------------------------|\n");
	    printf("\n|---------------------------------------- %d --------------------------------------------|\n", a[i]->matricula);
	    puts("\n|--------------------------------- Sobrenome do aluno -------------------------------------|\n");
	    printf("\n|--------------------------------------- %s ----------------------------------------|\n", a[i]->sobrenome);
	    puts("\n|--------------------------------- Data de nascimento do aluno ----------------------------|\n");
	    printf("\n|----------------------------------------- %d -------------------------------------------|", a[i]->ano);
	    puts("\n\n");
	    
    }
    
    free(a);
}
