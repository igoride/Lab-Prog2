#include <stdio.h>
#include <stdlib.h>

void Inter (int a[], int b[], int c[], int m, int n){
	
	int i,j,k;
	
	i=0;
	j=0;
	k=0;
	
	while((i<m) && (j<n)){
		
		if(a[i]<=b[j]){
			
			c[k++]=a[i++];
			
		}
		else{
			
			c[k++]=b[j++];
			
		}
		
	}
	
	while(i<m){
		
		c[k++]=a[i++];
		
	}
	
	while(j<n){
		
		c[k++]=b[j++];
		
	}
	
}

int main (){
     
   	 	int i,n,m;
   	 	int a[n],b[m],c[m+n];
   	 	
   	 	puts("Digite o tmanho do vetor a\n");
   	 	scanf("%d", &n);

   	 	puts("Digite o tmanho do vetor b\n");
   	 	scanf("%d", &m);
			   	 	
   	 	puts("Digite os elementos do vetor a\n");
   	 	
		for(i=0;i<n;i++){
   	 	    
   	 	    printf("elemento [%d]:", i+1);
			scanf("%d", &a[i]);	
   	 		
		}
   	 	puts("Digite os elementos do vetor b\n");
   	 	
		for(i=0;i<m;i++){
   	 	    
   	 	    printf("elemento [%d]:", i+1);
			scanf("%d", &b[i]);	
   	 		
		}		
		
		Inter(a,b,c,m,n);
		
		puts("Vetor a:\n");
		
   	 	for(i=0;i<n;i++){
   	 	    
   	 	    printf("elemento [%d]: %d ", i+1, a[i]);	
   	 		
		}		

		puts("\nVetor b:\n");
		
   	 	for(i=0;i<m;i++){
   	 	    
   	 	    printf("elemento [%d]: %d ", i+1, b[i]);	
   	 		
		}		

		puts("\nVetor c:\n");
		
   	 	for(i=0;i<n+m;i++){
   	 	    
   	 	    printf("elemento [%d]: %d ", i+1, c[i]);	
   	 		
		}		
	
}

