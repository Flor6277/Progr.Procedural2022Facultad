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
#include <conio.h>
#include <locale.h>
#define N 2

typedef char cadena[20];
struct nodo{
	cadena nombPaciente;
	int cod,DNI,edad;
	cadena sexo;
	struct nodo *sig;
}; typedef struct nodo *puntero;

struct arreglo{
	cadena OS;
    puntero siguiente;
};

void crear(arreglo *a){ //*a es el puntero de la cabeza de la lista 
	cadena os;   
	
	fflush(stdin);
	for(int i = 0; i<N; i++){
		a[i].siguiente = NULL;
		printf("-----------------------------------\n");
		printf("Ingrese nombre de la Obra Social: %d \n", i+1);
		gets(os);
		fflush(stdin);
		strcpy(a[i].OS,os);
   }
   return;
}

void recorre(puntero &b, puntero k, puntero a){
	
	if (k != NULL){
  		a = k;
    	k = k->sig;
    	return recorre (b,k,a);
		}
	a->sig = b;
	b->sig = NULL;
}

int busqueda(puntero p, int i,cadena b, int e){
	if(p != NULL){
		if (stricmp(p->nombPaciente,b) != 0){
			e = 0;
		} else {
			return (e + 1);
			}
	    p = p->sig;
		return busqueda(p,i,b,e);
	}	 
}

void insertar(arreglo *a){
	puntero nuevo, p, aux, anterior;
	int n = 0;
	cadena cad,s;
	
	for(int i = 0; i<N; i++){
		printf("-----------------------------------\n");
        printf("Ingrese el nombre del paciente para la obra social %s:  ", a[i].OS);
        gets(cad);
        fflush(stdin);
		while(stricmp(cad,"fin") != 0){
			fflush(stdin);
			p = a[i].siguiente;
        	n = busqueda(p,i,cad,n);
			if (n == 0){
				nuevo = (puntero) malloc (sizeof(struct nodo));
        		strcpy(nuevo->nombPaciente,cad);  
        		fflush(stdin);
        		printf("Ingrese la edad:  ");
        		scanf("%d", &nuevo->edad);
        		printf("Ingrese el DNI:  ");
        		scanf("%d", &nuevo->DNI);
        		printf("Ingrese el sexo:  ");
        		fflush(stdin);
        		gets(s);
        		strcpy(nuevo->sexo,s); 
				if (a[i].siguiente == NULL){
        			nuevo->sig = NULL;
        			a[i].siguiente = nuevo;
				} else if (a[i].siguiente != NULL) {
					aux = a[i].siguiente;
		        	recorre(nuevo,aux,anterior);
				}
				fflush(stdin);  
				printf("\nIngrese el nombre del paciente (fin para terminar la carga) ");
        		gets(cad);
        		fflush(stdin);
		    } else {
				printf("El nombre: %s ya fue registrado en:  %s\n",cad,a[i].OS);
				printf("\nIngrese el nombre del paciente (fin para terminar la carga) ");
       		 	gets(cad);
       		 	fflush(stdin);
			}
		}	
	}
	return;
}

void mostrar(arreglo *a, puntero p){
	
	for(int i = 0; i<N; i++){
		p = a[i].siguiente;
		printf("\n-----------------------------------\n");
		printf("\n    Obra Social: %s \n", a[i].OS);
		while (p != NULL){
			printf(" Nombre: %s \n", p->nombPaciente);
			printf(" DNI: %d \n", p->DNI);
			printf(" Edad: %d \n", p->edad);
			printf(" Sexo: %s \n\n", p->sexo);
			p = p->sig;
		}
	}
	return;
}


/*Programa principal*/
int main (){
	setlocale (LC_CTYPE, "Spanish");
	arreglo *p;
	puntero cabeza;
		
	p = (arreglo*) malloc(sizeof(struct arreglo)*N);
	crear(p);           //p es el puntero a la cabeza de la lista
	insertar(p);
	mostrar(p,cabeza);
	printf("-------------------------------\n");
	printf("     FIN DEL PROGRAMA  \n");
	printf("-------------------------------\n");
	getch();
}

/*
LOTE DE PRUEBA
OSDE
OSPEDYC
FLORENCIA
29
37647311
FEMENINO
NOEL
27
38463511
FEMENINO
FIN
AGUSTINA
25
39955475
FEMENINO
FIN
*/
