/*Ejercicio recursividad:
Realice una funcion recursiva que sume los primeros n enteros positivos. 
Nota: Para plantear la función recursiva tenga en cuenta que la suma puede expresarse mediante la siguiente recurrencia:
	suma(n) = 1            	,si n = 1
		n + suma(n-1)	   	,si n > 1   */
#include <stdio.h>
#include <conio.h>

int suma (int xn){
	int sum = 0;
	
	if(xn == 1){
		sum = 1;
	} else {
		sum = xn + suma(xn-1);
	}
	return sum;
}



int main(){
	int n;
	
	printf("\n\nIngrese un numero entero positivo: ");
	scanf("%d", &n);
	printf("\nLa suma de los primeros %d numeros positivos es: %d \n",n,suma(n));
	
	getch();
}
