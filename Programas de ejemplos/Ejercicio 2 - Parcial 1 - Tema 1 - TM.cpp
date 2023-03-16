#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#define E 2 //25 en el enunciado
#define M 2 //10 en el enunciado

void Cargar(int est[E][M]){
	
	for(int i=0; i<E; i++){
		for(int j=0; j<M; j++){
			printf(" Ingrese nota del estudiante %d: ", i+1);
			scanf("%d", &est[i][j]);
		}
	}
	return;		
}

void Mostrar(int est[M], int i){
	if(i < M)
	{
		printf("\n Nota de la materia %d: %d", i+1, est[i]);
		Mostrar(est, i+1);
	}
	else return;
}

void Promedio(int est[E][M]){
	
	for(int i=0; i<E; i++){
		int cont = 0;
		for(int j=0; j<M; j++){
			cont += est[i][j];
			printf("\nLa nota promedio del estudiante %d es: %.2f", i+1, (float)cont/M);
		}
	}
	return;
}

int main(){
	int estudiantes[E][M];
	
	Cargar(estudiantes);
	Mostrar(estudiantes[1], 0); //5 en el enunciado
	Promedio(estudiantes);
	
	getch();
}
