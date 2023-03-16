/*
Ejercicio 1
Se procesa información de los productos de un comercio. De cada producto se registró código y precio.
Se pide que usando funciones para cada ítem resuelva:
Cargar en un arreglo dinámico el código y precio de cada producto.
Mostrar los datos de los productos y el código del producto más caro. (Suponer único)
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

 /* Algoritmo Ejercicio_1_Práctica_Operativa*/
struct prod{
	int cod;
	float precio;	
};

void carga(prod *a, int cant, int i){
	
	fflush(stdin);
	if (i < cant){
		printf("\n Código: ");
		scanf("%d",&a[i].cod);
		printf(" Edad: ");
    	scanf("%f",&a[i].precio);
    	carga(a,cant,i+1);
	} else return;
}

void mostrar(prod *a, int xc){
	
    printf("\n\n\n Datos de los %d productos: \n", xc);
    for(int i = 0; i<xc; i++) {
    	printf("\n Producto %d \n", i+1);
    	printf("   %d   $ %.2f   \n",a[i].cod,a[i].precio);  
	}
   return; 
}

int prodMasCostoso(prod *a, int cant){
	float max = 0;
	int codMax;
	
	for(int i = 0; i < cant; i++){
		if (a[i].precio > max){
			max = a[i].precio;
			codMax = a[i].cod;
		}	
	}
	return codMax;
}
 
int main(){
	setlocale (LC_CTYPE, "Spanish");
	int cant_prod;
	prod *arr;
 	
	printf("\n Ingrese la cantidad de productos: ");
	scanf("%d",&cant_prod);
	arr = (prod*) malloc (cant_prod*sizeof(prod));  
    carga(arr,cant_prod,0);
	mostrar(arr,cant_prod);
	printf("\n\n Código del producto más caro: %d \n",prodMasCostoso(arr,cant_prod));
	free(arr);   
	
	getch(); 
}

/*Lote de prueba
4
418
1500
137
3650
201
2000
555
1000
*/
