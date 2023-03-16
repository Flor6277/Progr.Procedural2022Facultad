/*Recuperatorio Parcial 3 Turno Tarde Tema 2*/
/*Ejercicio 2
Se procesa información de empleados, de cada uno se conocen los siguientes datos: DNI, número de sector donde trabaja(1..7) y sueldo.
Se pide que usando funciones para cada ítem, resuelva lo siguiente:
1) Ingresar por teclado la cantidad de empleados y cargar en un arreglo dinámico la información de cada uno de ellos.
2) Indicar la cantidad de empleados del sector 7. Hacer una función recursiva que devuelva este resultado.
3) Generar un archivo "PERSONAL.DAT" con los datos de los empleados con un sueldo que esté entre $180.000 y $250.000.*/
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

typedef struct {
	char nombEm[20];
	int DNI,sector;
	float sueldo;	
}emp;

/*1) Ingresar por teclado la cantidad de empleados y cargar en un arreglo dinámico la información de cada uno de ellos.*/
void carga(emp *a, int cant){
	
	printf(" Ingrese: \n");
	for(int i = 0; i<cant; i++){
		fflush(stdin);
		printf("\n Nombre: "); gets(a[i].nombEm);
		printf(" DNI: "); scanf("%d", &a[i].DNI);
		printf(" Sector: "); scanf("%d", &a[i].sector);
		printf(" Sueldo: "); scanf("%f", &a[i].sueldo);
	}	
}

/*2) Indicar la cantidad de empleados del sector 7. Hacer una función recursiva que devuelva este resultado.*/
void contar(emp *a, int cant, int i, int &cont1){
	
	if(i<cant){
		if(a[i].sector == 7){
			cont1++;
		}
		contar(a,cant,i+1,cont1);
	}else return;
}


/*3) Generar un archivo "PERSONAL.DAT" con los datos de los empleados con un sueldo que esté entre $180.000 y $250.000.*/
void genera(FILE *archi, emp *a, int cant){  //esta función sirve para copiar los datos de una lista en el archivo.
    emp d;
    
    for (int i = 0; i<cant; i++){
    	if ((a[i].sueldo >= 180000) && (a[i].sueldo <= 250000)){
	    	strcpy(d.nombEm,a[i].nombEm);
	        d.DNI = a[i].DNI;
	        d.sector = a[i].sector;
	        d.sueldo = a[i].sueldo;
	        fwrite(&d, sizeof(d), 1, archi);
	    }
    }
}

void mostrar(FILE *arch){  //esta función es solamente para saber si se cargaron bien los datos en el archivo. No lo piden
    emp a;
    
	rewind(arch);
    printf("\n\n   Lista creada:  \n\n");
    while (fread(&a, sizeof(a), 1, arch)){
        printf("   %s  %d  %.2f  %d \n", a.nombEm, a.sector, a.sueldo, a.DNI);
    }

}


int main (){
	setlocale (LC_CTYPE, "Spanish");
	emp *ar;
	FILE *archi;
	int cantidad, cont = 0;
	
	printf("\n Ingrese la cantidad de empleados: "); scanf("%d", &cantidad);
	ar = (emp*) malloc (sizeof(emp)*cantidad);
	carga(ar, cantidad);
	contar(ar,cantidad,0,cont);
	printf("\n\n Cantidad de empleados del sector 7: %d \n", cont); 
	if((archi = fopen("PERSONAL.dat", "w+"))== NULL){
		printf(" Error al intentar abrir el archivo. ");
	} else {
		genera(archi,ar,cantidad);
		free(ar);
		mostrar(archi);  //No va! Solamente es para mostrar 
	}
	fclose(archi);
	
	printf("\n\n FIN DEL PROGRAMA \n\n");
	getch();
}

/*
8
empeado1
123
1
60000
empeado2
124
1
100000
empeado3
125
2
200000
empeado4
126
7
230000
empeado5
127
4
120000
empeado6
128
7
60000
empeado7
129
2
651200
empeado8
130
7
600000
*/
