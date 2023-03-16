#include <stdio.h>

int proceso( int n){
	if(n != 3) {
		return n + proceso(n+1);
	} else return 0;
}

int main() {
	int num;
	scanf("%d", &num);
	printf("Resultado es %d", proceso(num));
}
