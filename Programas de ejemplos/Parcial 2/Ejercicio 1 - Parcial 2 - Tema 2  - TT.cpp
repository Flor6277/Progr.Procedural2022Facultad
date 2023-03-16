/*Parcial 2 - Tema 2  -  Turno Tarde*/
/*Ejercicio 1
Un comercio almacena información de productos nuevos para la venta y por cada uno se conoce: nombre, tipo(1: bazar, 2: muebles,
3: mantelería), precio de venta y stock.
Se pide que usando funciones para cada ítem, resuelva lo siguiente:
a)  Ingresar una cantidad de productos y generar un arreglo dinámico para almacernar los datos de cada uno.
b)  Decir la cantidad de productos de mantelería con stock 0 y la cantidad cuyo precio es menor a 1000
(hacer una función que devuelva ambos resultados).
c)  Indicar el precio promedio de los productos con stock mayor a 10.
d)  Mostrar los nombres y stock de los productos cuyo precio de venta sea mayor a uno ingresado por teclado
(hacer una función recursiva).*/

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

void cargar(prod *arr, int cant){
	
    for(int i = 0; i < cant; i++){
		printf("\n Producto %d: \n", i+1);
		fflush(stdin);
		printf(" Nombre: ");
		gets(arr[i].nomb);
		printf(" Tipo (1: Bazar  -  2: Muebles  -  3: Mantelería): ");
	    scanf ("%d",&arr[i].tipo);
		printf(" Precio de venta: ");
	    scanf ("%f",&arr[i].precioV);
		printf(" Stock: ");
	    scanf ("%d",&arr[i].stock);
	} 
	return;
}

void mostrar(prod *a, int xc){
	
    printf("\n Datos de los %d productos: \n", xc);
    printf(" ORD. NOMBRE  TIPO     PRECIO   STOCK \n");
    for(int i = 0; i<xc; i++) {
    	printf("  %d:   %s     %d   $ %.2f    %d \n",i+1,a[i].nomb,a[i].tipo,a[i].precioV,a[i].stock);  
	}
   return; 
}

/*Indicar el precio promedio de los productos con stock mayor a 10.*/
int contar(prod *a, int xc, int &cont1, int &cont2){
	int cont = 0;
	
	for(int i = 0; i<xc; i++){
		if (a[i].tipo == 3){
			if (a[i].stock == 0){
				cont1++;
			}
			if (a[i].precioV < 1000){
				cont2++;
			}
		}
		if(a[i].stock > 10){
			cont++;
		}		
	}
	return cont;	
}


float acumMuebles(prod *a,int xc) {
	int acum = 0;
	
	for(int i = 0; i<xc; i++){
		if (a[i].tipo == 2){
			acum = acum + a[i].precioV;
		}
	}
	return acum;
}

void muebles(prod *a,int xc, int i,float pR){  	
	
	if (i < xc){
		if (a[i].precioV > pR){
			printf(" Nombre: %s   -  Stock: %d \n",a[i].nomb, a[i].stock);
		}
		muebles(a,xc,i+1,pR);
	} else return;
}
	
	
/*Algoritmo principal*/
int main() {
	setlocale (LC_CTYPE, "Spanish");
	prod *arr;
	int cant,cantM,c1 = 0,c2 = 0;
	float precioRef;
	
	printf("\n Ingrese la cantidad de productos: ");
	scanf("%d", &cant);
	arr = (prod*) malloc (cant * sizeof (prod));
	printf("\n\n A continuación se cargan los datos de los productos: \n");
	cargar(arr,cant);
	printf("------------------------------------------------------\n");
	mostrar(arr,cant);
	cantM = contar(arr,cant,c1,c2);
	printf("------------------------------------------------------\n");
	printf("\n\n Productos de mantelería con stock nulo:  %d \n",c1);
	printf("\n\n Productos de mantelería con precio de venta menor a $1000: %d \n",c2);
	printf("\n\n El precio promedio de los productos con stock > 10 es:  $ %.2f \n",acumMuebles(arr,cant)/cantM);
	printf("\n\n Ingrese un precio de venta para mostrar que productos lo superan: ");
	scanf("%f", &precioRef);
	printf("\n\n Datos de los productos con precio mayor a $ %.2f: \n", precioRef);
	muebles(arr,cant,0,precioRef);
	free(arr);
	printf("\n\n FIN DEL PROGRAMA   ");
	getch();
}

/*
Lote de prueba
nombre tipo precio stock
8
sofa
2
60000
30
termo
1
7000
0
comoda
2
30000
50
lampara
1
10000
25
sillas
2
15000
60
mantel
3
4000
15
lona
3
500
60
cristal
3
600
0
25000
*/
