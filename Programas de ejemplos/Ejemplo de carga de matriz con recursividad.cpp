/*Ejemplo de matriz con recursividad (carga y muestra)*/
#include <stdio.h>
#define N 2
#define M 3

void carga(int xt[N][M], int i, int j){
	if(i<N){
		if (j<M) {
			printf("Ingrese un numero: ");
			scanf("%d",&xt[i][j]);
			carga(xt,i,j+1);
		} else {
			carga(xt,i+1,0);
		}
	} else {
		return;	
	}	
}

void muestra(int xt[N][M], int i, int j){
	
	
	if(i<N){
		if (j<M) {
			printf("%4d",xt[i][j]);
			muestra(xt,i,j+1);
		} else {
			printf("\n");
			muestra(xt,i+1,0);
		}
	} else {
		return;	
	}	
}

int main(){
	int tabla[N][M];
	
	carga(tabla,0,0);
	printf("\n   Arreglo bidimensional  \n");
	muestra(tabla,0,0);
		
	return 0;
}
