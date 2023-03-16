/*EJERCICIO 2
Un comercio almacena informacion de productos nuevos para la venta, por cada uno se conoce: nombre,tipo(1:bazar,2:muebles,3:manteleria), precio de venta y stock.
Se pide que usando funciones para cada item resuelva:
a) Generar una lista enlazada con punteros para almacenar esta informacion.
b) Mostrar en forma recursiva los nombres de los productos con stock 0.
c) Indicar en el programa principal cual es el menor precio registrado.
d)mostrar el nombre del codigo y stock de los productos con menor precio.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct producto{
	char nombre[50];
	char tipo[12];
	float  preciodeventa;
	int stock;	
};

struct nodo{
	producto datos;
	struct nodo *sig;		
};

typedef struct nodo *puntero;

void crear(puntero &xp)
{
	xp=NULL;
	return;
}

void insertar(puntero &xp)
{
	puntero nuevo;
	int cod;
	char nomb[50];
	printf("Ingrese el numero de tipo de producto\n");
	printf("1: Bazar\n");
	printf("2: Muebles\n");
	printf("3: Manteleria\n");
	scanf("%d",&cod);
	while(cod != 0 )
	{
		nuevo=(puntero)malloc(sizeof(struct nodo));	
		switch(cod)
		{
			case 1: strcpy(nuevo->datos.tipo,"Bazar");
					break;
			case 2: strcpy(nuevo->datos.tipo,"Muebles");
					break;
			case 3: strcpy(nuevo->datos.tipo,"Manteleria");
					break;
		}
		fflush(stdin);
		printf("Ingrese el nombre del producto: \n");
		gets(nomb);
		fflush(stdin);
		strcpy(nuevo->datos.nombre,nomb);
		printf("Ingrese el precio de venta del producto: \n");
		scanf("%f",&nuevo->datos.preciodeventa);
		printf("Ingrese el stock del producto:\n");
		scanf("%d",&nuevo->datos.stock);
		printf("Ingrese el numero de tipo de un nuevo producto(corta con 0):\n");
		scanf("%d",&cod);
		nuevo->sig = xp;
		xp = nuevo;
	}
}

void mostrarstock0(puntero xp)
{
	if(xp != NULL )
	{
		if(xp->datos.stock == 0)
		{
			printf("\nNombre de producto con stock 0: %s\n\n",xp->datos.nombre);
		}
		mostrarstock0(xp->sig);
	}
}

void recorrer (puntero xp,float &min)
{
	while(xp != NULL)
	{
		if(xp->datos.preciodeventa<min)
		{
			min=xp->datos.preciodeventa;
		}
		xp=xp->sig;
	}
	return;
}

void mostrarcod(puntero xp,float min)		//no muestra
{
	while(xp != NULL)
	{
		if(xp->datos.preciodeventa==min)
		{
			printf("Tipo de producto: %s\n\n",xp->datos.tipo);
			printf("Stock: %d\n\n",xp->datos.stock);
		}
		xp=xp->sig;
	}
}

int main()
{
	float min=9999999;
	puntero listaprod;
	crear(listaprod);
	insertar(listaprod);
	mostrarstock0(listaprod);
	recorrer(listaprod,min);
	printf("El menor precio registrado es de: %10.2f",min);
	mostrarcod(listaprod,min);
}
