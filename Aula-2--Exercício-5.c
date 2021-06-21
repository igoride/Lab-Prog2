/******************************************************************/
/* Nome : Igor Yoshimitsu Ide                                     */
/* RA : 181040387                                                 */
/* Exercício-Progama 5   -- mostra o conceito da nota de um aluno */
/* Compilador: Dev-C++ versão 5.11                                */
/******************************************************************/

#include<stdio.h>
#include<stdlib.h>

char conceito (int media){
	char conceito1;
	if((media>=0) && (media<5)){
		conceito1='D';
		return conceito1;
	}
	if((media>=5) && (media<7)){
	    conceito1='C';
	    return conceito1;
	}
	if((media>=7) && (media<9)){
		conceito1='B';
		return conceito1;
	}
	if((media>=9) && (media<=10)){
		conceito1='A';
		return conceito1;
	}
	
}

int main(){
	int media;
	char conceito2;
	
	puts("digite a media do aluno para saber seu conceito");
	scanf("%d",&media);
	
	conceito2=conceito(media);
	printf("%c",conceito2);
}
