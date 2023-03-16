/*Recuperatorio Parcial 3 Turno Tarde Tema 2*/
/*Ejercicio 3 
Se tiene en un archivo "inscriptos.dat" la información de los inscriptos a cursos de actualización, de cada uno
se conoce Número de inscriptos, DNI, Nombre, Edad y Sexo. 
El archivo está ordenado en forma secuencial por número de inscripto a partir del número 1.
Se pide realizar un programa óptimo que a través del uso de funciones respondaa las siguientes solicitudes:
1) Generar una lista con la información de los inscriptos que son mujeres.
2) A partir de la lista generada, indicar la cantidad de mujeres a 21 años y la cantidad de mujeres mayores a 20 años.
Hacer una funcíon recursiva que devuelva ambos resultados al main.
3) Ingresar un número de inscripto y en el archivo modificar su nombre. */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

typedef struct{                //Estructura que hace referencia al archivo que se crea y a la lista
	char nomb[20], sexo;
	int DNI, edad,numIns;	
}inscripto;

struct nodo{                //Estructura que hace referencia a la lista que se crea
    inscripto dato;
    struct nodo * sig;
};
typedef struct nodo *puntero;

/*Esto no se hace en el ejercicio. Es sólo para crear el archivo con el que hay que trabajar*/
void genera(FILE *arch){                
    inscripto dato;
   	char nombre[20];
   	fpos_t x;
   	int num;
   	
	printf(" Ingrese: \n");
	fflush(stdin);
    printf(" Nombre: ");  
	gets(nombre);
    while (stricmp(nombre,"fin") != 0) {
    	strcpy(dato.nomb,nombre);
    	fseek(arch,0,SEEK_END);  
		fgetpos(arch,&x);
		num = (int)(x/sizeof(inscripto)) + 1;
		printf(" Número de inscripto asignado para %s: %d \n",nombre,num);
		dato.numIns = num;
        printf(" DNI: ");  
		scanf("%d", &dato.DNI); 
		printf(" Edad: ");  
		scanf("%d", &dato.edad);
		fflush(stdin);
		printf(" Sexo (F o M): ");  
		scanf("%c", &dato.sexo);           
        fwrite(&dato, sizeof(dato), 1, arch);
       	fflush(stdin);
   		printf("\n Nombre (termina con 'fin'): ");  
		gets(nombre);
    }
}

/*Esto no se hace en el ejercicio. Es sólo para crear el archivo con el que hay que trabajar*/
void mostrar(FILE *archi){                 
    inscripto dato;
    
	rewind(archi);
    printf("\n\n      Lista del archivo : \n\n");
    while (fread(&dato, sizeof(dato), 1, archi)){
        printf(" %d   %s   %d   %d   %c \n", dato.numIns, dato.nomb, dato.DNI, dato.edad, dato.sexo);
    }
}

/*1) 1) Generar una lista con la información de los inscriptos que son mujeres.*/
void generaLista(FILE *archi, puntero &xp){        
    inscripto a;
    
    rewind(archi);
    while (fread(&a, sizeof(a), 1, archi)){
        if(a.sexo == 'f' || a.sexo == 'F'){
            puntero nuevo;
            nuevo = (puntero) malloc (sizeof(struct nodo));
            nuevo->dato.numIns = a.numIns;
            strcpy(nuevo->dato.nomb, a.nomb);
            nuevo->dato.sexo = a.sexo;
            nuevo->dato.DNI = a.DNI;
            nuevo->dato.edad = a.edad;
            nuevo->sig = xp;
            xp = nuevo;
        }
    }
}

void muestraLista(puntero xp){              //esta función sirve para mostrar los datos de una lista.
	
	printf("\n\n    Lista creada desde el archivo: \n\n");
	while (xp != NULL) {
		printf("   %d    %s  %d   %d   %c  \n",xp->dato.numIns, xp->dato.nomb,xp->dato.edad,xp->dato.DNI,xp->dato.sexo);
		xp = xp->sig;
	}
}

/*2) A partir de la lista generada, indicar la cantidad de mujeres menores a 21 años y la cantidad de mujeres mayores a 20 años.
Hacer una funcíon recursiva que devuelva ambos resultados al main.*/
void contar(puntero xp,int i,int &mu20,int &mu21){
	
	if(xp != NULL){
		if(xp->dato.edad < 21) {
			mu21++;
		}
		if(xp->dato.edad > 20) {
			mu20++;
		}
		xp = xp->sig;
	} else return;
}

/*3) Ingresar un número de inscripto y en el archivo modificar su edad. */
void modificar(FILE *archi){ 
    inscripto a; 
	fpos_t x;
	int num;
	
    rewind(archi);
    printf("\n\n Ingrese el número de inscripto para modificar la edad: ");
    scanf("%d", &num);
  	fread(&a,sizeof(a),1,archi);
   	while (!feof(archi) && (num != a.numIns))    
    	fread(&a,sizeof(a),1,archi);
	if(!feof(archi)){
        printf("\n Ingrese la nueva edad del inscripto %d: ", num);
        scanf("%d",&a.edad); 
        fseek(archi,-sizeof(a),SEEK_CUR);                 
        fwrite(&a,sizeof(a),1,archi);
	}
}

int main(){
	setlocale (LC_CTYPE, "Spanish");
	FILE *archi;
	
		
	if((archi = fopen("PERSONAL.dat", "w+"))== NULL){
		printf(" Error al intentar abrir el archivo. ");
	} else {
		int mujeres21 = 0, mujeres20 = 0;
		puntero cabeza = NULL;
		genera(archi);
		mostrar(archi);
		generaLista(archi,cabeza);
		muestraLista(cabeza);
		contar(cabeza,0,mujeres20,mujeres21);
		printf("\n\n Cantidad de mujeres menores a 21 años: %d \n", mujeres21);
		printf("\n\n Cantidad de mujeres mayores a 20 años: %d \n", mujeres20);
		modificar(archi);
		mostrar(archi);
	}
	fclose(archi);
	printf("\n\n FIN DEL PROGRAMA \n\n");
	getch();
}

/*
nomb, DNI, edad, sexo
inscripto1
1230
29
m
inscripto2
1231
19
m
inscripto3
1232
31
m
inscripto4
1233
19
m
inscripto5
1234
35
f
fin
3
40
*/
