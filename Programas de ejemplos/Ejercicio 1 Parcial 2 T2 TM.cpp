/*Parcial 2 - Tema 2  -  Turno Mañana*/
/*Ejercicio 1
Una agencia de empleo registra datos de postulantes a un puesto de trabajo. De cada uno se registra nombre, DNI, sexo,
edad y código de localidad donde vive (1..19).
Se pide que usando funciones para cada ítem, resuelva lo siguiente:
a)  Ingresar una cantidad de postulantes y generar un arreglo dinámico para almacernar los datos de cada uno.
b)  Decir cuántas postulantes mujeres tienen menos de 30 años y cuantas son mayores de 50 (hacer una función que devuelva 
ambos resultados).
c)  Indicar la edad promedio de las mujeres.
d)  Mostrar los nombres de los postulantes y el DNI de quienes viven en la localidad 10 (hacer una función recursiva)*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

typedef struct {
	char nomb[20], sexo;
	int DNI, edad, cod;
}post;

//ITEM A Ingresar una cantidad de postulantes y generar un arreglo dinámico para almacernar los datos de cada uno.
void carga(post *a, int xc){
	
	for(int i = 0; i<xc; i++){
		fflush(stdin);
		printf("\n\n Nombre: "); gets(a[i].nomb);
		fflush(stdin);
		printf(" Sexo (F: femenino   -  M: masculino): "); scanf("%c", &a[i].sexo);
		printf(" DNI: "); scanf("%d", &a[i].DNI);
		printf(" Edad: "); scanf("%d", &a[i].edad);
		printf(" Código de localidad: "); scanf("%d", &a[i].cod);
	}
	
}

//ITEM B Decir cuántas postulantes mujeres tienen menos de 30 años y cuantas son mayores de 50 (hacer una función que devuelva ambos resultados).
//ITEM C Indicar la edad promedio de las mujeres.
int contar(post *a, int xc, int &cantM, int &m50, int &acum){
	int contM30 = 0;
	
	for(int i = 0; i<xc; i++){
		if ((a[i].sexo == 'F') || (a[i].sexo == 'f')){
			cantM ++ ;
			acum += a[i].edad;
			if (a[i].edad < 30){
				contM30++;
			} 
			if (a[i].edad > 50){
				m50++;
			}					
		}	
	}
	return contM30;
}

//item D Mostrar los nombres de los postulantes y el DNI de quienes viven en la localidad 10 (hacer una función recursiva)
void muestra(post *a, int xc, int i){
	
	if(i<xc){
		if (a[i].cod == 10){
			printf(" %s    %d   \n", a[i].nomb, a[i].DNI);
		}
		muestra(a,xc,i+1);
	} else return;
}

//Algoritmo principal
int main () {
	setlocale (LC_CTYPE, "Spanish");
	int cantPost, cantMuj = 0, m30 = 0, m50 = 0, acumEd = 0;
	post *arr;
	
	printf("\nIngrese la cantidad de postulantes: \n");
	scanf("%d", &cantPost);
	arr = (post*) malloc (cantPost * sizeof(post));
	carga(arr,cantPost);
	printf("\n\n Cantidad de mujeres menores a 30 años: %d \n", contar(arr,cantPost,cantMuj,m50,acumEd));
	printf("\n\n Cantidad de mujeres mayores a 50 años: %d \n", m50);
	printf("\n\n Promedio de edad de las mujeres postulantes: %d años\n", acumEd/cantMuj);
	printf("\n\n Lista de personas que viven en la localidad 10 \n");
	muestra(arr,cantPost,0);
	printf("\n\n Fin del programa \n");
	getch();
}

/*
Lote de prueba
6
flor
F
37647311
29
10
noel
F
38463511
27
16
myri
f
17173035
57
10
luis
M
39452648
25
3
jose
M
12697420
63
16
popi
F
16516515
25
10
*/
