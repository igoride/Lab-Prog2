#include <stdio.h>
#include <stdlib.h>

void Interc (int a[], int b[], int c[], int m, int n){
	
	int i,j,k;
	int c[r-p];
	
	i=p;
	j=q;
	k=0;
	
	while((i<q) && (j<r)){
		
		if(a[i]<=a[j]){
			
			c[k++]=a[i++];
			
		}
		else{
			
			c[k++]=a[j++];
			
		}
		
	}
	
	while(i<q){
		
		c[k++]=a[i++];
		
	}
	
	while(j<r){
		
		c[k++]=a[j++];
		
	}
	
	puts("\nVetor c:\n");
		
   	for(i=0;i<k;i++){
   	 	    
   	    a[i+p]=c[i];	
   	 		
	}		
	
}

int main (){
     
   	 	int i,n,m;
   	 	int a[n];
   	 	
   	 	puts("Digite o tmanho do vetor a\n");
   	 	scanf("%d", &n);

   	 	puts("Digite o tmanho do vetor b\n");
   	 	scanf("%d", &m);
			   	 	
   	 	puts("Digite os elementos do vetor a\n");
   	 	
		for(i=0;i<n;i++){
   	 	    
   	 	    printf("elemento [%d]:", i+1);
			scanf("%d", &a[i]);	
   	 		
		}	
		
		Interc(a,b,c,m,n);
	
}
