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
	char nomb[25], sexo;
	int DNI,edad,cod;
}post;

void cargar(post *&arr, int cant){
	
    for(int i = 0; i < cant; i++){
		printf("\n Postulante %d: \n", i+1);
		fflush(stdin);
		printf(" Nombre: ");
		gets(arr[i].nomb);
		printf(" Sexo (F o M): ");
	    scanf ("%c",&arr[i].sexo);
	    fflush(stdin);
		printf(" DNI: ");
	    scanf ("%d",&arr[i].DNI);
		printf(" Edad: ");
	    scanf ("%d",&arr[i].edad);
		printf(" Código de departamento (1..19): ");
		scanf("%d", &arr[i].cod);
	} 
	return;
}

void mostrar(post *a, int xc){
	
    printf("\n Datos de los %d postulantes: \n", xc);
    printf(" ORD. NOMBRE  SEXO     DNI      EDAD  CÓDIGO DE DEPARTAMENTO \n");
    for(int i = 0; i<xc; i++) {
    	printf("  %d:   %s     %c     %d    %d             %d  \n",i+1,a[i].nomb,a[i].sexo,a[i].DNI,a[i].edad,a[i].cod);  
	}
   return; 
}

int contar(post *a, int xc, int &m30, int &m50){
	int contMujeres = 0;
	
	for(int i = 0; i<xc; i++){
		if ((a[i].sexo == 'F') || (a[i].sexo == 'f')){
			contMujeres ++;
			if (a[i].edad < 30){
				m30++;
			}
			if (a[i].edad > 50){
				m50++;
			}
		}		
	}
	return contMujeres;	
}

int acumEdadMujeres(post *a,int xc) {
	int acum = 0;
	
	for(int i = 0; i<xc; i++){
		if ((a[i].sexo == 'F') || (a[i].sexo == 'f')){
			acum = acum + a[i].edad;
		}		
	}
	return acum;
}

void localidad10(post *a,int xc, int i){  	
	
	if (i < xc){
		if (a[i].cod == 10){
			printf(" Nombre: %s   -  DNI: %d \n",a[i].nomb, a[i].DNI);
		}
		localidad10(a,xc,i+1);
	} else return;
}
	
	
/*Algoritmo principal*/
int main() {
	setlocale (LC_CTYPE, "Spanish");
	post *arr;
	int cant,cantM,m30 = 0, m50 = 0;
	
	printf("\n Ingrese la cantidad de postulantes: ");
	scanf("%d", &cant);
	arr = (post*)malloc (cant * sizeof (post));
	printf("\n\n A continuación se cargan los datos de los postulantes: \n");
	cargar(arr,cant);
	printf("------------------------------------------------------\n");
	mostrar(arr,cant);
	cantM = contar(arr,cant,m30,m50);
	printf("------------------------------------------------------\n");
	printf("\n\n Mujeres con menos de 30 años:  %d \n",m30);
	printf("\n\n Mujeres con más de 50 años: %d \n",m50);
	printf("\n\n El promedio de edad de las mujeres es:  %d años\n",acumEdadMujeres(arr,cant)/cantM);
	printf("\n\n Datos de lxs postulantes que viven en la localidad 10: \n");
	localidad10(arr,cant,0);
	free(arr);
	printf("\n\n   FIN DEL PROGRAMA   ");
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
55
10
*/
