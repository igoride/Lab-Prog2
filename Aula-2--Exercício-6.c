/******************************************************************/
/* Nome : Igor Yoshimitsu Ide                                     */
/* RA : 181040387                                                 */
/* Exercício-Progama 6     --  ve se um numero se encaixa a outro */
/* Compilador: Dev-C++ versão 5.11                                */
/******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cont (int a){
	int x=0;
	
	while(a!=0){
		a=a/10;
		x++;
	}
	return x;
}

int encaixa (int a,int b){
	int na=a;
	int nb=b;
	int e;
	int Ta=cont(a);
	int Tb=cont(b);
	while(Ta>Tb){
		e= pow(10,Ta-1);
		na=na%e;
		Ta--;		
	}
	if(na==nb){
		return 1;
	}
	else{
		return 0;
	}
}

int main (){
	int x,y;
	int maior,menor;
	int Tma,Tme;
	int verificacao=0;
	
	puts("digite dois numeros");
	scanf("%d %d",&x,&y);
	
	if(x>y){
		maior=x;
		menor=y;
	}
	else if(x<y){
		maior=y;
		menor=x;
	}
	
	Tma=cont(maior);
	Tme=cont(menor);
	
	while(Tma>=Tme){
		
		verificacao=encaixa(maior,menor);
		
		if(verificacao==1){
			Tma=0;
		}
		else{
			maior=maior/10;
		}
		Tma--;
	}
		
	if(verificacao==1){

        if(menor == y){
            printf("%d e segmento de %d",y,x);
        }
        else{
            printf("%d e segmento de %d",x,y);
        }
        
    }
    else{
        puts("Um nao e segmento do outro");
    }
}
