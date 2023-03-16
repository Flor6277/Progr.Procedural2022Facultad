/*Ejercicio 2
Se procesa la información de 97 estudiantes de ingreso a la LCC, de cada uno se registra: Nombre, DNI, Año de ingreso
a la carrera y el promedio del secundario.
Realizar un programa en lenguaje C, que permita:
1. Almacenar en un arreglo de registro la información de los 97 estudiantes.
2. Indicar cuantos estudiantes ingresaron en el año 2019 y cuantos en el 2020 (hacer una función que devuelva un
valor con el retorno y otro por parámetro).
3. Mostrar el Nombre y DNI de los estudiantes que obtuvieron un promedio mayor o igual a 7.
Nota: hacer al menos una función recursiva.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#define N 5

/*Algoritmo Ejercicio_2*/

struct alumnos {
	char nombA[15];
	int DNI, Ingreso;
	float promSec;
}alu[N];

void carga(alumnos alu[N], int inf, int sup){
	
    if (inf < sup){
    	printf("\n Ingrese el nombre del estudiante: ");
    	fflush(stdin);
    	gets(alu[inf].nombA);
        printf(" Ingrese su DNI: ");
        scanf("%d",&alu[inf].DNI);
        printf(" Ingrese el año de ingreso a la carrera: ");
        scanf("%d",&alu[inf].Ingreso);
        printf(" Ingrese el promedio del secundario ");
        scanf("%f",&alu[inf].promSec);
        return(carga(alu,inf+1,sup));
    } else return;        
}

int contar(alumnos alu[N], int &xc){
	int c = 0;
	for(int i = 0; i<N; i++){
		if (alu[i].Ingreso == 2019)
			c++;
		else if (alu[i].Ingreso == 2020)			
				xc++;
	}
	return c;
}

void Mayor_A_7(alumnos alu[N]){
	
	printf("\n Lista de alumnos que tienen promedio mayor o igual a 7: \n ");
	printf("    Nombre       DNI     \n");
	for(int i = 0; i<N; i++){
		if(alu[i].promSec >= 7){
			printf("  %s       %d    \n", alu[i].nombA, alu[i].DNI);
		}
	}
	return ;
}

/*Programa principal*/
int main (){
	setlocale (LC_CTYPE,"Spanish");
	int inf = 0, sup = N, cuenta ;
	
	carga(alu,inf,sup);
	printf("\n Alumnos que ingresaron en el 2019:  %d \n",contar(alu,0));
	printf("\n Alumnos que ingresaron en el 2020:  %d \n", cuenta);
	Mayor_A_7(alu);
	
	getch();
}
