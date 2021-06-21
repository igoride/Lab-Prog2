/******************************************************************/
/* Nome : Igor Yoshimitsu Ide                                     */
/* RA : 181040387                                                 */
/* Exercício-Progama 3 -- mostra a soma dos n primeiros primos    */
/* Compilador: Dev-C++ versão 5.11                                */
/******************************************************************/

#include<stdio.h>
#include<stdlib.h>

int primo(int n){
	
	int count=0,i;
	
	for (i = 1; i <= n; i++) {
        
		if (n % i == 0) { 
            count++;
        
		}
    }
    
	if (count == 2){
        return 1;
    }
    
	else{
        return 0;
    }
    
}

int main(){
	
	int n,i,soma=0;
	
	do{
		system("cls");
		puts("digite um numero inteiro nao negativo para saber a soma dos n primeiros numeros primos");
	    scanf("%d",&n);	
	}while(n<=0);
     
	for(i=1;i<=n;i++){
		
		if(primo(i)==1){
			soma=soma+i;
		}
	}
	
	printf("a soma dos n primeiros numeros primos e : %d", soma);
}
