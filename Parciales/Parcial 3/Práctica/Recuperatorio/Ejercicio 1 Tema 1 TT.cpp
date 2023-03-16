/*Recuperatorio Parcial 3 Turno Tarde Tema 1*/
/*Ejercicio 1 
Se realiza un relevamiento de industrias en 6 provincias, cada provincia se ha dividido en 5 zonas (1: Este, 2: Oeste, 3: Sur, 
4: Norte y 5: Centro. 
De cada industria se registra código de provincia (1..6) y de zona (1..5).
Realizar un programa en C que usando funcion optimas responda a los siguientes ítems:
1) Acumular en una estructura bidimensional la información de las industrias relevadas, de modo tal que las filas representen
provincias y las columnas zonas.
2) Indicar para cada provincia que zonas no tienen industria. */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#define Z 5
#define P 6

void cereo(int a[P][Z]){
	
	for(int i = 0; i<P; i++){
		for(int j=0; j<Z; j++){
			a[i][j] = 0;
		}
	}
}
/*1) Acumular en una estructura bidimensional la información de las industrias relevadas, de modo tal que las filas representen
provincias y las columnas zonas.*/
void carga(int a[P][Z]){
	int zo = 0, pr = 0;
	
	printf("Ingrese la provincia(1..6): "); scanf("%d", &pr);
	while (pr != 0) {
		printf("Ingrese la zona(1..5): "); scanf("%d", &zo);
		a[pr-1][zo-1] ++;
		printf("Ingrese la provincia (finaliza con 0): "); scanf("%d", &pr);
	}
	
}

void indicar(int a[P][Z]){
	for(int i = 0; i<P; i++){
		for(int j=0; j<Z; j++){
			if(a[i][j] == 0)
				printf(" Zona: %d tiene industria ",j+1);
		}
		printf("\n");
	}
}


int main() {
	int arr[P][Z];
	
	cereo(arr);
	carga(arr);
	printf("\n\n");
	indicar(arr);
	
	printf("\n FIN DEL PROGRAMA \n");
	getch();
}

