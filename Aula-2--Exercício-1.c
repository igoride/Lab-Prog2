/******************************************************************/
/* Nome : Igor Yoshimitsu Ide                                     */
/* RA : 181040387                                                 */
/* Exercício-Progama 1 -- da a soma dos n primeiros numeros       */
/* Compilador: Dev-C++ versão 5.11                                */
/******************************************************************/

#include<stdio.h>
#include<stdlib.h>

int func (int n){
     int i,j;
     j=0;
	 for(i=1;i<=n;i++){
	 	j=j+i;
	 } 
	return (j);  	
}

int main(){
	int n;
	puts("digite um numero para obter sua progressao aritimetica:");
	scanf("%d",&n);
	printf("sua progressao aritmetica e : %d",func(n));
}
