#include<stdio.h>
#include<string.h>
#include<stdlib.h>



void convert_str(char a[],float V[] ){
	
	int i, j, t, lim, lim1, lim2, flag[2];
	float V1[4], ex, ey=1.0;

    t=strlen(a);
    
    char aux[t], aux1[t];
    
    for(i=1; i<t; i++){
    	if((a[i]== '+') || (a[i] == '-')){
    		lim=i;
		}
	}
//procura a posição do + ou o - Ex a1a2+b1i lim = 2;
	
	if(a[0] == '-'){//caso o numero comece com -
		
		flag[0]=1;
		
		for(i=1; i<lim; i++){
			if(a[i] == '.'){
				lim1=i; 
				for(j=lim1+1; j<lim; j++){
			        aux1[j-(lim1+1)]=a[j];		
		        }                             		
				V1[1]=atoi(aux1);		
            }
			if(a[i] == ','){
				lim1=i;
				for(j=lim1+1; j<lim; j++){
			        aux1[j-(lim1+1)]=a[j];		
		        } 				
		        V1[1]=atoi(aux1);
			}	
		}
		for(i=1;i<lim1; i++){
			aux[i-1]=a[i];
		}
		V1[0]=atoi(aux);
	}else{// caso normal
	
	    flag[0]=0;
	
		
	    for(i=0; i<lim; i++){
		    if(a[i] == '.'){
			    lim1=i; 
			    for(j=lim1+1; j<lim; j++){
		            aux1[j-(lim1+1)]=a[j];		
	            }
			    V1[1]=atoi(aux1);	                              				
            }
		    if(a[i] == ','){
			    lim1=i;
			    for(j=lim1+1; j<lim; j++){
		            aux1[j-(lim1+1)]=a[j];		
	            }
			    V1[1]=atoi(aux1);	 				
		    }	
	    }
	    for(i=0;i<lim1; i++){
			aux[i]=a[i];
		}
	    V1[0]=atoi(aux); 
    }
//        printf("\n\n%s- aux\n\n", aux);
    for(i=lim1+1;i<lim;i++){
    	ey*=10;
	}
	ex=V1[1]/ey;
    V[0]=V1[0]+ex;
    
    for(i=0;i<t;i++){
	    aux[i]=0;
    }// limpa aux
    for(i=0;i<t;i++){
	    aux1[i]=0;
    }// limpa aux1

//	Essa parte do programa acha a parte imaginaria do numero e a transforma em double
	if(a[lim] == '-'){//caso o numero comece com -
		
		flag[1]=1;
		
		for(i=lim+1; i<t-1; i++){
			if(a[i] == '.'){
				lim2=i;  
				for(j=lim2+1; j<t-1; j++){
			        aux1[j-(lim2+1)]=a[j];		
		        }     
					V1[3]=atoi(aux1);                           
            }
			if(a[i] == ','){
				lim2=i;
				for(j=lim2+1; j<t-1; j++){
			        aux1[j-(lim2+1)]=a[j];		
		        }   
		        	V1[3]=atoi(aux1); 
			}	
			aux[i-(lim+1)]=a[i];
		}	
//		for(i=lim+1;i<lim2; i++){
//			aux[i-(lim+1)]=a[i];
//		}
		
		V1[2]=atoi(aux);                         
	}else{// caso normal
	
	    flag[0]=0;
	
	    for(i=lim+1; i<t-1; i++){
		    if(a[i] == '.'){
			    lim2=i;
	            for(j=lim2+1; j<t-1; j++){
		            aux1[j-(lim2+1)]=a[j];
		
	            }
	            V1[3]=atoi(aux1);
		    }
		    if(a[i] == '.'){
			    lim2=i;
		        for(j=lim2+1; j<t-1; j++){
		            aux1[j-(lim2+1)]=a[j];
		
                }	
                V1[3]=atoi(aux1);
		    }
		    aux[i-(lim+1)]=a[i];
		    
	    }
//	    for(i=lim+1;i<lim2; i++){
//			aux[i-(lim+1)]=a[i];
//		}
	    V1[2]=atoi(aux);
	}
	for(i=lim2+2;i<t-2;i++){
		ey= ey * 10 ;
	}

    ex=V1[3]/ey;
    V[1]=V1[2]+ex;

    if(flag[0] == 1){
    	V[0]=-V[0];
	}	
	if(flag[1] == 1){
		V[1]=-V[1];
	}

	
    puts("\n");
    for(i=0;i<t;i++){
	    aux1[i]=0;
    }// limpa aux1
    for(i=0;i<t;i++){
	    aux[i]=0;
    }// limpa aux
    for(i=0;i<4;i++){
    	V1[i]=0;
	}
	for(i=0;i<t;i++){
    	a[i]=0;
	}

}
void conv_vet(float A[], char c[]){
	
	char b[10000],a[10000];
	
	sprintf(b, "%f", A[0]);
    printf("\n%s", b);
    sprintf(a, "%f", A[1]);
	printf("\n%s ", a);
    
    if(A[1]>0 || A[1] == 0){
    	strcat(b,"+");
    	strcat(b,a);
	}else{
		strcat(b, a);
	}
	strcat(b,"i");
//    printf("\n%s",b);
    
    strcpy(c, b);
}

