/*************************************************************/
/*Nome: Igor Yoshimitsu Ide                                  */
/*RA:181040387          181040387	181040387                                     */
/*Exercicio-Programa 2 - sequencial -- Binario               */
/*Compilador: DevC versão 5.11                               */
/*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <locale.h>


void GeraVetor (int v[], int n){
	
	int i;
	
	for(i=0;i<n;i++){
	
		v[i]=(double)INT_MAX * rand()/(RAND_MAX + 1.0);	
    
    }

}

double temp () {
	
	return (double) clock()/CLOCKS_PER_SEC;

}

int verificaOrdem (int *v, int n){
	
	int i,j;
	
	for(i=0;i<n-1;i++){
	
		for(j=n-1;j>i;j--){
		
			if(v[j-1]>v[j]) return 0;
	    
	    }
    
	}
	
	return 1;

}

void Insercao (int v[], int n)
{
	int i,j,x,t=0;
	
	for(i=1;i<n;i++){
		
		x=v[i];

		for(j=i-1;j>=0&&v[j]>x;j--){
			
			v[j+1]=v[j];
			t++;
		
		}
			
		v[j+1]=x;	
	
	}
	printf("\n O número de mudanças na inserção é : %d \n", t);
}

void BubbleS (int v[], int n){
	
	int i,j,aux,t=0;
	
	for(i=0;i<n-1;i++){

		for(j=n-1;j>i;j--){
		
			if(v[j-1]>v[j]){
				
				aux=v[j];
				v[j]=v[j-1];
				v[j-1]=aux;
				t++;
			
			}
	
		}
	
	}
	
	printf("\n O número de mudanças do bubble sort é : %d\n", t);

}

void Selecao (int v[], int n){
	
	int i,j,menor,ind,troca,t=0;
	
	for(i=0;i<n-1;i++){
		
		menor=v[i];
		ind=i;
		troca=0;
		
		for(j=i+1;j<n;j++){
		
			if(v[j]<menor){
				
				menor=v[j];
				ind=j;
				troca=1;
			
			}
		
		}
		
		if(troca){
			
			v[ind]=v[i];
			v[i]=menor;	
			t++;
		
		}
	
	}

	printf("\n O número de mudanças do método de seleção é %d\n", t);

}

void ShellSort (int *v, int n){
	
	// 3 ciclos e h={4,3,1}
	
	int i,j,H,c,x;
	int h[]={4,3,1};
	
	for(c=0;c<3;c++){
		
		H=h[c];
		
		for(i=H;i<n;i++){
			
			x=v[i];
			
			for(j=i-H;j>=0&&x<v[j];j=j-H){
			
				v[j+H]=v[j];
             			
			}
			
			v[j+H]=x;
		
		}	
	
	}		

}

void QuickSort (int v[], int esq, int dir){
	
	int i,j,aux,x;
	
	i=esq;
	j=dir;
	x=v[(i+j)/2];
	
	do{
		
		while(v[i]<x)i++;
		
		while(v[j]>x)j--;
		
		if(i<j){
			
			aux=v[i]; v[i]=v[j]; v[j]=aux;
			i++; j--;	
		
		}
		else{
		
			if(i==j){
			
			    i++; 
				j--;
			
			}
		
		}
	
	}while(i<j);
	
	if(j<dir) QuickSort(v,esq,j);
	
	if(i<dir) QuickSort(v,i,dir);	
}


void MergeSort (int v[], int p, int r){
	
	int q;
	
	if(p<r-1){
		
		q=(p+r)/2;
	
		MergeSort(v,p,q);
	
		MergeSort(v,q,r);
	
		intercala(v,p,q,r);	
	
	}	

}

intercala (int p, int q, int r, int v[]){
	
   int *w;
                                    
   w = (int *) malloc ((r-p) * sizeof (int));     
   
   int i = p, j = q;                       
   int k = 0;                              

   while (i < q && j < r) {                
     
	    if (v[i] <= v[j]){
	        
			w[k++] = v[i++];  
        
		}
		else{
		    
			w[k++] = v[j++];               
             
		}
   
   }                                       
   while (i < q)  w[k++] = v[i++];         
   
   while (j < r)  w[k++] = v[j++];         
   for (i = p; i < r; ++i){
        
		v[i] = w[i-p]; 
   
    }
   
   free (w);                               

}

int BuscaSequencial (int v[], int n, double x){
	
	int m;
	m=0;
	
	while(m<n&&v[m]<x) m++;
	
	if(m<n&&v[m]==x) return m;	
	else return -1;

}

int BuscaBinaria (int v[], int n, int x){
	
	int e=0,d,m;
	d=n-1;
	
	while(e<=d){
		
		m=(e+d)/2;
		if(v[m]==x) return m;
		else 
		    if(x<v[m]) d=m-1;
		else e=m+1;	
	
	}
	
	return -1;

}

int main(){
	
	setlocale(LC_ALL,"");
	
	int n, i, opcao, numero, v[100000], cont1=0, cont2=0, c=0, d=0, pos;
	
	double t1, t2, tt1, tt2, duracao;
	
	printf("\n Forneça o tempo máximo de execução do programa : ");
	scanf("%lf", &duracao);
	printf("\n Duração do progama = %.2f segundos\n", duracao);
	
	printf("\n Escolha o algoritmo a ser utilizado:\n");
	printf("\n               Bolha <1>               ");
	printf("\n              Seleção <2>              ");
	printf("\n              Inserção <3>             ");
	printf("\n             Shell Sort <4>            ");
	printf("\n             Mergesort <5>             ");
	printf("\n            Quicksort <6>              ");
	printf("\n          Todos os métodos <7>         ");
	printf("\n");
	scanf("%d", &opcao);
	
	//gera um número aleatório para ser procurado no vetor
	numero=(double) INT_MAX*rand()/(RAND_MAX+1.0);
	printf("\n Número procurado: %d \n", numero);
	
	
	switch (opcao){
		
		case 1: {
			
			printf("\n Bolha: \n");
			
			for(i=2000; tt1<duracao&&tt2<duracao; i=i+2000){
				
				GeraVetor(v,i);
				t1=temp();
				BuscaSequencial(v,i,numero);		
				t2=temp();
				tt1=t2-t1;
				t1=temp();
				BubbleS(v,i);
				
				if(verificaOrdem(v,i)==1) puts("\nVetor ordenado. \n");
				else puts("\nVetor não ordenado. \n");
				
				BuscaBinaria(v,i,numero);
				t2=temp();
				tt2=t2-t1;
			
				printf("\n Tempo Binária: %f \n",tt2);
				
				if(tt1<tt2) 
				    c++;
				else if(tt2<tt1) 
				    d++;
				if ((cont1=0 && c!=0) || (cont2=0 && d!=0)){
					
					if (cont1=1){
						
					    cont2=1;
						pos=i;
					
					}
					if(cont2=1) {
					    
						cont1=1;
						pos=i;
						
					}
					
					if(c!=0) cont1=1;
					if(d!=0) cont2=1;
				
				}
				
			}
			
			if(c>d&&d!=0) printf("\n A Busca Sequêncial compensa mais que Busca Binária até o vetor ter %d elementos \n", pos);
			else if(d>c&&c!=0) printf("\n A Busca Binária compensa mais que a Busca Sequêncial até o vetor ter %d elementos\n",pos);
			else if(c>d&&d==0) puts("\n A Busca Sequêncial compensa mais em todos os casos.\n");
			else if(d>c&&c==0) puts("\n A Busca Binária compensa mais em todos os casos.\n");
			
			break;
		
		}
		
		case 2: {
			
			printf("\n Seleção: \n");
			
			for(i=2000;tt1<duracao&&tt2<duracao;i=i+2000){
				
				GeraVetor(v,i);
				t1=temp();
				BuscaSequencial(v,i,numero);		
				t2=temp();
				tt1=t2-t1;
				t1=temp();
				Selecao(v,i);
				
				if(verificaOrdem(v,i)==0) puts("\nVetor ordenado. \n");
				else puts("\nVetor não ordenado. \n");
				
				BuscaBinaria(v,i,numero);
				t2=temp();
				tt2=t2-t1;
				printf("\n Tempo Binária: %f \n",tt2);
				
				if (tt1<tt2)
				    c++;
				else if (tt2<tt1) 
				    d++;
				if ((cont1=0&&c!=0)||(cont2=0&&d!=0)){
					if (cont1=1){
					    
						cont2=1;
						pos=i;
						
						}
					if (cont2=1){
	
					    cont1=1;
						pos=i;
						
					}
					
					if(c!=0) cont1=1;
					if(d!=0) cont2=1;
				
				}
			
			}
			
			if(c>d&&d!=0) printf("\n A Busca Sequêncial compensa mais que a Busca Binária até o vetor ter %d elementos\n",pos);
			else if(d>c&&c!=0) printf("\n A Busca Binária compensa mais que a Busca Sequêncial até o vetor ter %d elementos\n",pos);
			else if(c>d&&d==0) puts("\n A Busca Sequêncial compensa mais em todos os casos.\n");
			else if(d>c&&c==0) puts("\n A Busca Binária compensa mais em todos os casos.\n");
		
			break;
		
		}
	
		case 3: {
			
			printf("\n Inserção: \n");
			
			for(i=2000;tt1<duracao&&tt2<duracao;i=i+2000){
				
				GeraVetor(v,i);
				t1=temp();
				BuscaSequencial(v,i,numero);		
				t2=temp();
				tt1=t2-t1;
				t1=temp();
				Insercao(v,i);
				
				if(verificaOrdem(v,i)==1) puts("\n Vetor ordenado. \n");
				else puts("\n Vetor não ordenado. \n");
				
				BuscaBinaria(v,i,numero);
				t2=temp();
				tt2=t2-t1;
				printf("\n Tempo Binária: %f \n",tt2);
				
				if(tt1<tt2) 
				    c++;
				else if(tt2<tt1) 
				    d++;
				if((cont1=0&&c!=0)||(cont2=0&&d!=0)){
					
					if (cont1=1){
					
					    cont2=1;
						pos=i;
						
					}
					if (cont2=1){
					    
						cont1=1;
						pos=i;
						
					}
					
					if(c!=0) cont1=1;
					if(d!=0) cont2=1;
				
				}
			
			}
			
			if(c>d&&d!=0) printf("\n A Busca Sequêncial compensa mais que a Busca Binária até o vetor ter %d elementos\n",pos);
			else if(d>c&&c!=0) printf("\n A Busca Binária compensa mais que a Busca Sequêncial até o vetor ter %d elementos\n",pos);
			else if(c>d&&d==0) puts("\n A Busca Sequêncial compensa mais em todos os casos.\n");
			else if(d>c&&c==0) puts("\n A Busca Binária compensa mais em todos os casos.\n");
			
			break;
		
		}
		
		case 4:{
			
			printf("\n Shell Sort: \n");
			
			for(i=2000;tt1<duracao&&tt2<duracao;i=i+2000){
				
				GeraVetor(v,i);
				t1=temp();	
				BuscaSequencial(v,i,numero);		
				t2=temp();
				tt1=t2-t1;
				t1=temp();
				ShellSort(v,i);
				
				if(verificaOrdem(v,i)==1) puts("\n Vetor ordenado. \n");
				else puts("\n Vetor não ordenado. \n");
				
				BuscaBinaria(v,i,numero);
				t2=temp();
				tt2=t2-t1;
				printf("\n Tempo Binária: %f \n",tt2);
				
				if(tt1<tt2) 
				    c++;
			    else if(tt2<tt1) 
				    d++;
				if((cont1=0&&c!=0)||(cont2=0&&d!=0)){
					
					if(cont1=1){
					
					    cont2=1;
						pos=i;
					
					}
					if(cont2=1){
					    
						cont1=1;
						pos=i;
						
					}
					
					if(c!=0) cont1=1;
					if(d!=0) cont2=1;
				
				}
			
			}
			
			if(c>d&&d!=0) printf("\n A Busca Sequêncial compensa mais que a Busca Binária até o vetor ter %d elementos\n",pos);
			else if(d>c&&c!=0) printf("\n A Busca Binária compensa mais que a Busca Sequêncial até o vetor ter %d elementos\n",pos);
			else if(c>d&&d==0) puts("\n A Busca Sequêncial compensa mais em todos os casos.\n");
			else if(d>c&&c==0) puts("\n A Busca Binária compensa mais em todos os casos.\n");
			
			break;
		
		}
		
		case 5:{
		
			printf("\n Merge Sort: \n");
			
			for(i=2000;tt1<duracao&&tt2<duracao;i=i+2000){
				
				GeraVetor(v,i);
				t1=temp();
				BuscaSequencial(v,i,numero);		
				t2=temp();
				tt1=t2-t1;
				t1=temp();
				MergeSort(v,0,i);
				
				if(verificaOrdem(v,i)==1) puts("\n Vetor ordenado. \n");
				else puts("\n Vetor não ordenado. \n");
				
				BuscaBinaria(v,i,numero);
				t2=temp();
				tt2=t2-t1;
				printf("\n Tempo Binária: %f \n",tt2);
				
				if(tt1<tt2) 
				    c++;
				else if(tt2<tt1) 
				    d++;
				if((cont1=0&&c!=0)||(cont2=0&&d!=0)){
					
					if(cont1=1){
					    
						cont2=1;
						pos=i;
						
					}
					if(cont2=1){
					    
						cont1=1;
						pos=i;
						
					}
					
					if(c!=0) cont1=1;
					if(d!=0) cont2=1;
			
				}
		
			}
		
			if(c>d&&d!=0) printf("\n A Busca Sequêncial compensa mais que a Busca Binária até o vetor ter %d elementos\n",pos);
			else if(d>c&&c!=0) printf("\n A Busca Binária compensa mais que a Busca Sequêncial até o vetor ter %d elementos\n",pos);
			else if(c>d&&d==0) puts("\n A Busca Sequêncial compensa mais em todos os casos.\n");
			else if(d>c&&c==0) puts("\n A Busca Binária compensa mais em todos os casos.\n");
		
			break;
		
		}
		
		case 6: {
		
			printf("\n Quicksort: \n");
		
			for(i=2000;tt1<duracao&&tt2<duracao;i=i+2000){
				
				GeraVetor(v,i);
				t1=temp();
				BuscaSequencial(v,i,numero);		
				t2=temp();
				tt1=t2-t1;
				t1=temp();
				QuickSort(v,0,i-1);
				
				if(verificaOrdem(v,i)==1) puts("\n Vetor ordenado. \n");
				else puts("\n Vetor não ordenado. \n");
				
				BuscaBinaria(v,i,numero);
				t2=temp();
				tt2=t2-t1;
				printf("\n Tempo Binária: %f \n",tt2);
				
				if(tt1<tt2) 
		            c++;
				else if(tt2<tt1) 
				    d++;
				if((cont1=0&&c!=0)||(cont2=0&&d!=0)){
					
					if(cont1=1){
					    
						cont2=1;
						pos=i;
						
					}
					if(cont2=1){
					    
						cont1=1;
						pos=i;
						
					}
					
					if(c!=0) cont1=1;
					if(d!=0) cont2=1;
				
				}
			
			}
			
			if(c>d&&d!=0) printf("\n A Busca Sequêncial compensa mais que a Busca Binária até o vetor ter %d elementos\n",pos);
			else if(d>c&&c!=0) printf("\n A Busca Binária compensa mais que a Busca Sequêncial até o vetor ter %d elementos\n",pos);
			else if(c>d&&d==0) puts("\n A Busca Sequêncial compensa mais em todos os casos.\n");
			else if(d>c&&c==0) puts("\n A Busca Binária compensa mais em todos os casos.\n");
			
			break;
		
		}
		
		case 7:{
		
			break;
		
		}	
	
	}		

}
