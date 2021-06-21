#include <stdio.h>
#include <stdlib.h>

static void intercala (int p, int q, int r, int v[]){
	
   int *w;                                 //  1
   w = (int *) malloc ((r-p) * sizeof (int));     //  2
   int i = p, j = q;                       //  3
   int k = 0;                              //  4

   while (i < q && j < r) {                //  5
      if (v[i] <= v[j])  w[k++] = v[i++];  //  6
      else  w[k++] = v[j++];               //  7
   }                                       //  8
   while (i < q)  w[k++] = v[i++];         //  9
   while (j < r)  w[k++] = v[j++];         // 10
   for (i = p; i < r; ++i)  v[i] = w[i-p]; // 11
   free (w);                               // 12
}

/////////////////////////////////MERGE SORT//////////////////////////////////////////////////////////////////////////////////
                                                                                                                          //
void mergesort (int p, int r, int v[]){
   if (p < r-1) {                 // 1
      int q = (p + r)/2;          // 2
      mergesort (p, q, v);        // 3
      mergesort (q, r, v);        // 4
      intercala (p, q, r, v);     // 5
   }
}                                                                                                         //
                                                                                                             //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main (){
	
	int r, p=0;
	int v[r];
	
	puts("Digite o tamanho do vetor");
	scanf("%d", &r);
	
	puts("Digite o vetor");
	
	for(int i=0; i<r;i++){
	
	printf("Elemento [%d]:", i+1);
	scanf("%d", &v[i]);	
	}
	
	mergesort(p, r, v);
	
	for(int i=0; i<r; i++){
		
		printf("Elemento [%d] : %d ", i+1, v[i]);
	}
}
