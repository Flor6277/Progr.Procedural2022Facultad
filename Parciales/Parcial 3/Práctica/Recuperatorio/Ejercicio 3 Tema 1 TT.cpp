/*Recuperatorio Parcial 3 Turno Tarde Tema 1*/
/*Ejercicio 3 
Se tiene en un archivo "inscriptos.dat" la información de los inscriptos a cursos de actualización, de cada uno
se conoce Número de inscriptos, DNI, Nombre, Edad y Sexo. 
El archivo está ordenado en forma secuencial por número de inscripto a partir del número 1.
Se pide realizar un programa óptimo que a través del uso de funciones respondaa las siguientes solicitudes:
1) Generar una lista con la información de los inscriptos que son mayores de 30 años.
2) A partir de la lista generada, indicar la cantidad de hombres y la cantidad de mujeres. Hacer una funcíon recursiva que
devuelva ambos resultados al main.
3) Ingresar un número de inscripto y en el archivo modificar su edad. */

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>


typedef struct {                //Estructura que hace referencia al archivo que se crea
	char nomb[20], sexo;
	int DNI, edad,numIns;
}inscripto;

struct nodo{    
	inscripto dato;
    struct nodo * sig;
};
typedef struct nodo *puntero;

struct nodo{                //Estructura que hace referencia a la lista que se crea
    int codi; 
    cadena titu;
    struct nodo * sig;
};
typedef struct nodo *puntero;

/*Esto no se hace en el ejercicio. Es sólo para crear el archivo con el que hay que trabajar*/
void genera(FILE *arch){                //esta función sirve para generar un archivo.
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
void mostrar(FILE *archi){                 //esta función sirve para mostrar un archivo creado.
    inscripto dato;
    
	rewind(archi);
    printf("\n\n      Lista : \n\n");
    while (fread(&dato, sizeof(dato), 1, archi)){
        printf(" %d  %s  %d  %d  %c \n", dato.numIns, dato.nomb, dato.DNI, dato.edad, dato.sexo);
    }
}

/*1) Generar una lista con la información de los inscriptos que son mayores de 30 años.*/
void cargaLista(FILE *archi, puntero &xp){        //esta función sirve para cargar los datos a una lista desde el archivo.
    inscripto a;
    
    rewind(archi);
    while (fread(&a, sizeof(a), 1, archi)){
        if(a.edad > 30){
            puntero nuevo;
            nuevo = (puntero) malloc (sizeof(struct nodo));
            strcpy(nuevo->nombre, a.nomb);
            nuevo->codi = a.cod;
            nuevo->sig = xp;
            xp = nuevo;
        }
    }
}


/*2) A partir de la lista generada, indicar la cantidad de hombres y la cantidad de mujeres. Hacer una funcíon recursiva que
devuelva ambos resultados al main.*/



/*3) Ingresar un número de inscripto y en el archivo modificar su edad. */



int main(){
	setlocale (LC_CTYPE, "Spanish");
	FILE *archi;
	int mujeres = 0, hombres = 0;
		
	if((archi = fopen("PERSONAL.dat", "w+"))== NULL){
		printf(" Error al intentar abrir el archivo. ");
	} else {
		puntero cabeza = NULL;
		genera(archi);
		mostrar(archi);
		generaLista(archi,cabeza);
//		contar(cabeza,0,mujeres,hombres);
//		printf(" Cantidad de hombres: %d \n", hombres);
//		printf(" Cantidad de mujeres: %d \n", mujeres);
//		modificar(archi);
//		mostrar(archi);
	}
	fclose(archi);
	
	printf("\n\n FIN DEL PROGRAMA \n\n");
	getch();
	
}

/*
dato.nomb, dato.DNI, dato.edad, dato.sexo);
inscripto1
1230
29
f
inscripto2
1231
30
f
inscripto3
1232
31
m
inscripto4
1233
32
m
inscripto5
1234
33
f
fin
*/
