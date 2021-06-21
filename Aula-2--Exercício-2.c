/******************************************************************/
/* Nome : Igor Yoshimitsu Ide                                     */
/* RA : 181040387                                                 */
/* Exercício-Progama 2 -- faz operaçoes entre dois numeros        */
/* Compilador: Dev-C++ versão 5.11                                */
/******************************************************************/

#include<stdio.h>
#include<stdlib.h>

float divisao (float a,float b){
	float D;
	D=a/b;
	return D;
}

int soma (int a,int b){
	int S;
	S=a+b;
	return S;
}

int sub (int a, int b){
	int Sub;
	Sub=a-b;
	return Sub;
}

int mult (int a,int b){
	int Mult;
	Mult=a*b;
	return Mult;
}

int main(){
	int a,b,n;
	
	puts("digite dois numeros");
	scanf("%d %d",&a,&b);
	
	puts("escolha o que fazer com eles: 1-somar, 2-subtrair, 3 multiplicar, 4-dividir");
	scanf("%d",&n);
	
	if(n==1){
		printf("a soma de %d + %d = %d",a,b,soma(a,b));
	}
	
	if(n==2){
		printf("a subtraçao de %d - %d = %d",a,b,sub(a,b));
	}
	
	if(n==3){
		printf("a multiplicaçao de %d * %d = %d",a,b,mult(a,b));
	}
	
	if(n==4){
		printf("a divisao de %d / %d = %f",a,b,divisao(a,b));
	}
}
