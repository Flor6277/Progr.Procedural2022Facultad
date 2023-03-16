/*Ejercicio 8 Unidad 2*/

#include <stdio.h>
#define N 6
#define M 3

void cereo(float t[N][M]){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			t[i][j]=0;
		}
	}
	return;
}

void carga(float t[N][M],int &c){
	int i,j;
	float imp;
	printf("Ingrese mes (para terminar ingrese 0)\n");
	scanf("%d",&i);
	while(i != 0){
		if(i > 0 && i <= N){
			printf("Ingrese dpto(0 para terminar)\n");
			scanf("%d",&j);
			while(j != 0){
				if(j > 0 && j <= M){
					printf("Ingrese importe:\n");
					scanf("%f",&imp);
					t[i-1][j-1]+=imp;
					c++;
					printf("Ingrese dpto(0 para termianar)\n");
					scanf("%d",&j);
				}else{
					printf("No encontrado, ingrese dpto nuevamente (0 para terminar)\n");
					scanf("%d",&j);
				}
			}
			printf("Ingrese mes (para terminar ingrese 0)\n");
			scanf("%d",&i);
		}else{
			printf("No encontrado, ingrese mes nuevamente(0 para terminar)\n");
			scanf("%d",&i);
		}
	}
	return;
}

void mostrar(float t[N][M]){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			printf("|%.2f|",t[i][j]);
		}
		printf("\n");
	}
	return;
}

int buscar(float t[N][M],int m){
	float min=10000;
	int aux;
	for(int i=0;i<M;i++){
		if(t[m][i] < min){
			min=t[m][i];
			aux=i+1;
		}
	}
	return aux;
}

float prom(float t[N][M],int c){
	int sumador=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			sumador+=t[i][j];
		}
	}
	return sumador/c;
}

void incisod(float t[N][M],int m,int d,float prom){
	if(t[m][d] > prom){
		printf("Si supera el importe promedio de venta\n");
	}else{
		printf("No supera el importe promedio de venta\n");
	}
	return;
}

int main(){
	float tabla[N][M];
	int mes,contador=0,dpto;
	cereo(tabla);
	carga(tabla,contador);
	printf("Cantidad de ventas: %d\n",contador);
	mostrar(tabla);
	printf("Ingrese mes para buscar:\n");
	scanf("%d",&mes);
	printf("El dpto que menos vendio fue el %d\n",buscar(tabla,mes-1));
	printf("El importe promedio de venta de super es de: %.2f\n",prom(tabla,contador));
	printf("Ingrese mes y departamento:\n");
	scanf("%d",&mes);
	scanf("%d",&dpto);
	incisod(tabla,mes-1,dpto-1,prom(tabla,contador));
}
