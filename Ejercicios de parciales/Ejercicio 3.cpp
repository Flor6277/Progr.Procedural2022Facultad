/*Ejercicio 3
Una empresa comercializa 34 productos (1..34) de plástico en sus 8 sucursales. De cada sucursal registra para cada
uno de sus 34 productos la cantidad de unidades vendidas en el mes de Julio.
Realizar un programa en lenguaje C, que permita:
1. Almacene en una tabla el total la información de cada producto por sucursal (cada fila debe representar un
producto).
2. Indicar la cantidad total de ventas para el producto 25, decir si alguna sucursal no tuvo ventas del mismo y cuantas
sucursales vendieron más de 100. (hacer una función que devuelva los tres resultados).
3. Decir cuántos productos vendió cada sucursal.
Nota: hacer al menos una función recursiva.*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#define P 4 //productos (filas)
#define S 3 //sucursales (columnas)

void carga(int arr[P][S]){
	int prod, suc;
	
	printf("\n A continuación se cargan los datos de las ventas del mes de Julio: \n");
	for(int i = 0; i<P; i++){
		for(int j=0; j<S; j++){
			printf("\n Ingrese el producto: ");
			scanf("%d", &prod);
			printf(" Ingrese la sucursal a la que se le vendió: ");
			scanf("%d", &suc);
			printf(" Ingrese las unidades vendidas: ");
			scanf("%d", &arr[prod-1][suc-1]);
		}
	}
	return;
}

void muestra(int arr[P][S]){
	
	printf("\n A continuación se muestran los resultados cargados: \n");
	for(int i = 0; i<P; i++){
		printf("  Producto %d \n", i+1);
		for(int j=0; j<S; j++){
			printf("  %5d ",arr[i][j]);
		}
		printf("\n");
	}
	return;
}



int main(){
	setlocale(LC_CTYPE, "Spanish");
	int arr[P][S];
	
	carga(arr);
	muestra(arr);
	
	getch();
}

