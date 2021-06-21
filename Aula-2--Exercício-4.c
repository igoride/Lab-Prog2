/******************************************************************/
/* Nome : Igor Yoshimitsu Ide                                     */
/* RA : 181040387                                                 */
/* Exercício-Progama 4--calcula o mdc de uma sequencia de numeros */
/* Compilador: Dev-C++ versão 5.11                                */
/******************************************************************/

#include<stdio.h>
#include<stdlib.h>

int mdc(int a,int b){
	int x;
	do{
        x=a%b;
        a=b;
        b=x;
    }while(x!=0);
    return a;
}

int main (){
	int n;
	int v[n];
	int i,x;
	
	do{
	    puts("digite quantos numeros voce quer na sequencia");
	    scanf("%d",&n);

    }while(n<0);
    

    puts("digite a sequencia de numeros inteiros nao negativos ");
	for(i=0;i<n;i++){
	    do{
	    	system("cls");
	        scanf("%d",&v[i]);
	    }while(v[i]<0);
	}
	
    for(i=0;i<n;i++){
        x=mdc(x,v[i]);
    }
	
	printf("%d",x);
	
	return 0;		
}
    


