#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct{   
     int reg;
     int nota;
}alumno;

void carga(alumno *&al, int c){
	int i;
    al=(alumno*) malloc(c *sizeof(alumno));
    for(i=0; i<c; i++){
		printf("\n ingrese registro  y nota del alumno %d: ", i+1);
		scanf ("%d   %d", &al[i].reg,&al[i].nota);   
	}
	return;
}
      
void muestra( alumno *al, int c){
	int i;
    
	printf("\n datos de los %d alumnos que rindieron : ", c);
    for(i=0; i<c; i++){
    	printf ("\n %5d   %5d",al[i].reg,al[i].nota); 
	}
	return;
}

int main(){
alumno *a;   
int ca;

    printf("\n Ingrese la cantidad de alumnos que rindieron ");   
    scanf( "%d",&ca);
    carga(a,ca);
    muestra(a,ca);

}
