/*Parcial 2 - Tema 1  -  Turno Tarde*/
/*Ejercicio 1
Un comercio almacena información de productos nuevos para la venta y por cada uno se conoce: nombre, tipo(1: bazar, 2: muebles,
3: mantelería), precio de venta y stock.
Se pide que usando funciones para cada ítem, resuelva lo siguiente:
a)  Ingresar una cantidad de productos y generar un arreglo dinámico para almacernar los datos de cada uno.
b)  Decir cuántas productos tipo bazar tienen un precio mayor a 1000 y cuantos un stock 0 (hacer una función que devuelva 
ambos resultados).
c)  Indicar el precio promedio de los muebles.
d)  Mostrar los nombres de los muebles y el precio de venta (hacer una función recursiva)*/

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

void cargar(prod *&arr, int cant){
	
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

void contar(prod *a, int xc, int &b1000, int &b0, int &contM, float &acum){
	
	for(int i = 0; i<xc; i++){
		if (a[i].tipo == 1){
			if (a[i].precioV > 1000){
				b1000++;
			}
			if (a[i].stock == 0){
				b0++;
			}
		}
		if(a[i].tipo == 2){
			contM++;
			acum = acum + a[i].precioV;
		}		
	}
}

void muebles(prod *a,int xc, int i){  	
	
	if (i < xc){
		if (a[i].tipo == 2){
			printf(" Nombre: %s   -  Precio: $ %.2f \n",a[i].nomb, a[i].precioV);
		}
		muebles(a,xc,i+1);
	} else return;
}
	
	
/*Algoritmo principal*/
int main() {
	setlocale (LC_CTYPE, "Spanish");
	prod *arr;
	int cantPostu, cantM, b1000 = 0,s0 = 0;
	float acum = 0;
	
	printf("\n Ingrese la cantidad de productos: ");
	scanf("%d", &cantPostu);
	arr = (prod*) malloc (cantPostu * sizeof (prod));
	printf("\n\n A continuación se cargan los datos de los productos: \n");
	cargar(arr,cantPostu);
	printf("------------------------------------------------------\n");
	mostrar(arr,cantPostu);
	contar(arr,cantPostu,b1000,s0,cantM,acum);
	printf("------------------------------------------------------\n");
	printf("\n\n Productos de bazar con precio mayor a $1000:  %d \n",b1000);
	printf("\n\n Productos de bazar con stock nulo: %d \n",s0);
	printf("\n\n El precio promedio de los muebles es:  $ %.2f \n",acum/cantM);
	printf("\n\n Datos de los muebles: \n");
	muebles(arr,cantPostu,0);
	
	printf("\n\n FIN DEL PROGRAMA  \n\n ");
	getch();
}

/*
Lote de prueba
nombre tipo precio stock
6
sofa
2
60000.50
30
termo
1
7000
0
comoda
2
30000.25
50
lampara
1
10000
25
sillas
2
15000.15
60
mantel
3
4000
15
*/
