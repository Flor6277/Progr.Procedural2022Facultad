#include <stdio.h>
#include <conio.h>

int acumula_pares_impares(int &si,  int xnum) {   
int sp=0;
while (xnum){ 
          if (xnum%2==0)
                 sp+= xnum;
          else  
                 si+= xnum;
          xnum--;
     }
    return sp;
}

int main(){
	int sumai=0, num;
	printf("ingrese un numero "); 
	scanf("%d", &num);
	printf("suma de pares  = %d \n", acumula_pares_impares(sumai,num));
	printf("suma de impares = %d \n",sumai);
	getch();
}

