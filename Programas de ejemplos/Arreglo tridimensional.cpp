#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define M 20
#define N 25


void carga(int ar[M][N]){
	
	printf("\n-------------------------------   \n");
	srand(time(NULL));
	for(int i=0; i<M; i++){
		for(int j=0;j<N; j++){
			ar[i][j] = 1 + rand () % (201-1);
		}
	}
	return;
}

void muestra(int ar[M][N]){

	printf("\n Datos cargados   \n");
	for(int i=0; i<M; i++){
		for(int j=0;j<N; j++){
			printf("%6d",ar[i][j]);
		}
		printf("\n");
	}
	return;	
}

int main () {
	int ar[M][N];
	
	carga(ar);
	muestra(ar);
		
	getch();
}
