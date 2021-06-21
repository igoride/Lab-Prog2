/******************************************************************/
/* Nome : Igor Yoshimitsu Ide                                     */
/* RA : 181040387                                                 */
/* Exercício-Progama 1 --  calculadora                            */
/* Compilador: Dev-C++ versão 5.11                                */
/******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int operacao(int a,int b,char c,int *resultado){
	switch(c){
		case '+':
			*resultado=a+b;
		break;	
		case '-':
			*resultado=a-b;
		break;
		case '*':
			*resultado=a*b;
		break;
		case '/' : 
		    *resultado=a/b;
		break;
		default :
			printf("operador invalido");
	}
}

int main() {
	int a,b;
	char c,r;
	int resultado;
	while(r!='n'){
	
	puts("digite a conta no estilo : a+b/-/a-b/-/a*b/-/a/b/-/\n");
	scanf("%d %c %d",&a,&c,&b);
	
	operacao(a,b,c,&resultado);
	printf("%d",resultado);
    
    puts("vc quer continuar o progama ? ");
    r=getchar();
    
    }
}
