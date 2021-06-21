#include <stdlib.h>
#include <stdio.h>

int Bola_piramide(int altura){
	
	if(altura == 0){
		return 0;
	}else{
		return altura + Bola_piramide(altura-1);
	}
	
	
}

main(){
	int altura = 5, quant;
	
	quant =  Bola_piramide(altura);
	
	printf("%d", quant);
}
