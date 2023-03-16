/*Ejercicio Repaso
En un Instituto se dictará un curso de Desarrollador Web. Se registrá la siguiente información de los inscriptos: 
Número de inscripción (es secuencial y comienza en 1), Nombre y Apellido, DNI, Domicilio, Numero de celular y Edad.
Codificar un programa en Lenguaje C que usando funciones óptimas permita:
a) Generar una lista con la información de los inscriptos.
b) A partir de la lista generada, indicar en el main la cantidad de total de inscriptos y la cantidad de inscriptos 
mayores de 40 años. Realizar una función recursiva que devuelva los dos valores, uno a través del retorno y otro por parámetro.
c) Generar y mostrar de forma ascendente(edad) un arreglo dinámico con la información de los inscriptos mayores de 40 años.*/

#include <stdio.h>
#include <string.h>	 
#include <conio.h>
#include <malloc.h>
#include <locale.h>


typedef struct{
	int edad, numIns;
	char nya[40];
} inscriptos;

struct nodo{
	inscriptos datos;
	struct nodo *sig;
};
typedef struct nodo *puntero;

struct mayores{
	int ed, num;
	char nomb[40];
};


void carga(puntero &xp){
	xp = NULL;
}


void insertar(puntero &xp){
	puntero nuevo;
	char nomb[40];
		
	printf(" Nombre: ");
	gets(nomb);
	fflush(stdin);
	while (stricmp(nomb,"FIN") != 0){
		nuevo = (puntero)malloc(sizeof(struct nodo));
		strcpy(nuevo->datos.nya,nomb);
		printf(" Número de inscripción: ");
		scanf("%d", &nuevo->datos.numIns);
		printf(" Edad: ");
		scanf("%d", &nuevo->datos.edad);
		nuevo->sig = xp;
		xp = nuevo;
		fflush(stdin);
		printf("\n Ingrese el nombre (finaliza con FIN): ");
		gets(nomb);
	}
}

void ordenar(puntero xp){
	puntero k,p,cota;
	int auxEdad,auxNum;
	char aux_nom[40];
	
	cota = NULL;
	k = NULL;
	while(k != xp){
		k = xp;
		p = xp;
		while(p->sig != cota){
			if(p->datos.numIns > p->sig->datos.numIns){
				auxNum = p->sig->datos.numIns;
				p->sig->datos.numIns = p->datos.numIns,
				p->datos.numIns = auxNum;
				
				strcpy(aux_nom,p->sig->datos.nya);
				strcpy(p->sig->datos.nya,p->datos.nya);
				strcpy(p->datos.nya,aux_nom);
				
				auxEdad = p->sig->datos.edad;
				p->sig->datos.edad = p->datos.edad,
				p->datos.edad = auxEdad;

				k = p;
			}
			p = p->sig;
		}
		cota = k->sig;
	}
	return;
}


void muestra(puntero xp){
	
	if (xp != NULL){
		printf(" %d    %s   %d  \n",xp->datos.numIns,xp->datos.nya, xp->datos.edad);
		muestra(xp->sig);
	}	
}


int contar(puntero xp, int &xc){
	int cont = 0;
	
	while (xp != NULL){
		cont++;
		if(xp->datos.edad > 40){
			xc++;
		} 
		xp = xp->sig;
	}
	return cont;
}


void generarArreglo(puntero xp, mayores *&a, int &cant, int i){	

	if (i < cant){
		while (xp != NULL){
			if (xp->datos.edad > 40){
				strcpy(a[i].nomb,xp->datos.nya);
				a[i].ed = xp->datos.edad;
				a[i].num = xp->datos.numIns;				
			}
			xp = xp->sig;
			generarArreglo(xp,a,cant,i+1);	
		}
	}
	return;
}


void mostrar(mayores *a, int &xc)	{
	
    printf("\n Datos de los %d inscriptos mayores de 40 años: \n", xc);
    for(int i = 0; i<xc; i++) {
    	printf("     Inscripto %d \n", i+1);  
    	printf("     Nombre: %s   Edad: %d  N°: %d \n\n",a[i].nomb,a[i].ed,a[i].num);
	}
   return; 
}


int main() {
	setlocale (LC_CTYPE, "Spanish");
	puntero cabeza;
	mayores *arr;
	int cantidad = 0;
	
	carga(cabeza);
	printf("\n A continuación se cargan los datos de los inscriptos: \n\n");
	insertar(cabeza);
	ordenar(cabeza);
	printf("\n\n Lista generada: \n");
	muestra(cabeza);
	printf("\n\n Cantidad total de inscriptos: %d ",contar(cabeza,cantidad));
	printf("\n\n Cantidad de inscriptos mayores a 40 años: %d \n\n", cantidad);
	arr = (mayores*)malloc(cantidad*sizeof(mayores));
	generarArreglo(cabeza,arr,cantidad,0);
	mostrar(arr,cantidad);
	free(arr);
	printf(" FIN DEL PROGRAMA \n");	
	
	getch();
}

/*
marcos
1
18
karen
2
25
flor
3
29
popi
8
45
agus
5
50
pedro
9
59
luis
6
65
juan
4
7
fin
*/
