#include <stdio.h>
#include <conio.h>

int proceso( int n){
	if(n != 0) {
		return n + proceso(n-1);
	} else return 0;
}

int main() {
	int num;
	scanf("%d", &num);
	printf("Resultado es %d", proceso(num));
	
	getch();
}
