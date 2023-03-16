	/* Molina, Florencia - 37.647.311 - 21.004 - LSI */
#include <stdio.h>
#include <conio.h>
#define N 3

/*Algoritmo Practica_Operativa*/

/*FUNCION CARGA*/
void carga (int arr[N][N]){
	printf("\n   CARGA DE LOS DATOS \n");
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			printf(" Ingrese un elemento: ");
			scanf("%d", &arr[i][j]);
		}
	}		
	return;
}


//FUNCIÓN SUMA
int sumar(int arr[N][N]){
	int sum = 0;
	for(int i = 0; i<N; i++) {
		for(int j = 0; j<N; j++){
			if(i == j){
				sum = sum + arr[i][j];
			}
		}
    }
	return(sum);
}

//FUNCIÓN MUESTRA
void muestra(int arr[N][N]) {
	printf("\n --Arreglo bidimensional--\n");
	for(int i = 0; i<N; i++) {
		for(int j = 0; j<N; j++){
			printf("%5d ",arr[i][j]);
		}
		printf("\n");
    }
    return ;
}

/*FUNCIÓN MAYORES A 0*/
int mayoresA0(int arr[N][N]){
	int c = 0;
	for(int i = 0; i<N; i++) {
		for(int j = 0; j<N; j++){
			if(arr[i][j] > 0){
				c++;
			}
		}
    }
	return(c);
}

/*ALGORITMO PRINCIPAL*/
int main () {
	int arr[N][N];
	
	carga(arr);
	printf("\n La suma de los elementos de la diagonal principal es: %d \n\n",sumar(arr));
	muestra(arr);
	printf("\n\n Hay %d componentes mayores a 0 en el arreglo \n",mayoresA0(arr));
	getch();
}
















