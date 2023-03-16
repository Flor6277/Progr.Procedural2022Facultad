/*Parcial 2 - Tema 2  -  Turno Mañana*/
/*Ejercicio 2
Un comercio almacena información de productos nuevos para la venta y por cada uno se conoce: código, tipo (1: bazar, 2: muebles,
3: mantelería), precio de venta y stock.
Se pide que usando funciones para cada ítem, resuelva lo siguiente:
a)  Genere una lista enlazada con punteros para almacenar esta información.
b)  Mostrar en forma recursiva los códigos de producto tipo 3.
c)  Indicar en el programa principal cuál es el mayor precio registrado.
d)  Mostrar el código y stock de los productos con el mayor precio.*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

typedef struct {
	float precioV;
	int stock, tipo,cod;
}prod;

struct nodo{
	prod dato;
	struct nodo *sig;
};
typedef struct nodo *puntero;


void crear(puntero &xp){
	xp = NULL;
}

/*Item a*/
void insertar (puntero &xp){ 
	puntero nuevo;
	int codigo;
	
	printf("\n Código (finaliza la carga con 0): ");
	scanf ("%d", &codigo);
	if (codigo != 0){ 
		nuevo = (puntero) malloc(sizeof(struct nodo));
		nuevo->dato.cod = codigo;
		printf(" Tipo (1: Bazar - 2: Mueble - 3: Mantelería): ");
		scanf ("%d", &nuevo->dato.tipo);
		printf(" Precio de venta: ");
		scanf ("%f", &nuevo->dato.precioV);
		printf(" Stock: ");
		scanf ("%d", &nuevo->dato.stock);
		nuevo->sig = xp;
		xp = nuevo;
		insertar (xp);
	}
}

/*Item b*/
void muestra(puntero xp){   
	puntero p;	
	
	if (xp != NULL){
		if(xp->dato.tipo == 3){
			printf(" Código: %d  \n\n",xp->dato.cod);
		}
		muestra(xp->sig);
	} 
}

/*Item c*/
float busMax(puntero xp){
	float max = 0;
	
	while(xp != NULL){
		if(xp->dato.precioV > max){	
			max = xp->dato.precioV;
			puntero(xp);
		}
		xp = xp->sig;
	} 	
	return max;
}

/*Item d*/
void muestra2(puntero xp,float max){   
	
	if (xp != NULL){
		if(xp->dato.precioV == max){
			printf(" Código: %d  - Stock: %d \n\n",xp->dato.cod,xp->dato.stock);
		}
		muestra2(xp->sig,max);
	} 
}


/*Algoritmo principal*/
int main() {
	setlocale (LC_CTYPE, "Spanish");
	puntero cabeza;	
	float mayorPrecio;
	
	crear(cabeza);
	printf("\n\n A continuación se cargan los datos de los productos: \n");
	insertar(cabeza);
	printf("------------------------------------------------------\n");
	printf("\n   **** CÓDIGOS DE PRODUCTOS DE TIPO 3 (MANTELERÍA) **** \n\n");
	muestra(cabeza);
	mayorPrecio = busMax(cabeza);
	printf("------------------------------------------------------\n");
	printf("\n Mayor precio registrado:  $ %.2f \n\n",mayorPrecio);
	printf("------------------------------------------------------\n");
	printf("\n\n Productos que tienen precio = a $ %.2f \n\n",mayorPrecio);
	muestra2(cabeza,mayorPrecio);
	printf("\n\n FIN DEL PROGRAMA \n\n");
	getch();
}

/*
8
2
60000
30
19
1
7000
0
20
2
30000
50
5
1
60000
25
3
2
15000
60
88
3
4000
15
105
3
500
60
19
3
600
20
0
*/
