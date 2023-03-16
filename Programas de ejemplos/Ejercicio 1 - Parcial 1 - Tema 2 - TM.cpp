#include <stdio.h>
#include <conio.h>
#include <locale.h>
#define A 3 //80 en el enunciado

struct alumno{
	char nombre[15];
	int edad, materias;
}estud[A];

void Cargar(alumno xest[A]){
	
	for(int i=0; i<A; i++){
		printf("\n Nombre del estuadiante: ");
		fflush(stdin);
		gets(xest[i].nombre);
		printf("\n Edad: ");
		scanf("%d", &xest[i].edad);
		printf("\n Materias rendidas: ");
		scanf("%d", &xest[i].materias);
	}
	return;
}

void Listar(alumno xest[A], int xedad, int i){
	
	if (i < A) {
		if(xest[i].edad < xedad){
			printf("\n El alumno %s tiene la edad de %d años.", xest[i].nombre, xest[i].edad);
			Listar(xest, xedad, i+1);
		}
		else
			Listar(xest, xedad, i+1);
	}
	else return;
}

int Mostrar(alumno xest[A], int &menor){
	int igual = 0;
	
	for(int i=0; i<A; i++){
		if(xest[i].materias == 10)
			igual++;
		else if(xest[i].materias < 10)
			menor++;
	}
	return igual;
}

int main(){
	setlocale(LC_CTYPE, "Spanish");
	int edad = 0;
	
	Cargar(estud);
	printf("\n Ingrese una edad: ");
	scanf("%d", &edad);
	Listar(estud, edad, 0);
	printf("\n Hay %d alumnos con 10 materias rendidas y", Mostrar(estud, edad));
	printf(" Hay %d estuadiantes con menos de 10 materias rendidas.", edad);
	
	getch();
}
