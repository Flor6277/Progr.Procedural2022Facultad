#include <stdio.h>
#include <conio.h>

void Binario (int n){
  if (n > 0){
    Binario(n/2);
    printf("%d", n % 2);
   }
}
int  main(){
	int n;
	printf("\n Introduzca un entero positivo: ");
	scanf("%d", &n) ;
	printf("\n El Numero Decimal %d en binario es ", n);
	Binario(n);
	printf(" en binario");
}

