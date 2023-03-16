/*Ejercicio 2
Un gremio registra datos de sus nuevos afiliados. De cada uno registra Nombre y Sueldo.
Se pide que usando funciones para cada ítem resuelva:
Generar una lista enlazada con punteros para almacenar esta información.
Indicar en el programa principal cuál es el sueldo promedio.
Mostrar en forma recursiva la información de la lista.*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

typedef struct{
	char nomb[30];
	float sueldo;
} afiliado;

struct nodo{
	afiliado dato;
	struct nodo *sig;
};
typedef struct nodo *puntero;

void crear(puntero &xp){
	xp = NULL;
}

void insertar (puntero &xp){ 
	puntero nuevo;
	char nombre[30];
	
	fflush(stdin);
    printf("Ingrese el nombre del afiliado (termina la carga con FIN):  ");
    gets(nombre);			                         						 
	if ((stricmp(nombre,"FIN") != 0)){ 
		nuevo = (puntero)malloc(sizeof(struct nodo));
		strcpy(nuevo->dato.nomb,nombre);
		printf("Ingrese el sueldo: ");
		scanf ("%f", &nuevo->dato.sueldo);
		nuevo->sig = xp;
		xp = nuevo;
		insertar (xp);
	}
}


float prom(puntero &xp){
	float acum = 0,prom;
	int c = 0;
	
	while(xp!=NULL){
		acum = acum + xp->dato.sueldo; 
		c++;
		xp = xp->sig;
	} 
	prom = acum / c;	
	return prom;
}

void muestra(puntero xp){   
	puntero p;	
	
	if (xp != NULL){
		printf(" Nombre: %s   -   Sueldo: $ %2.f \n\n",xp->dato.nomb,xp->dato.sueldo);
		xp=xp->sig;
		muestra(xp);
	} else{
		return;
	}
}


int main(){
	setlocale (LC_CTYPE, "Spanish");
	puntero cabeza;	
	
	crear(cabeza);
	insertar(cabeza);

	printf("\n   ** LISTA ** \n\n");
	muestra(cabeza);
		printf("\n Sueldo promedio: $ %.2f \n",prom(cabeza));
	getch();
}

/*
Lote de prueba
JUAN
63000
LUCIA
84000
ANA
42000
JOSE
50000
LUIS
122000
FIN
*/
