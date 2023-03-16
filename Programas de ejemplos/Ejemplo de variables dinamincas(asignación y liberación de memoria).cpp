//Ejemplo de variables dinamincas(asignación y liberación de memoria)
#include <malloc.h>

int main(){
	//se declara un puntero a entero
	int * n;     
	
	//se solicita espacio para almacenar en el montículo una variable dinámica entera y la dirección 
	//obtenida como resultado, se guarda en el puntero n.                       
	n = (int *) malloc (sizeof (int));  
	//se asigna un valor a la variable apuntada por el puntero.
	*n = 12; 
	//permite liberar el espacio reservado a la variable dinámica apuntada por n.
	free(n); 
}