void soma() {
	int i, a1, b1, x, lenc;
    float A[2], B[2], S[2], C[i];
    
    printf(" SOMA DE NUMEROS COMPLEXOS \n\n");
    printf(" O numero complexo deve ser da forma a+bi\n\n");
    
    puts("digite o tamanho dos numeros complexos \n");
    scanf("%d", &x);
    
    char a[x+4], b[x+4], c[x+4];
    puts("Digite o primeiro numero complexo, na forma a+bi\n");
    scanf("%s", a);
    fflush(stdin);
    
    puts("\nDigite o segundo complexo, na forma a+bi\n");
    scanf("%s", b);
    fflush(stdin); 
	
	convert_str(a, A);
    for(i=0;i<2;i++){
    	printf("A%d : %f ",i, A[i]);
	}
	convert_str(b, B);
	puts("\n");
    for(i=0;i<2;i++){
    	printf("B%d : %f ",i, B[i]);
	}    
    for(i=0;i<2;i++){
    	C[i]=A[i]+B[i];
    	printf("C[%d]=%f",i, C[i]);
	}
    
    conv_vet(C, c);
    
    printf("\n%s + %s = %s", a, b, c);
    getchar();
}
void subtracao() {
	int i, a1, b1, x;
    float A[2], B[2], C[i];
    
    printf(" SUBTRACAO DE NUMEROS COMPLEXOS \n\n");
    printf(" O numero complexo deve ser da forma a+bi\n\n");
    
    puts("Digite o tamanho dos numeros complexos \n");
    scanf("%d", &x);
    
    char a[x+4], b[x+4], c[x+4];
    puts("Digite o primeiro numero complexo, na forma a+bi\n");
    scanf("%s", a);
    fflush(stdin);
    
    puts("Digite o segundo complexo, na forma a+bi\n");
    scanf("%s", b);
    fflush(stdin); 
	
	convert_str(a, A);
    for(i=0;i<2;i++){
    	printf("A%d : %f ",i, A[i]);
	}
	convert_str(b, B);
	puts("\n");
    for(i=0;i<2;i++){
    	printf("B%d : %f ",i, B[i]);
	}    
    for(i=0;i<2;i++){
    	C[i]=A[i]-B[i];
    	printf("C[%d]=%f",i, C[i]);
	}
    
    conv_vet(C, c);
    
    printf("\n%s - %s = %s", a, b, c);
    getchar();
}

void multiplicacao() {
	
    float A[2],B[2],C[2];
    int i, x;
   
//   system ("clear");
    printf(" MULTIPLICACAO DE NUMEROS COMPLEXOS \n\n");
    printf(" O numero complexo deve ser da forma a+bi\n\n");
    puts("Insira o tamanho dos numeros complexos\n");
    scanf("%d", &x);
    
	char a[x+4], b[x+4], c[x+4];
	puts("Insira o primeiro numero complexo\n");
    scanf("%s", a);
    puts("Insira o segundo numero complexo\n");
    scanf("%s", b);
    printf("A = %s \nB = %s", a, b);
    convert_str(a, A);
    convert_str(b, B);
    
    C[0] = ((A[0]*B[0]) - (A[1]*B[1]));
    C[1] = (A[0]*B[1] + B[0]*A[1]);
   
    conv_vet(C, c);
    
    printf("\n%s * %s = %s", a, b, c);
     
    getchar();
}


