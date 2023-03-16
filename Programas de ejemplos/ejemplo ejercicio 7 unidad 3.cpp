#include <stdio.h>
int m=0;            //global

int calculo(int v, int w) {    //globales
	static int z=0;                     //locales
	if ((w==1)&& (v==0)) 
		z++; 
	return z; 
} 

int main() { 
int a,b,x =0, y=0; 

	printf("\n ingrese par de valores a y b  "); 
	scanf("%d %d", &a, &b);    
	while (a<b){ 
		int c; 
		c = a*b; 
		calculo (a,b); 
		x += a; 
		y += b; 
		printf("\n ingrese valor a y b  "); 
		scanf("%d %d", &a, &b); 
		printf("\n ......%d", c); 
		} 
	printf("\n ......%d", calculo(a,b)); 
	printf("\n ......%d .....%d", x,y); 
}

