#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no {
    char pal[20];
    int urg;
    struct no *prox; 
} Elem;

void insereCircularLista(Elem *p0, char *x){
	
    Elem  *p;
    p = (Elem *)malloc(sizeof(Elem));
    
	strcpy(p->pal, x);
    
    if (p0 == NULL){
	    p->prox = p;
    }else{
        p->prox = (p0)->prox;
        (p0)->prox = p;
    }
    
    p = p0;
    
}

void Ler(Elem *lista){
	FILE *arq;
	arq = fopen("pacotes.dat", "r");
	int A, B, i, count = -1, j=0;
	char aux[5];
	while(!feof(arq)){
		
		fscanf(arq, "%d %s %d\n", &A, &aux, &B);
		
		if(A == 0){
			if(!strcmp("PRTY",aux)){
				insereCircularLista(lista, aux);
				count = B;
			}else{
				if(count>0){
				
				}else{
				    insereCircularLista(lista, aux);
			    }
			}	
			count --;
		}
		
	    i++;
	}
	fclose(arq);

}

void Escreve(Elem *lista){
	FILE *arq;
	arq = fopen("lidos.dat", "w");
    Elem *primeiro = lista;
  
    do{
    	
    	lista = lista->prox; 
		printf("%s\n",lista->pal);	
	    fprintf(arq,"%s\n",lista->pal);
	    
	}while(lista != primeiro);

	
	fclose(arq);
}



int main(){
	
	Elem *lista = (Elem*) malloc (sizeof(Elem));
    Elem *primeiro;
    
	Ler(lista);
	
	Escreve(lista);

}
