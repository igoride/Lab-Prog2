#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int partidas;
	int i;
	
	scanf("%i", &partidas);
	if(partidas < 0 || partidas >1000){
		return 0;
	}
	
	int linhas[partidas][2];
	int result;
	
	for(i=0; i<partidas; i++){
		scanf("%i", &linhas[i][0]);
		if(linhas[i][0]<0){
			return 0;
		}
		scanf("%i", &linhas[i][1]);
		if(linhas[i][1]>5){
			return 0;
		}
	}	
	for(i=0; i<partidas; i++){
		result = linhas[i][0] + linhas[i][1];
		if(result%2 == 0){
			printf("A\n");
		}else{
			printf("B\n");
		}
	}
}
