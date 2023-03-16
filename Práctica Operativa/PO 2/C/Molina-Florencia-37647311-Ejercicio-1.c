/*
Molina Florencia
37.647.311
21.004
LSI*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

 /* Algoritmo Ejercicio_1_Práctica_Operativa*/
struct asistentes{
	char nombA[20];
	int edad;	
};

void carga(asistentes *a, int cant, int i){
	int acum = 0;
	
	fflush(stdin);
	if (i < cant){
		printf("\n Asistente %d \n", i+1);
		printf(" Nombre: ");
    	gets(a[i].nombA);
    	fflush(stdin);
		printf(" Edad: ");
    	scanf("%d",&a[i].edad);
    	carga(a,cant,i+1);
	} else return;
}

void mostrar(asistentes *a, int xc){
	
    printf("\nDatos de los %d asistentes a la conferencia: \n", xc);
    for(int i = 0; i<xc; i++) {
    	printf("\n Asistente %d \n", i+1);
    	printf("   %s   %d   \n",a[i].nombA,a[i].edad);  
	}
   return; 
}

int promedioEdad(asistentes *a, int cant){
	int acum = 0;
	
	for(int i = 0; i<cant; i++){
		acum = acum + a[i].edad;
	}
	return acum;
}
 
int main(){
	setlocale (LC_CTYPE, "Spanish");
	int cant_as, DNI_ref,p,s;
	asistentes *arr;
 	
	printf("\n Ingrese la cantidad de asistentes: ");
	scanf("%d",&cant_as);
	arr = (asistentes*) malloc (cant_as*sizeof(asistentes));  
    carga(arr,cant_as,0);
    printf("--------------------------------\n");
	mostrar(arr,cant_as);
	s = promedioEdad(arr,cant_as);
	printf("\n\nPromedio de Edades: %d años \n",s/cant_as);
	free(arr);   
	
	   
	getch(); 
}

/*Lote de prueba
5
JUAN
26
LUCIA
28
ANA
42
JOSE
50
LUIS
22
*/


