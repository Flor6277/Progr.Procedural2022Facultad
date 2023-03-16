/*Ejercicio 5
En la Facultad se realiza un congreso para el cual se destinan 6 salas de conferencias y cada una representa un 
�rea tem�tica. En cada sala se dictar�n 4 conferencias en distintos turnos. Para procesar la informaci�n, en un 
primer momento y por �nica vez se ingresa el nombre de cada una de las 6 �reas tem�ticas que se tratar�n en el 
congreso y el cupo de personas para la sala donde se dictar� la misma.Por cada interesado se ingresa su  nombre, 
nombre del �rea tem�tica, y n�mero correspondiente a la conferencia a la que quiere asistir. La inscripci�n se realiza 
previa verificaci�n del cupo de la sala. A partir de la informaci�n ingresada generar una tabla que permita responder 
los siguientes �tems:
a) Decir para cada �rea tem�tica qu� conferencia tuvo menos asistentes y cu�l la mayor cantidad (Suponer el mayor 
y el menor como valores �nicos).
b) Indicar el nombre del �rea tem�tica con menos inscriptos.
c) Dado un nombre de �rea tem�tica decir cu�l fue el promedio de inscriptos.
d) Indicar la/s �reas tem�ticas que en alg�n turno tuvieron la sala completa, si las hubiera.*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define A 6
#define T 4

struct area{
    char nombA[20],nombI[20];
    int cupo;
    int cantI;
}ar[A][T];

void cargaA(area ar[A][T]){
	int cupo;
	char areaT[15];
	
    printf("\n---A continuacion se cargan los datos de las areas tematicas---\n\n");
	for(int i = 0; i<A; i++){
		printf("Ingrese el nombre del area numero %d: ",i+1);
		fflush(stdin);
		gets(areaT);
		printf("Ingrese el cupo disponible para el area %s: ", areaT);
		scanf("%d", &cupo);
		for(int j = 0; j<T; j++){
			ar[i][j].cupo = cupo;
			strcpy(ar[i][j].nombA,areaT);
			ar[i][j].cantI = 0;
		}
		printf("\n");
        printf("-----------------------------------------------\n");
    }
    return;
}

void muestra1(area ar[A][T]){
	printf("         DATOS REGISTRADOS:  \n");
	for(int i=0; i<A; i++){
		printf("         %s \n",ar[i][0].nombA);
		for(int j = 0; j<T; j++){
			printf("cupo: %5d ",ar[i][j].cupo);
			//printf("cantI: %5d ",ar[i][j].cantI);
		}
		printf("\n");
		printf("------------------------------\n");
	}
	return;
}

int busqueda(area ar[A][T],char nomb[20]){
	int i = 0;
	while ((i<A)&&(strcmp(ar[i][0].nombA,nomb) != 0)){
		i++;
	}
	if(i<A){
		return(i);
	} else return(-1);
}

void procesamiento(area ar[A][T]){
	char areaT[20];
	int pos, turno;
	
	printf(" Procesamiento de los datos:\n");
	printf("Ingrese el area a la que se quiere inscribir (finalice con fin): ");
	fflush(stdin);
    gets(areaT);
    
    while (strcmp(areaT,"fin") != 0) {
		pos = busqueda(ar,areaT);
    	if (pos != -1) {
			printf("Ingrese el turno de conferencia (entre 1 y 4): ");
			scanf("%d",&turno);
			ar[pos][turno-1].cupo = ar[pos][turno-1].cupo - 1;
			if (ar[pos][turno-1].cupo >= 0) {
			    ar[pos][turno-1].cantI = ar[pos][turno-1].cantI + 1;
				printf("Ingrese el nombre del estudiante: ");
    			fflush(stdin);
    			gets(ar[pos][turno-1].nombI);
        	} else  printf("\nNo hay cupo para el turno elegido \n");
		}		
		printf("\nIngrese el area a la que se quiere inscribir (finalice con fin): ");
		fflush(stdin);
    	gets(areaT);
    }
	return;
}

void menosI(area ar[A][T]){
	char nomb[15];
	int numC,j;
	
	for(int i = 0; i<A; i++){
		int min = ar[i][0].cantI;
		for(j = 1;j<T; j++){
			if(ar[i][j].cantI  < min ){
				min = ar[i][j].cantI;
				numC = j+1;
			}			
		}	
		printf("    %s \n",ar[i][j-1].nombA);
		printf("La conferencia %d tuvo la menor cantidad de asistentes\n",numC);
		printf("-----------------------------\n");		
		//printf("La conferencia %d del area %s tuvo la mayor cantidad de asistentes\n",max,nomb);
	}	
	return ;
}

void masI(area ar[A][T]){
	char nomb[15];
	int numC,j;
	
	for(int i = 0; i<A; i++){
		int max = ar[i][0].cantI;
		for(int j = 1; j<T; j++){
			if(ar[i][j].cantI  > max ){
				max = ar[i][j].cantI;
				numC = j+1;
			}			
		}	
		printf("    %s \n",ar[i][j-1].nombA);
		printf("La conferencia %d tuvo la mayor cantidad de asistentes\n",numC);
		printf("-----------------------------\n");		
		//printf("La conferencia %d del area %s tuvo la mayor cantidad de asistentes\n",max,nomb);
	}	
	return ;
}

int main(){
			
    cargaA(ar);
    procesamiento(ar);
    muestra1(ar); 
	menosI(ar);
	masI(ar);
	
	    
    getch();    
}
