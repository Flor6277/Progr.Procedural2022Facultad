/*Ejemplo de teor�a*/
#include <malloc.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

struct alumno {
    char nom[20];
    float prom;
};

int main(){
	setlocale (LC_CTYPE, "Spanish");
	int *n, num; //se declara un puntero a entero y una variable num
	alumno *p;   
	                                       
	printf("\nIngrese un n�mero entero: ");
	scanf("%d",&num);
	//se solicita espacio para almacenar en el mont�culo una variable din�mica entera y la direcci�n 
	//obtenida como resultado, se guarda en el puntero n.
	n = (int *) malloc (sizeof (int));     
	//se asigna el valor num a la variable apuntada por el puntero.
	*n = num;   //n guarda la direccion de memoria de la variable num
	p = (alumno *) malloc (sizeof (alumno));
	fflush(stdin);
	printf("\nIngrese nombre "); 
	gets(p-> nom);
	printf("\nIngrese promedio ");
	scanf("%f", &p-> prom);
	printf("\n N�mero entero es %d ", *n);
	printf("\n El alumno ingresado es %s y tiene promedio %.2f \n", p -> nom, p -> prom);
	free(n);  //permite liberar el espacio reservado a la variable din�mica apuntada por n.
	free(p);  //permite liberar el espacio reservado a la variable din�mica apuntada por p.
	getch();	                                        
}

