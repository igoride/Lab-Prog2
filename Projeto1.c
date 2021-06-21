#include<stdio.h>
#include<stdlib.h>

typedef struct sencos {
	
	int grau;
	float rad;
	float sen;
	float cos;
	char ver[2];
	
}trigonometrica;

void Ler_arq_sen(float seno[]);
void Ler_arq(trigonometrica trig[]);
float grau2rad(int grau);
void Escrever_arq(trigonometrica trig[],int indice[], int c);

int main(){
	int i, j, c=0;
	float seno[20];
	trigonometrica trig[90];
	int indice[20];

	Ler_arq(trig);
	Ler_arq_sen(seno);
	
	
	
	for(i=0; i<90; i++){
		for(j=0; j<20; j++){
			if(trig[i].sen == seno[j]){
				indice[c] = i;
				c++;
			    trig[i].rad = grau2rad(i);
			    
			}else{
				if(trig[i].sen < seno[j] && trig[i+1].sen > seno[j]){
					float com1, com2;
					
					com1 = seno[j] - trig[i].sen;
					com2 = trig[i+1].sen - seno[j];
					
					if(com1 < com2){
						
						indice[c] = i;
				        c++;
						trig[i].rad = grau2rad(i);
					
					}else{
						
						indice[c] = i+1;
				        c++;
						trig[i+1].rad = grau2rad(i+1);
					}
				    
			    }
				
			}
			
		}
	}
	
   	Escrever_arq(trig, indice, c);
   	
}

float grau2rad(int grau){
	
	float g = 180;
	float rad = grau/g;
	return rad;
	
}

void Escrever_arq(trigonometrica trig[], int indice[], int c){
	int i;
	FILE *arq;
	arq = fopen("senocosseno.txt", "w");
    for(i=0;i<c;i++){
    	
    	fprintf(arq,"Rad %f \n", trig[indice[i]].rad);
		fprintf(arq,"Sen %f \n", trig[indice[i]].sen);
		fprintf(arq,"Cos %f \n", trig[indice[i]].cos);
    	fprintf(arq,"\n");
    	
	}

	
	fclose(arq);

}

void Ler_arq(trigonometrica trig[]){
	
	int i=0;
	FILE *t;
	t = fopen("trigo.txt", "r");
	
	while(!feof(t)){
		
		fscanf(t,"%d \n", &trig[i].grau );
		fscanf(t,"%f \n", &trig[i].sen);
		fscanf(t,"%f \n", &trig[i].cos);
		trig[i].rad = 10;
	    i++;
	
	}
	
	
	fclose(t);
	
}

void Ler_arq_sen(float seno[]){
    
    int i=0, j=0;
	float aux;
	FILE *s;
	s = fopen("seno.txt", "r");
	
	while(!feof(s)){
		
		fscanf(s,"%f \n", &seno[i]);
		i++;
	    
	}
	for(j=i; j<20; j++){
		seno[j]=2;
	}
	
	fclose(s);
	
}
