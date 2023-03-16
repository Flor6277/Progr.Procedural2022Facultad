#include <stdio.h>
#define N 3
typedef struct{
char nombr[20];
int edad, cant;
}alumno;

void carga(alumno alu[N]){
for(int i=0;i<N;i++){
    printf("Ingrese nombre del alumno [%d]\n", i+1);
    gets(alu[i].nombr);
    fflush(stdin);
    printf("Ingrese edad del alumno [%d]\n", i+1);
    scanf("%d", &alu[i].edad);
    fflush(stdin);
    printf("Ingrese cantidad de materias rendidas del alumno [%d]\n", i+1);
    scanf("%d", &alu[i].cant);
    fflush(stdin);
}
}

void lista(alumno alu[N], int i, int ed){
if(i<N){
    if(alu[i].edad<ed){
        printf("\n Nombre:%s\n", alu[i].nombr);
        printf("\nEdad:%d\n", alu[i].edad);
        printf("\nCantidad de materias rendidas:%d\n", alu[i].cant);
        lista(alu, i+1, ed);
    }
}
}

int materias(alumno alu[N], int &cont){
int c=0;
for(int i=0;i<N;i++){
    if(alu[i].cant==10){
        cont++;
    }
    else{
        if(alu[i].cant<10){
            c++;
        }
    }
}
return c;
}

int main(){
alumno alu[N];
int i=0, edd, p, conte=0;
carga(alu);
printf("Ingrese la edad deseada\n");
scanf("%d", &edd);
printf("LISTA DE ALUMNOS CON EDAD MENOR A %d\n", edd);
lista(alu, i, edd);
p=materias(alu, conte);
printf("Los alumnos con cantidad de materias rendidas iguales a 10 son: %d\n", conte);
printf("Los alumnos con cantidad de materias rendidas menores a 10 son: %d\n", p);
}
