#include<stdio.h>
#include<stdlib.h>

float Cel2Fahr(float grau);
float Fahr2Cel(float grau);

int main(){
	int opt, flag=1;
	float grau;
	
	while(flag != 0){
		printf("\n MENU Conversoes\n");
		printf("\n 1 - Celcius para fahrenheit\n");
		printf("\n 2 - Fahrenheit para Celcius \n");
		printf("\n 3 - Sair\n");
		scanf("%d", &opt);
		
		switch(opt){
			case 1 :{
				printf("\n Digite o grau em celcius\n");
				scanf("%f", &grau);
				grau = Cel2Fahr(grau);
			    printf("%f", grau);
				break;
			}
			case 2 :{
				printf("\n Digite o grau em fahrenheit\n");
				scanf("%f", &grau);
				grau = Fahr2Cel(grau);
				printf("%f", grau);
				break;
			} 
			case 3 :{
				flag = 0;
				break;
			}
		}
	}
}

float Cel2Fahr(float grau){
	return (grau*1.8)+32 ;
}

float Fahr2Cel(float grau){
	return (grau-32)*0.55 ;
}
