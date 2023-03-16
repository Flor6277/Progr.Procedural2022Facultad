/*
Molina Florencia
37.647.311
21.004
LSI
*/

/*Ejercicio 2
Un comercio almacena informaci�n de productos nuevos para la venta, por cada uno se conoce: c�digo y precio de venta.
Se pide que usando funciones para cada �tem resuelva:
Generar una lista enlazada con punteros para almacenar esta informaci�n.
Mostrar en forma recursiva la informaci�n de la lista.
Indicar en el programa principal cu�l es el c�digo del producto m�s caro (suponer �nico).*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <locale.h>

typedef struct{
	int cod;
	float precio;
} producto;

struct nodo{
	producto dato;
	struct nodo *sig;
};
typedef struct nodo *puntero;

void crear(puntero &xp){
	xp = NULL;
}

void insertar (puntero &xp){ 
	puntero nuevo;
	int codigo;
	
	printf("Ingrese codigo del producto (finaliza la carga con 0): ");
	scanf ("%d", &codigo);
	if (codigo != 0){ 
		nuevo = (puntero) malloc(sizeof(struct nodo));
		nuevo->dato.cod = codigo;
		printf("Ingrese el precio: ");
		scanf ("%f", &nuevo->dato.precio);
		nuevo->sig = xp;
		xp = nuevo;
		insertar (xp);
	}
}

void muestra(puntero xp){   
	puntero p;	
	
	if (xp != NULL){
		printf(" Codigo: %d   -   Precio: $ %2.f \n\n",xp->dato.cod,xp->dato.precio);
		muestra(xp->sig);
	} 
}

int busMax(puntero &xp){
	float max;
	int cod;
	max=0;
	
	while(xp!=NULL){
		if(xp->dato.precio > max){	
			max = xp->dato.precio;
			cod = xp->dato.cod;
			puntero(xp);
		}
		xp = xp->sig;
	} 	
	return cod;
}

int main(){
	setlocale (LC_CTYPE, "Spanish");
	puntero cabeza;	
	
	crear(cabeza);
	insertar(cabeza);
	printf("\n   **** LISTA CREADA **** \n\n");
	muestra(cabeza);
	printf("\n C�digo del producto m�s costoso: %d \n",busMax(cabeza));
	
	getch();
}

/*
Lote de prueba
15
700
02
1200
68
400
49
1000
52
500
0
*/



