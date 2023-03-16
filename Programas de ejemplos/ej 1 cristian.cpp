#include <stdio.h>
#include <malloc.h>
#define N 4

typedef struct
{
	int cod;
	float price;
}prod;

void carga(prod *&xp)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("Ingrese el codigo seguido del precio del producto \n");
		scanf("%d",&xp[i].cod);
		scanf("%f",&xp[i].price);
	}
}

void mostrar1(prod *xp)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("Codigo del producto: %d \n",xp[i].cod);
		printf("Precio: %f \n",xp[i].price);
	}
}

void mostrar2(prod *xp)
{
	int c ; 
	float max = 0;
	for(int i = 0;i<N; i++)
	{
		if(max < xp[i].price)
		{
			max = xp[i].price;
			c = xp[i].cod;
		}
	}
	printf("El codigo del producto mas caro es: %d \n",c);
}

int main(){
	prod *p;
	
	p = (prod*)malloc(N*sizeof(prod));
	carga(p);
	mostrar1(p);
	mostrar2(p);
	free(p);
}
