/*Ejercicio Parcial 2021
Una empresa láctea procesa información de las variedades de yogures para beber que comerzializa. Para ello registra
cantidad de litros elaborados, cantidad de litros vendidos, tipo (entero / descremado) y variedad de yogurt 
(extra calcio, con fibra, con hierro, etc.). Generar un arreglo de registros para almacenar la información.
Realizar un programa en C, que usando funciones para cada item permita:
a)  Cargar los datos de los yogures.
b)  Listar los datos de los yogures tipo entero. (Hacer una función recursiva).
c)  Indicar cuántas variedades de yogures elaboran más de 250.000 listros y cuantas menos de 80.000 litros. Realice una función 
que retorne un valor con la función y otro por parámetro. Ambos valores se deben mostrar en el main.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define V 3

typedef struct{
	int litro;
	int ventas;
	int tipo;
	char variedad[30];
}yogur;

void carga (yogur xa[V]){

	for(int i=0;i<V;i++){
		printf(" Yogur %d \n", i+1);
		printf(" Ingrese litros elaborados: ");
		scanf("%d",&xa[i].litro);
		printf(" Ingrese cantidad de litros vendidos: ");
		scanf("%d",&xa[i].ventas);
		printf(" Ingrese tipo (1 para entero, 2 para descremado): ");
		scanf("%d",&xa[i].tipo);
		printf(" Ingrese variedad del yogur: \n");
		fflush(stdin);
		gets(xa[i].variedad);	
	}
}

void listar(yogur xa[V], int i){
	if(i<V){
		if(xa[i].tipo == 1){
			printf("\n Listado de yogur tipo entero (1) \n");
			printf("\n Litros elaborados: %d \n",xa[i].litro);
			printf("\n Cantidad de ventas: %d \n",xa[i].ventas);
			printf("\n Variedad del yogur: %s \n",xa[i].variedad);
		}
		listar(xa,i+1);
	}
	
}

int indicar(yogur xa[V], int &m250){
	int i, m80 = 0;
	for(i=0;i<V;i++){
		if(xa[i].litro > 250000){
			m250++;
		}
		if(xa[i].litro < 80000){
			m80++;
		}
	}
	return(m80);
}


int main(){
	yogur *arr;
	int m50=0, cantidad;
	
	printf("Ingrese la cantidad de yogures vendidos: ");
	scanf("%d", &cantidad);
	arr* = (yogur) malloc ()
	carga(a);
	listar(a,0);
	printf("\n La variedad de yogures mayor a 250.000 litros son: %d \n",indicar(a,m50));
	printf("\n La variedad de yogures menores a 80.000 litros son: %d \n",m50);
}

/*

*/
