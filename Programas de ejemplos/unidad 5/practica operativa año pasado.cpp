/*Ejercicio 1
Una Clínica procesa la información de los servicios que brinda.
Por cada paciente que se atiende, se registra su nombre, DNI, código de Obra social (1..6) y para un estudio estadístico
también se registra su edad y sexo. Además, se conoce el nombre de las 6 obras sociales con las que la clínica trabaja.
Utilizando estructuras adecuadas y funciones óptimas
a) Cargar en una lista la información de los pacientes.
b) Realizar una función recursiva que devuelva al principal el total de pacientes atendidos y cantidad de mujeres
mayores de 50 años. Hacer una sola función donde un resultado debe ser calculado con la función y el otro con un
parámetro.
c) Ingresar un DNI por teclado y si se encuentra cambiar su código de Obra Social leyendo uno nuevo por teclado.
d) Generar a partir de la lista un arreglo que contenga el nombre de cada Obra Social y la cantidad de pacientes
atendidos por la misma. Mostrar la información almacenada en el arreglo.*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#define N 6

typedef char cadena[30];
typedef struct {
	cadena nombre;
	cadena dni;
	int os,edad;
	char sexo;
} paciente;

struct nodo {
	paciente dato;
	struct nodo *sig;
	};
typedef struct nodo *puntero;

typedef struct {
	cadena nombre;
	int cant;
} obraSocial;

void inicia (obraSocial ob[N]){
	
	for (int i=0;i<N;i++){
		ob[i].cant=0;
		printf (" Ingrese el nombre de la Obra Social N° %d:  ",i+1);
		fflush(stdin);
		gets(ob[i].nombre);
	}
	return;
}

void crear (puntero &xp){
	xp = NULL;
}

void insertar (puntero &xp, obraSocial ob[N]){
	puntero nuevo;
	int num;
	
	printf ("\n Ingrese el código de la obra social (0 para finalizar):  ");
	scanf ("%d",&num);
	while (num != 0){
		nuevo = (puntero)malloc(sizeof(struct nodo));
		nuevo->dato.os = num;
		ob[num-1].cant++;
		printf(" Ingrese los siguientes datos: \n");
		printf(" Nombre del paciente:  ");
		fflush(stdin);
		gets(nuevo->dato.nombre);
		printf(" DNI:  ");
		gets(nuevo->dato.dni);
		printf(" Edad:  ");
		scanf("%d",&nuevo->dato.edad);
		printf(" Sexo:  ");
		fflush(stdin);
		scanf("%c",&nuevo->dato.sexo);
		nuevo->sig=xp;
		xp=nuevo;
		printf("\n Ingrese el código de la obra social (0 para finalizar):  ");
		scanf("%d",&num);
	}
	return;
}

int total (puntero &xp,int &aux, int cont){
	
	if (xp!=NULL){
		if ((xp->dato.sexo == 'F') && (xp->dato.edad>=50)){
			aux++;
		} 
		total (xp->sig,aux,cont+1);
	}	else return cont;
}

void cambio (puntero &xp, cadena num, obraSocial ob[N]){
	int nuevo;
	
	while ((xp!=NULL) && ((stricmp(xp->dato.dni, num))!=0)){
		xp=xp->sig;
	}
	if (xp==NULL){
		printf ("\n El DNI ingresado no se encuentra registrado ");
	} else {
	 printf (" Ingrese el número de la nueva obra social para el DNI: %d  ",num);
		scanf ("%d",&nuevo);
		ob[xp->dato.os - 1].cant = ob[xp->dato.os - 1].cant - 1;
		ob[nuevo - 1].cant = ob[nuevo - 1]. cant +1;	
		xp->dato.os = nuevo;
	}
	return;
}
void mostrar (obraSocial ob[N]){
	
	for (int i=0;i<N;i++){
		printf (" Obra social N° %d          -   Cantidad: %d     \n", i+1,ob[i].cant);
	}
	return;
}

void libera(puntero &cab, puntero p){  //Liberamos la memoría del montículo. 
	if(cab != NULL){
		libera(cab->sig, cab);
	} else {
		printf("\n\n Se liberó la memoria \n");
	}
	return;
}

/*...Algoritmo principal...*/
int main (){
	setlocale (LC_CTYPE, "Spanish");
	puntero cab;
	obraSocial ob[N];
	int aux=0,cont=0;
	cadena elem;
	
	inicia (ob);
	crear (cab);
	insertar (cab,ob);
	printf ("\n Cantidad de pacientes atendidos:  %d \n", total(cab,aux,cont));
	printf ("\n Cantidad de mujeres mayores de 50 años: %d \n", aux);
	printf ("\n Ingrese un DNI para cambiarle la Obra Social: ");
	gets(elem);
	fflush(stdin);
	cambio(cab,elem,ob);
	printf("\n Lista de Obra Sociales - Cantidad de pacientes atendidos \n");
	mostrar(ob);
	
	libera(cab->sig,cab);
	printf("--------------------------\n");
	printf("     FIN DEL PROGRAMA     \n");
	printf("--------------------------\n");
	getch();
}

/*
Lote de prueba
AA
BB
CC
DD
EE
FF
3
AballayG
31000000
30
M
2
CalivarA
32000000
51
F
3
CastroL
33000000
52
F
1
FernandezM
34000000
53
M
1
FunesG
35000000
30
F
4
36000000
31
M
6
37000000
32
M
6
38000000
33
F
0

*/
