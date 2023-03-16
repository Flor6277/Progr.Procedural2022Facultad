//Ejemplo de variables dinamincas(asignaci�n y liberaci�n de memoria)
#include <malloc.h>

int main(){
	//se declara un puntero a entero
	int * n;     
	
	//se solicita espacio para almacenar en el mont�culo una variable din�mica entera y la direcci�n 
	//obtenida como resultado, se guarda en el puntero n.                       
	n = (int *) malloc (sizeof (int));  
	//se asigna un valor a la variable apuntada por el puntero.
	*n = 12; 
	//permite liberar el espacio reservado a la variable din�mica apuntada por n.
	free(n); 
}
