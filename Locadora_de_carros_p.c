#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct dado {
	char categoria[200];
	char inicio[11];
	char fim[11];
	int Km;
	int id;
	char placa[8];
	char modelo[100];
	char fabricante[200];
	char disp[2];
	int ocp;
	char ar[2];
	
}dados;

void zera_id(dados carro[]){
	int i;
	for(i=0; i<900; i++){
		carro[i].id=0;
	}
}

int list(dados carro[]){
	int i;
	for(i=0; i<900; i++){
		if(carro[i].id == 0){
			return i;
		}
	}
}

int Busca_id(int idr, dados carro[]){
	int i;
	for(i=0; i<900; i++){
		if(carro[i].id == idr){
			return i;
		}
	}
}

int Busca_id_igual(int idr, dados carro[]){
	int i, count=0;
	for(i=0; i<900; i++){
		if(carro[i].id == idr){
			count++;
		}
	}
	if(count>=2){
		return idr;
	}
	else return -1;
}

void Inserir(struct dado carro[] ){
	int a, b;
	dados car;
	
	a=list(carro);
    do{
	
        puts("Insira o id do carro\n");
        scanf("%d", &carro[a].id);
        b=Busca_id_igual(carro[a].id, carro);
        if(carro[a].id == carro[b].id){
  	        puts("carros com id´s iguais por favor digite outro\n");
        }
    }while(carro[a].id == carro[b].id);
        
		puts("Insira a placa do carro\n");
       
        scanf("%s", carro[a].placa);
         fflush(stdin);
        puts("Insira o fabricante do carro\n");
        
        scanf("%s", carro[a].fabricante);
        fflush(stdin);
        puts("Insira o modelo do carro\n");
        
        scanf("%s", carro[a].modelo);
        fflush(stdin);
        puts("O carro esta disponivel?(s/n)\n");
        
        scanf("%s", carro[a].disp);
       fflush(stdin);
        puts("Insira a categoria do carro\n");
        
        scanf("%s", carro[a].categoria);
       fflush(stdin);
        puts("Insira o numero de passageiros comportados\n");
        
        scanf("%d", &carro[a].ocp);
       fflush(stdin);
        puts("O carro possui ar condicionado? (s/n)");
        
		scanf("%s", carro[a].ar);
	    fflush(stdin);
	    puts("Insira a quilometragem do carro\n");
        scanf("%d", &carro[a].Km);
        fflush(stdin);
        
        if(strcmp(carro[a].disp, "S") == 1){
        	strcpy(carro[a].inicio,"0/0/0");
	        strcpy(carro[a].fim,"0/0/0");
        	
		}else{
			puts("Insira a data de início da reserva(dd/mm/aa)\n");
	    scanf("%s", carro[a].inicio);
	    puts("Insira a data do termino da reserva(dd/mm/aa)\n");
	    scanf("%s", carro[a].fim);
			
		}
}


void Remover(dados carro[]){
	int idr, a, b, i;
	puts("Insira o id do carro a ser removido");
	scanf("%d", &idr);
	a=Busca_id(idr, carro);
	b=list(carro);
	
	for(i=a; i<b; i++){
	strcpy(carro[i].fabricante,carro[i+1].fabricante );
		carro[i].id = carro[i+1].id;
	strcpy(carro[i].categoria, carro[i+1].categoria );
		carro[i].Km = carro[i+1].Km;
	strcpy(carro[i].fim, carro[i+1].fim );
	strcpy(carro[i].inicio, carro[i+1].inicio );
	}
	puts("\n");
}


void Listar_tds(dados carro[]){
	int i, a;
	a=list(carro);
	
	for(i=0; i<a; i++){
		printf(" Id = %d \n Placa: %d \n Fabricante : %s \n Modelo : %s \n Disponibilidade : %s \n Categoria = %s \n Capacidade : %d \n Ar Condicionado : %s \n Quilometragem = %d \n Reserva\n Inicio = %s   Fim = %s", carro[i].id, carro[i].placa, carro[i].fabricante, carro[i].modelo, carro[i].disp,  carro[i].categoria, carro[i].ocp, carro[i].ar, carro[i].Km, carro[i].inicio, carro[i].fim);
	    puts("\n");
	}
	
	getchar();
	
}

void Listar_disp(dados carro[]){
	int i, a;
	a=list(carro);
	
	for(i=0; i<a; i++){
	    if(strcmp(carro[i].disp, "N") == 1){
		    printf(" Id = %d \n Placa: %d \n Fabricante : %s \n Modelo : %s \n Disponibilidade : %s \n Categoria = %s \n Capacidade : %d \n Ar Condicionado : %s \n Quilometragem = %d \n", carro[i].id, carro[i].placa, carro[i].fabricante, carro[i].modelo, carro[i].disp,  carro[i].categoria, carro[i].ocp, carro[i].ar, carro[i].Km);
	        puts("\n");
	    }
	}
	getchar();
	
}

