/******************************************************************/
/* Nome : Igor Yoshimitsu Ide                                     */
/* RA : 181040387                                                 */
/* Exerc�cio-Progama 1 -- da a soma dos n primeiros numeros       */
/* Compilador: Dev-C++ vers�o 5.11                                */
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
