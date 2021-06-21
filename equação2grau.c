#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//ax^2+bx+c
// delta = b^2 - 4*a*c
//x1 e x2 = -b +- sqrt(delta) / 2*a

double calc_delt(double a, double b, double c);
void func2grau(double *x1, double *x2, double a, double b, double c);

main(){
	double a, b, c, x1, x2;
	
	printf("Digite o valor de a :\n");
	scanf("%lf", &a);
	printf("Digite o valor de b :\n");
	scanf("%lf", &b);
	printf("Digite o valor de c :\n");
	scanf("%lf", &c);
	
	func2grau(&x1, &x2, a, b, c);
	
	
	printf("X1 = %lf\n", x1);
	printf("X2 = %lf\n", x2);
}
void func2grau(double *x1, double *x2, double a, double b, double c){
    
    double delta;
    
	if(a != 0){
		delta = calc_delt(a, b, c);
		if(delta == 0){
			*x1 = (-b + sqrt(delta))/(2*a);
			x2 = x1;
			printf("Delta = 0\n");
			
		}else{
			if(delta>0){
				*x1 = (-b + sqrt(delta))/(2*a);
			    *x2 = (-b - sqrt(delta))/(2*a);
			
			    printf("Delta > 0\n");
			    //printf("X1 = %.2f\n", x1);
			    //printf("X2 = %.2f\n", x2);
			}else{
				printf("Delta < 0\n");
			}
		}
	}else{
		printf("a = 0\n");
	}
	
}
double calc_delt(double a, double b, double c){
	return (b*b) - 4*a*c;
}
