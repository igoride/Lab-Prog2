#include <stdio.h>
#include <stdlib.h>

void hanoi(int N, int K, int a, int b, int c){
	
	if(N==1){ 
		
		printf("%d %d %d\n", a, b, c);
		return;
	}
	
	hanoi(N-1,K, a, b, c);
	a--;
	b++;
		printf("%d %d %d\n", a, b, c);

	hanoi(N-1, K, b, c, a);
	b--;
	c++;
}

int main(){
	int N;
	int K;
	int i, count = 0;
	int a = N, b = 0, c = 0;
	
	scanf("%i", &N);
	scanf("%d", &K);
	
	hanoi(N, K, a, b, c);
	
	//printf("%d %d %d", a, b, c);
	
}
