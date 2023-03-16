/*Parcial 2 - Tema 1  -  Turno Mañana */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

typedef struct {
	float precioV;
	int stock, tipo, cod;
}prod;

struct nodo{
	prod dato;
	struct nodo *sig;
};
typedef struct nodo *puntero;

//ITEM A  Genere una lista enlazada con punteros para almacenar esta información.
void insertar(puntero &xp){
	puntero nuevo;
	int codigo;
	
	printf("\n Código (finaliza con 0): "); scanf("%d", &codigo);
	while (codigo != 0){
		nuevo = (puntero) malloc (sizeof(struct nodo));
		nuevo->dato.cod = codigo;
		printf(" Tipo (1: bazar, 2: muebleria, 3: manteleria): "); scanf("%d",&nuevo->dato.tipo);	
		printf(" Precio: "); scanf("%f",&nuevo->dato.precioV);	
		printf(" Stock: "); scanf("%d",&nuevo->dato.stock);	
		printf("\n\n Código (finaliza con 0): "); scanf("%d", &codigo);
		nuevo->sig = xp;
		xp = nuevo;
	}
}

//ITEM B  Mostrar en forma recursiva los códigos de producto tipo 3.
void muestra(puntero xp){
	if(xp != NULL){
		if(xp->dato.tipo == 3){
			printf("      %d \n", xp->dato.cod);
		}
		muestra(xp->sig);
	} else return;
}

//ITEM C  Indicar en el programa principal cuál es el mayor precio registrado.
float maxPrecio(puntero xp, float &max){
	
	while(xp != NULL){
		if (xp->dato.precioV > max){
			max = xp->dato.precioV;
			puntero (xp);
		}
		xp = xp->sig;
	}
}

//ITEM D  Mostrar el código y stock de los productos con el mayor precio.
void muestra2(puntero xp, float &max){
	
	while (xp != NULL){
		if(xp->dato.precioV == max){
			printf("   %d        %d \n", xp->dato.cod, xp->dato.stock);
		}
		xp = xp->sig;
	}
}

//Algoritmo principal
int main () {
	puntero cabeza;
	setlocale(LC_CTYPE, "Spanish");
	cabeza = NULL;
	float max = 0;
	
	printf(" A continuación se cargan los datos de los productos: \n");
	insertar(cabeza);
	printf("\n Listado de productos de tipo 3 (mantelería) \n");
	muestra(cabeza);
	maxPrecio(cabeza,max);
	printf("\n Máximo precio registrado: $ %.2f \n", max);
	printf("\n Listado de productos con precio igual a $ %.2f \n", max);
	printf(" Código  -  Stock \n");
	muestra2(cabeza, max);
	
	printf("\n FIN DEL PROGRAMA \n");
	getch();
}

/*
Lote de prueba
codigo tipo precio stock
8
3
15000
30
95
1
7000
0
56
2
15000
50
81
1
10000
25
650
2
15000
60
77
3
4000
15
11
3
500
60
47
3
600
16
0
*/
