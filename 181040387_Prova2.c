#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*********************************************************************************/
/*Nome: Igor Yoshimitsu Ide                                                     */
/*RA: 181040387	                                                                */
/*Prova --2 ----                                                                */
/*Compilador: DevC versão 5.11                                                  */
/********************************************************************************/

typedef struct node {
     int item;
     struct node *prox;
}lista;

void insere (lista **L, int x) {
    lista *novo, *q;
    q = *L;
    novo = (lista *)malloc(sizeof(lista));
    novo->item = x;

    if (*L == NULL) {
    
	    novo->prox = NULL;
        *L = novo;
    
	}
    else {
     
	    while (q->prox != NULL) q = q->prox;

        novo->prox = q->prox;
        q->prox = novo;
     
	 }

}

//void desaloca (lista **L1,lista **L2, lista **L3 ){
//	
//	free(L1);
//	free(L2);
//	free(L3);
//	
//	
//}


lista *desaloca (lista *L){
	
	free(L);
	
	return L;
	
}

void imprime (lista *L) {
    
	lista *q;
    
	q=L;
	
	if(q==NULL){
		
		printf("NULL");
		
	}
	else{
		
		while(q != NULL){
			
			printf("%d", q->item);
			q=q->prox;
		}
	}
	
}

int Pertence(lista *L, int x) {
    lista *q; 
	 
	int repete;
    q = L;

    while (q != NULL && q->item != x) q = q->prox;

     // AQUI  => verifica se q e diferente de NULL antes de acessar conteudo 
     if (q != NULL && q->item == x) repete = 1;
     else repete = 0;

return repete;
}

lista *Intersecao_lista(lista *L1, lista *L2) {
     
	lista *x, *y, *r = NULL;
    
	int aux;

    for (y = L1; y !=NULL; y = y->prox) {
        for (x = L2; x != NULL; x = x->prox) {
            
			aux = x->item;
            
			if (Pertence(y, aux) ==  1) {
                
				if (Pertence(r, aux) == 0) insere(&r, aux);
 
            }
        }
    }
    
	return r;

}

void limpar(lista *L){
    
	lista *no = L, *aux;
	
    while (no != NULL){
        
		aux = no;
        
        free (aux);
    
        no = no->prox;
	
	}
    
	L = NULL;
}

int main () {
	
	setlocale(LC_ALL, "portuguese");
    
	lista *L1 = NULL;
    lista *L2 = NULL;
    lista *L3 = NULL;
     
    
     
	int n, i, x;
    
	puts(" Digite quantos nós tera a lista 1 \n ");
    scanf(" %d", &n);
    
    puts("\n Digite os nós da lista 1 \n ");
    for(i=0; i<n; i++){
    	
    	scanf(" %d", &x);
    	
		insere(&L1, x);
    	
	}
    
    puts("\n Lista-1\n\n");
    imprime(L1);
    
    puts("\n\n Digite quantos nós tera a lista 2 \n ");
    scanf(" %d", &n);
    
    puts("\n Digite os nós da lista 2 \n ");
    for(i=0; i<n; i++){
    	
    	scanf(" %d", &x);
    	
		insere(&L2, x);
    	
	}
    
    puts("\n\n Lista-2\n\n");
    imprime(L2);
    
	L3 = Intersecao_lista(L1, L2);
    
	puts("\n\n Interseçao\n\n");
	imprime(L3);
	
	puts("\n Limpando \n")
    limpar(L1);
    limpar(L2);
    limpar(L3);
    
    puts("\n\n");
    imprime(L1);
    puts("\n\n");
    imprime(L2);
    puts("\n\n");
    imprime(L3);
    return 0;

}
