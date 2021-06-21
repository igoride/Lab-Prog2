#include <stdlib.h>
#include <stdio.h>

int soma_vet(int v[], int n){
	
	if(n == 1){
		return v[0];
	}
	return v[n]+soma_vet(v, n-1);
	
}

int main(){
	int v[3], n =3, c;
	
	v[0]=1;
	v[1]= 2;
	v[2]=3;
	c = soma_vet(v, n);
	printf("%d", c);
}
