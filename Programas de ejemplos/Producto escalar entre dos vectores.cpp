#include <stdio.h>
typedef int vector[3]; //permite el uso del identificador vector como si fuera un tipo de datos

int escalar (vector a, vector b){//Operación producto escalar de vectores
	int e=0,i;
	
	for(i=0; i < 3; i++)
		e+=a[i]*b[i];
	return e ;
}

void carga(vector x) {//Operación de carga del vector
	int i;
		
	printf(" \n ingrese las componentes del vector ");
	for(i=0; i<3; i++)
		scanf("%d",&x[i]);
	return;
}

int main(void) {
	vector v1, v2;
	
	carga(v1);
	carga(v2);
	printf(" el producto escalar es %d ", escalar(v1,v2));
	getchar();
}	





