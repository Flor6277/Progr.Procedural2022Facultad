#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <locale.h>

void carga(int *&x, int t){
	srand(time(0));
    x=(int*)malloc(t*sizeof(int));
    for(int i=0; i<t; i++){
        x[i]= 1 + rand() % 20-1;
    }
}

void muestra(int *&x, int t){
	
    for(int i=0; i<t; i++){
        printf("%3d",x[i]);
    }
    printf("\n");
}

int escalar(int *x, int *y, int t, int i){
    if(i<t) 
		return x[i]*y[i] + escalar(x,y,t,i+1);
    else return 0;
}

int impares(int *x, int t){
    int cont=0; 
    for(int i=0; i<t; i++){
        if(x[i]%2!=0){
            cont++;
        }
    }
    return cont;
}
 
int cargasub(int *x, int t, int *&c){
	int cont1=0; 
	int tam=impares(x,t);
	c = (int*)malloc(tam*sizeof(int));
	for(int i=0; i<t; i++){
        if(x[i]%2!=0){
            c[cont1]=x[i];
            cont1++;
    	}
	}
	return cont1;
}  

void mostrar(int *c, int n){
	for(int i=0; i<n; i++){
		printf("%3d ", c[i]);
	}
}

int main(){
	setlocale (LC_CTYPE, "Spanish");
    int *a,*b,n,m,*c,c1;
    
    printf("Ingrese el tamaño del arreglo a \n");
    scanf("%d",&n);
    printf("Ingrese el tamaño del arreglo b\n");
    scanf("%d",&m);
    carga(a,n);
    carga(b,m);
    printf("\nVector a \n");
    muestra(a,n);
    printf("\nVector b \n");
    muestra(b,m);
    if(n<m) 
		printf("\nEscalar: %d\n", escalar(a,b,n,0));
    else if(m<n) printf("\nEscalar: %d\n", escalar(a,b,m,0));
    c1 = cargasub(a,n,c);
    printf("\n\nNuevo arreglo con componentes impares del arreglo a \n");
    mostrar(c,c1);
}
