#include <pthread.h> 
#include <time.h> 
#include <stdlib.h>
#include <stdio.h>
  
#define MAX 1000 
   
#define THREAD_MAX 4 

int a[MAX];
 
int part = 0; 
   
void merge(int low, int mid, int high){ 

    int *left = (int*)malloc((mid - low + 1)*sizeof(int*));
    int *right = (int*)malloc((high - mid)*sizeof(int*)); 
  
    // n1 tamanho esquerda, n2 tamanho direita
    int n1 = mid - low + 1, n2 = high - mid, i, j; 
  
    // guardando valores na esquerda
    for (i = 0; i < n1; i++) 
        left[i] = a[i + low]; 
  
    // guardando valores na direita
    for (i = 0; i < n2; i++) 
        right[i] = a[i + mid + 1]; 
  
    int k = low; 
    i = j = 0; 
  
    // merge esq e dir em orde crescente
    while (i < n1 && j < n2){ 
        if (left[i] <= right[j]) 
            a[k++] = left[i++]; 
        else
            a[k++] = right[j++]; 
    } 
  
    // insere os valores restantes pela esquerda 
    while (i < n1){ 
        a[k++] = left[i++]; 
    } 
  
    // insere os valores restantes pela direita
    while (j < n2){ 
        a[k++] = right[j++]; 
    } 
} 
  
void merge_sort(int low, int high){ 
     
    int mid = low + (high - low) / 2;
	 
    if (low < high) { 
  
        // 1ª metade
        merge_sort(low, mid); 
  
        // 2ª metade 
        merge_sort(mid + 1, high); 
  
        // dando merge nas duas metades 
        merge(low, mid, high); 
    } 
} 
  
// função para o multithreading
void* merge_sortl(void* arg){ 

    // qual parte das quatro
    int thread_part = part++; 
   
    int low = thread_part * (MAX / 4); 
    int high = (thread_part + 1) * (MAX / 4) - 1; 
    int mid = low + (high - low) / 2; 
    
    if (low < high) { 
        merge_sort(low, mid); 
        merge_sort(mid + 1, high); 
        merge(low, mid, high); 
    } 
} 
  
int main(){
    
    int i, n;
    
    printf("digite a quantidade de elementos\n");
    scanf("%d", &n);
     
    for(i=0;i<n;n++){
    	scanf("%d", &a[i]);
	}
   
    clock_t t1, t2; 
  
    t1 = clock(); 
    
    pthread_t threads[THREAD_MAX]; 
  
    // creando o numero definido de threads 
    for (i = 0; i < THREAD_MAX; i++) 
        pthread_create(&threads[i], NULL, merge_sortl, (void*)NULL); 
  
    // dando join nas threads
    for (i = 0; i < 4; i++) 
        pthread_join(threads[i], NULL); 
  
    // dando merge nas ultimas 4 partes 
    merge(0, (MAX / 2 - 1) / 2, MAX / 2 - 1 ); 
    merge(MAX / 2, MAX/2 + (MAX-1-MAX/2)/2, MAX - 1); 
    merge(0, (MAX - 1)/2, MAX - 1); 
  
    t2 = clock(); 
 
    for (i = 0; i < MAX; i++) 
        printf("%d ", a[i]); 
  
	printf("tempo levado %lf", (t2-t1)/(double)CLOCKS_PER_SEC);  
  
    return 0; 
}
