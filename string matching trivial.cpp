#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int trivial(char *a, char *b)
{
	int i,j,k,m,n,ocorrencia=0;
	
	m=strlen(a);
	n=strlen(b);
	
	for(k=m-1;k<n;k++)
	{
		for(i=m-1,j=k;i>=0;i--,j--)
			if(a[i]!=b[j]) break;
		if(i<0) ocorrencia++;	
	}
	
	return ocorrencia;	
}

int main()
{
	char a[500],b[10];
	
	puts("Insira um texto.");
	scanf("%[^\n]",b);
	
	puts("Insira a palavra.");
	scanf("%s",&a);
	
	printf("%d",trivial(a,b));	
}

