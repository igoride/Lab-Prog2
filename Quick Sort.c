#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void QuickSort (int V[], int Esq, int Dir){
	
	int i,j,aux,x;
	//fazer o particionamento
	i=Esq;
	j=Dir;
	x=V[(i+j)/2];
	
	do{
		
		while(V[i]<x) i++;
		while(V[j]>x) j--;
		
		if(i<j){
			
			aux=V[i];
			V[i]=V[j];
			V[j]=aux;
		    
		    i++;
		    j--;
		    
		}
	    else{
	    	
	    	if(i==j){
	    		
	    		i++;
	    		j--;
	    		
			}
	    	
		}
		
	}while(i<j);
	
	if(Esq<j) QuickSort(V,Esq,j);
	if(i<Dir) QuickSort(V,i,Dir);
	
}
int main (){
     
   	 	int i,n;
   	 	int V[n];
   	 	
   	 	puts("Digite o tmanho do vetor\n");
   	 	scanf("%d", &n);
   	 	
   	 	puts("Digite os elementos do vetor\n");
   	 	
   	 	for(i=0;i<n;i++){
   	 	    
   	 	    printf("elemento [%d]:", i+1);
			scanf("%d", &V[i]);	
   	 		
		}
		
		QuickSort(V,0,n-1);
		
   	 	for(i=0;i<n;i++){
   	 	    
   	 	    printf("elemento [%d]: %d", i+1, V[i]);	
   	 		
		}		

	
}


