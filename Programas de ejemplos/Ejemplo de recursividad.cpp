#include <stdio.h>
#include <conio.h>

void listar (int n){
	
	if (n != 0){
		printf("\n %d", n);
		listar(n-1);
		printf("\n %d", n);
	} else printf("\n el numero es 0");
	
	return;
}

int main () {
	
	int a = 4;
	
	listar(a);
	
	getch();
}