void escalar(){
    float A[2], C[2], k;
    int i, x;
   
//    system ("clear");
    printf(" MULTIPLICACAO POR ESCALAR \n\n");
    printf(" O numero complexo deve ser da forma a+bi\n\n");
    
    puts("digite o tamanho do numero complexo \n");
    scanf("%d", &x);
    
    char a[x+4], c[x+4];
    puts("Digite o numero complexo, na forma a+bi\n");
    scanf("%s", a);
    fflush(stdin);
	
	puts("Digite o escalar\n");
	scanf("%f", &k);
	printf("\n k = %f", k);
	convert_str(a, A);
	
    for(i=0;i<2;i++){
    	printf("A%d : %f ",i, A[i]);
	}
	
    for (i=0;i<2;i++) {
        C[i]=A[i]*k;
    }
    for(i=0;i<2;i++){
        printf(" \n\n%f ", C[i]);
	}
    conv_vet(C, c);
    
    printf("\n%s * %f = %s", a, k, c);
 
    getchar();
}

void divisao() {
    float A[2],B[2],C[2];
    int i, x;
   
    system ("clear");
    puts(" DIVISAO DE NUMEROS COMPLEXOS \n\n");
    puts(" O numero complexo deve ser da forma a+bi \n\n");
    puts("Digite o tamanho dos numeros commplexos : ");
    scanf("%d", &x);
    char a[x+4], b[x+4], c[x+4];
    puts("Insira o primeiro numero complexo : ");
    scanf("%s", a);
    puts("Insira o segundo numero complexo");
    scanf("%s", b);
    printf("%s \n%s", a , b);
    convert_str(a, A);
    convert_str(b, B);
    
    for(i=0; i<2; i++){
       	printf("A[%d] : %f", i, A[i]);
   	    printf("B[%d] : %f", i, B[i]);
   }
   
    C[0]= (((A[0]*B[1]) + (A[1]*B[1]))/(B[0]*B[0] + B[1]*B[1]));
    C[1]= ((-(A[1]*B[0]) + (A[0]*B[1]))/(B[0]*B[0] + B[1]*B[1]));
   
    conv_vet(C, c);
   
    printf("\n%s / %s = %s \n", a, b, c);
    getchar();
}

float escreve_vet(float Vet[]){
	int i;
	
	for(i=0; i<2; i++){
		printf("\n insira o termo %d do numero complexo ", i+1);
		scanf("%f", &Vet[i]);
	}
	
	getchar();
}   

void imprime_vet(float Vet[]){
	int i;
	char a;
	for(i=0; i<2; i++){
		printf("Vet[%d] : %f", i, Vet[i]);
	}
	getchar();
}

void Menu(){
	char opc;
    int token=0;
    float Vetor[2];

    do {

//        system("clear"); 
        puts("  CALCULADORA DE NUMEROS COMPLEXOS \n\n");
        puts(" [1] Soma de numeros complexos \n");
        puts(" [2] Subtracao de numeros complexos \n");
        puts(" [3] Multiplicacao de complexo por Escalar \n");
        puts(" [4] Produto entre dois complexos \n");
        puts(" [5] Divisao entre dois complexos \n");
        puts(" [6] Escrever um complexo em um vetor \n");
        puts(" [7] Imprmir um complexo \n");
        puts(" [8] Sair \n");
        opc=getchar();
        switch (opc) {
            case '1': {
                soma();
   
                break;
            }
            case '2': {
                subtracao();
    
                break;
            }
            case '3': {
                escalar();
    
                break;
            }
            case '4': {
                multiplicacao();
    
                break;
            }
            case '5': {
                divisao();

                break;
            }
            case '6': {
               escreve_vet(Vetor);
                
                break;
            }
            case '7': {
                imprime_vet(Vetor);
    
                break;
            }
            case '8': {
                printf (" Finalizando aplicacao ... \n\n");
                token=1;
            }
            break;
            default: {
                token=0;
                printf (" Opcao Invalida, voltando ao menu... \n");
                break;
            }
   
        }
    }while (token==0);
}

int main(){
//soma();
	Menu();

}
