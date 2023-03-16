/*Parcial 2  -  Tema 2  -  Turno Tarde*/
/*Ejercicio 2
Una agencia de empleo registra datos de postulantes a un puesto de trabajo. De cada uno registra nombre, sexo, DNI, edad y 
código de localidad donde vive (1..19).
Se pide que usando funciones para cada ítem, resuelva lo siguiente:
a)  Genere una lista enlazada con punteros para almacenar esta información.
b)  Mostrar en forma recursiva los nombres y DNI de los postulantes de la localidad 12.
c)  Indicar en el programa principal si algún postulante es mayor de 50 años.
d)  Decir cuántos mujeres son menores de 30 años. */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

typedef struct {
	char nomb[25], sexo;
	int DNI,edad,cod;
}post;

struct nodo{
	post dato;
	struct nodo *sig;
};
typedef struct nodo *puntero;


void crear(puntero &xp){
	xp = NULL;
}

/*Item a Genere una lista enlazada con punteros para almacenar esta información*/
void insertar (puntero &xp){ 
	puntero nuevo;
	char nombre[15];
	
	printf("\n Nombre (finaliza la carga con fin): ");
	fflush(stdin);
	gets(nombre);
	if (stricmp(nombre,"fin") != 0){ 
		nuevo = (puntero) malloc (sizeof(struct nodo));
		strcpy(nuevo->dato.nomb,nombre);
		printf(" Sexo: (F: 'Femenino'  -  M: 'Masculino'): ");
		fflush(stdin);
		scanf ("%c", &nuevo->dato.sexo);
		printf(" DNI: ");
		scanf ("%d", &nuevo->dato.DNI);
		printf(" Edad: ");
		scanf ("%d", &nuevo->dato.edad);
		printf(" Código de localidad (1..19): ");
		scanf ("%d", &nuevo->dato.cod);
		nuevo->sig = xp;
		xp = nuevo;
		insertar (xp);
	} else return;
}

/*Item b  Mostrar en forma recursiva los nombres y DNI de los postulantes de la localidad 12*/
void muestra(puntero xp){   
	
	if (xp != NULL){
		if(xp->dato.cod == 12){
			printf(" Nombre: %s  -  DNI: %d \n\n",xp->dato.nomb,xp->dato.DNI);
		}
		muestra(xp->sig);
	} 
}

/*Item c Indicar en el programa principal si algún postulante es mayor de 50 años*/
int busqueda(puntero xp){
	int b = 0;
	
	while(xp != NULL){
		if (xp->dato.edad > 50){
			b = 1;
		}
		xp = xp->sig;
	} return b;
}

/*Item d Decir cuántas mujeres son menores de 30 años.*/
int mujeres30(puntero xp, int &cant){   
	
	if (xp != NULL){
		if ((xp->dato.edad < 30) && ((xp->dato.sexo == 'f') || (xp->dato.sexo == 'F'))){
			cant++;
		}
		mujeres30(xp->sig,cant);
	} 
}

/*Algoritmo principal*/
int main() {
	setlocale (LC_CTYPE, "Spanish");
	puntero cabeza;	
	int cant = 0;

	crear(cabeza);
	printf("\n\n A continuación se cargan los datos de los postulantes: \n");
	insertar(cabeza);
	printf("------------------------------------------------------\n");
	printf("\n   **** POSTULANTES DE LA LOCALIDAD 12 **** \n\n");
	muestra(cabeza);
	printf("------------------------------------------------------\n");
	if (busqueda(cabeza) == 0) {
		printf("\n No existen postulantes mayores de 50 años \n");
	} else {
		printf("\n Existe al menos un postulante mayor de 50 años \n");
	}
	printf("\n------------------------------------------------------\n");
	mujeres30(cabeza,cant);
	printf("\n\n Cantidad de mujeres menores de 30 años: %d \n\n",cant);
	printf("\n\n FIN DEL PROGRAMA \n\n");
	getch();
}

/*
flor
f
37647311
29
19
noel
F
38463511
27
12
myri
f
17173035
57
19
pato
f
39955475
25
3
jose
M
12697420
63
12
majo
f
44019223
20
12
fin
*/
