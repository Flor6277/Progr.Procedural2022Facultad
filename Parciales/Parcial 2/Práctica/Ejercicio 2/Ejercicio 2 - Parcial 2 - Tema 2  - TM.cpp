/*Parcial 2 - Tema 2  -  Turno Mañana*/
/*Ejercicio 2
Un comercio almacena información de productos nuevos para la venta y por cada uno se conoce: nombre, tipo (1: bazar, 2: muebles,
3: mantelería), precio de venta y stock.
Se pide que usando funciones para cada ítem, resuelva lo siguiente:
a)  Genere una lista enlazada con punteros para almacenar esta información.
b)  Mostrar en forma recursiva los nombre de producto con stock 0.
c)  Indicar en el programa principal cuál es el menor precio registrado.
d)  Mostrar el nombre y stock de los productos con el menor precio.*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

typedef struct {
	char nomb[15];
	float precioV;
	int stock, tipo;
}prod;

struct nodo{
	prod dato;
	struct nodo *sig;
};
typedef struct nodo *puntero;


void crear(puntero &xp){
	xp = NULL;
}

/*Item a  Genere una lista enlazada con punteros para almacenar esta información*/
void insertar (puntero &xp){ 
	puntero nuevo;
	char nombre[15];
	
	printf("\n Nombre (finaliza la carga con fin): ");
	fflush(stdin);
	gets(nombre);
	if (stricmp(nombre,"fin") != 0){ 
		nuevo = (puntero) malloc (sizeof(struct nodo));
		strcpy(nuevo->dato.nomb,nombre);
		printf(" Tipo (1: Bazar - 2: Mueble - 3: Mantelería): ");
		scanf ("%d", &nuevo->dato.tipo);
		printf(" Precio de venta: ");
		scanf ("%f", &nuevo->dato.precioV);
		printf(" Stock: ");
		scanf ("%d", &nuevo->dato.stock);
		nuevo->sig = xp;
		xp = nuevo;
		insertar (xp);
	} else return;
}

/*Item b  Mostrar en forma recursiva los nombre de producto con stock 0*/
void muestra(puntero xp){   
	
	if (xp != NULL){
		if(xp->dato.tipo == 3){
			printf(" Nombre: %s  \n\n",xp->dato.nomb);
		}
		muestra(xp->sig);
	} 
}

/*Item c  Indicar en el programa principal cuál es el menor precio registrado*/
float busMin(puntero xp){
	float min = 99999999;
	
	while (xp != NULL){
		if(xp->dato.precioV < min){	
			min = xp->dato.precioV;
			puntero(xp);
		}
		xp = xp->sig;
	} 	
	return min;
}

/*Item d  Mostrar el nombre y stock de los productos con el menor precio.*/
void muestra2(puntero xp, float min){   
	
	if (xp != NULL){
		if(xp->dato.precioV == min){
			printf(" Nombre: %s  -  Tipo: %d \n\n",xp->dato.nomb,xp->dato.tipo);
		}
		muestra2(xp->sig,min);
	} 
}

/*Algoritmo principal*/
int main() {
	setlocale (LC_CTYPE, "Spanish");
	puntero cabeza;	
	float menorPrecio;
	
	crear(cabeza);
	printf("\n\n A continuación se cargan los datos de los productos: \n");
	insertar(cabeza);
	printf("------------------------------------------------------\n");
	printf("\n   **** CÓDIGOS DE PRODUCTOS DE TIPO 3 (MANTELERÍA) **** \n\n");
	muestra(cabeza);
	menorPrecio = busMin(cabeza);
	printf("------------------------------------------------------\n");
	printf("\n Menor precio registrado:  $ %.2f \n\n",menorPrecio);
	printf("------------------------------------------------------\n");
	printf("\n\n Productos que tienen precio = a $ %.2f \n\n",menorPrecio);
	muestra2(cabeza,menorPrecio);
	printf("\n\n FIN DEL PROGRAMA \n\n");
	getch();
}

/*
comoda
2
60000
30
termo
1
7000
0
mesa
2
30000
50
copas
1
60
mantel
3
2
1500
60
lona
3
4000
15
cristal
3
60
60
manta
3
600
20
fin
*/
