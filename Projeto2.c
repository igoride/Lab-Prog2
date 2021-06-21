#include <stdio.h>
#include<stdlib.h>
#include <math.h>

void calc_centro(float x[], float y[], float *xc, float *yc, int n);//calcula o ponto central
double dist(float x, float y, float xc, float yc);//calcula a distância dos pontos.

int main() {

    int n, i=0;
    float x[n], y[n], xc, yc;
  
    FILE *arq;
	
	arq = fopen("imput.txt", "r");
	
	fscanf(arq, "%d\n", &n);
	
	while(!feof(arq)){
		
		fscanf(arq,"%f %f\n", &x[i],&y[i]);
	    i++;
	
	}
	
	fclose(arq);
	
    calc_centro(x, y, &xc, &yc, n);
  
    printf("Ponto (%f, %f)", xc, yc);

    return 0;
}

void calc_centro(float x[], float y[], float *xc, float *yc, int n) {

    float distancia[n], DM = 0, cx=0, cy=0;
    int i, MD;
    
    for (i=0; i<n; i++){//soma todos os x e y 
        cx += x[i];
        cy += y[i];
    }
    
    cx = cx/n;//faz o x e y medio
    cy = cy/n;
    
    for (i = 0; i < n; i++) {
        
        distancia[i] = dist(x[i], y[i], cx, cy);// calcula a distância entre os pontos lidos e o ponto central obtido
        
        if (DM == 0) {
        	
            DM = distancia[i];
            
        }else if(distancia[i] < DM){//o indice da menor distância é armazenado
        	
            DM = distancia[i];
            MD = i;
            
        }
    }
    
    *xc = x[MD];
    *yc = y[MD];

}

double dist(float x, float y, float cx, float cy) {

    return sqrt(((x - cx) * (x - cx)) + ((y - cy) * (y - cy)));// equação para obter a distância entre dois pontos

}