void Listar_cat(dados carro[]){
	char cat[30];
	int i, a;
	
	a=list(carro);
	
	puts("Insira a categoria dos veículos a serem listados\n");
	scanf("%s", cat);
	for(i=0; i<a; i++){
	    if(strcmp(carro[i].categoria, cat) == 0){
		    printf(" Id = %d \n Placa: %d \n Fabricante : %s \n Modelo : %s \n Disponibilidade : %s \n Categoria = %s \n Capacidade : %d \n Ar Condicionado : %s \n Quilometragem = %d \n Reserva\n Inicio = %s   Fim = %s", carro[i].id, carro[i].placa, carro[i].fabricante, carro[i].modelo, carro[i].disp,  carro[i].categoria, carro[i].ocp, carro[i].ar, carro[i].Km, carro[i].inicio, carro[i].fim);
	        puts("\n");
	        if(strcmp(carro[i].disp, "S") == 1){
	        	printf("Reserva:\n\n  Início : %s   |  Fim : %s", carro[i].inicio, carro[i].fim);
			}
	    }
	}
getchar();
	
}

int Ver(dados carro[]){
	int idr, a;
	puts("Insira o id do carro a ser verificado\n");
	scanf("%d", &idr);
	a=Busca_id(idr, carro);
	
	if(strcmp(carro[a].disp, "S") == 1){
		
		puts("o carro não esta reservado\n");
		
	}else{
		printf(" início : %s \n termino : %s", carro[a].inicio, carro[a].fim);
	}
	getchar();
	
}

void Reservar(dados carro[]){
	int idr, a;
	
	puts("Insira o id do carro a ser reservado\n");
	scanf("%d", &idr);
	
	a=Busca_id(idr, carro);
	
	if(strcmp(carro[a].disp, "S") == 1){
		
		puts("o carro já esta reservado");
	

	}else{
		
	    puts("Insira a data de início da reserva(dd/mm/aa)\n");
	    scanf("%s", carro[a].inicio);
	    puts("Insira a data do termino da reserva(dd/mm/aa)\n");
	    scanf("%s", carro[a].fim);
	    strcpy(carro[a].disp, "N");
	
	}
	
	
}

void Liberar(dados carro[]){
	int idr, a;
	
	puts("Insira o id do carro a ser retirado a reserva\n");
	scanf("%d", &idr);
	
	a=Busca_id(idr, carro);
	
	strcpy(carro[a].inicio,"0/0/0");
	strcpy(carro[a].fim,"0/0/0");
	strcpy(carro[a].disp, "N");
}
void Ler_arq(dados carro[]){
	int i=0;
	FILE *arq;
	arq = fopen("listacarros.dat", "r");
	
	while(!feof(arq)){
		fscanf(arq, "%d %s %s %s \n", &carro[i].id, carro[i].placa, carro[i].fabricante, carro[i].modelo );
		fscanf(arq,"%s %s %d %s \n", &carro[i].disp, carro[i].categoria, &carro[i].ocp, carro[i].ar);
		fscanf(arq, "%d \n", &carro[i].Km);
		fscanf(arq,"%s %s \n", carro[i].inicio, carro[i].fim);
		
	    i++;
	
	}
	
	fclose(arq);
	
}

void Escrever_arq(dados carro[]){
	int i, a;
	FILE *arq;
	arq = fopen("listacarros.dat", "w");

    a=list(carro);
    
    for(i=0;i<a;i++){
    	fprintf(arq, "%d %s %s %s \n", carro[i].id, carro[i].placa, carro[i].fabricante, carro[i].modelo );
		fprintf(arq,"%s %s %d %s \n", carro[i].disp, carro[i].categoria, carro[i].ocp, carro[i].ar);
		fprintf(arq, "%d \n", carro[i].Km);
		fprintf(arq,"%s %s \n", carro[i].inicio, carro[i].fim);
    	
	}

	
	fclose(arq);

}

int main(){
	dados carro[900];
	zera_id(carro);
    setlocale(LC_ALL,"");
	int op, T=1;
    Ler_arq(carro);
    
    do{
    getchar();
    	puts("Locadora de carros\n\n");
	    puts("1  -- Iserir novo veiculo no sistema\n");
	    puts("2  -- Remover veículo do sistema\n");
        puts("3  -- Listar todos os veículos\n");
        puts("4  -- Listar veículos disponiveis\n");
        puts("5  -- Listar veículos por categoria\n");
        puts("6  -- Verifica a devolução de um veículo\n");
        puts("7  -- Reserva de um veículo\n");
        puts("8  -- Liberar a reserva de um veículo\n");
        puts("9  -- Fechar aplicaçâo\n");
    	puts("Digite a opçâo desejada\n ");
    	
    	scanf("%d", &op);
        switch(op){
    	
    	    case 1 : 1 ;{
    		    Inserir(carro);
			    break;
		    }
		    case 2 : 2;{
			    Remover(carro);
			    break;
		    }
		    case 3 : 3;{
			    Listar_tds(carro);
			    break;
		    }
		    case 4 : 4;{
			    Listar_disp(carro);
			    break;
		    }
	    	case 5 : 5;{
			    Listar_cat(carro);
			    break;
		    }
		    case 6 : 6;{
			    Ver(carro);
			    break;
		    }
		    case 7 : 7;{
		    	Reservar(carro);
				break;
		    }
		    case 8 : 8;{
				Liberar(carro);
				break;
			}
			case 9 : 9;{
				 T = 0;
			    break;
			}
			default :
				puts("Entrada invalida");
				break;
		 
	    }
    }while(T != 0);
    
    Escrever_arq(carro);
    
}
