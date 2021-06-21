#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	
	int item;
	struct node *prox;
	
}node;

//node *Busca (int x, node *le){
//	
//	node *p;
//    p = le;
//    
//	while (p != NULL && p->item != x) 
//        
//		p = p->prox; 
//    
//	return p->prox;
//}

//void insere_i(node *le, node *aux){
//	
//	node *no;
//	
//    no=(node *)malloc(sizeof(node));
//    
//	no->item = aux;
//	no->prox=le;
//	le=no;	
//	
//	
//}

void insere (int x, node *le){
	
   node *nova;
   
   nova =(node *) malloc (sizeof (node));
   
   nova->item = x;
   
   nova->prox = le->prox;
   le->prox = nova;
   
}


void imprima (node *le) {
 
   node *p;
   
   puts("lista=");
   
   for (p = le->prox; p != NULL; p = p->prox)
        printf (" %d \n", p->item);

}

int main (){
	
	int x, i;
	
	node *le, *aux;

	le=(node*)malloc(sizeof(node));
	aux=(node*)malloc(sizeof(node));
	
	for(i=0;i<3;i++){
	
	    printf("digite o valor do %d no : ", i+1);
	    scanf("%d", &x);
	
	    insere(x, le);
	
    }
	
	imprima(le);
	
//	aux=Busca(y, le);
	
//	insere_i(le, aux);
	
//	imprima(le);
	
}
	

