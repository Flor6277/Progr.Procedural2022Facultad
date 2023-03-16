/*Ejercicio 2
Se tienen las notas de 25 estudiantes que cursan de 10 materias.*
Gererar una tabla y guardar esta información, donde las filas representen a los estudiantes.
Realizar un programa en C, que usando funciones para cada ítem, permita:
a) Mostrar todas las calificaciones del estudiante número 5. (Genere una función recursiva que reciba la fila con las notas
del estudiante).
b) Calcular la nota promedio de cada estudiante. */
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
	
	if(i < M){
		printf("\nNota de la materia %d: %d \n", i+1, est[i]);
		Mostrar(est, i+1);
	}
	else return;
}

void Promedio(int est[E][M]){
	
	for(int i=0; i<E; i++){
		float cont = 0;
		for(int j=0; j<M; j++){
			cont += est[i][j];
		}
		printf("\nLa nota promedio del estudiante %d es: %.2f ", i+1, cont/M);
	}
	return;
}

int main(){
	int estudiantes[E][M];
	
	Cargar(estudiantes);
	printf("\nNotas del estudiante 2: \n");
	Mostrar(estudiantes[1], 0); //5 en el enunciado
	Promedio(estudiantes);
	
	getch();
}
