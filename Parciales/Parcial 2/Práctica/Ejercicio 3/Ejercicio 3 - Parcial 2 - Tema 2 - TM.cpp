#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>

struct nodo {
	int nro;
    struct nodo *sig;
};
typedef struct nodo *puntero;

void insertar (puntero & xp){
	int dato;
	puntero nuevo;
	
	printf("\n Ingrese el nuevo valor (0 para terminar): ");
	scanf("%d",&dato);
	while (dato != 0){
		nuevo =(puntero) malloc(sizeof(struct nodo));
		nuevo->nro = dato;
		nuevo->sig = xp;
		xp = nuevo;
		printf("\n Ingrese el nuevo valor (0 para terminar): ");
		scanf("%d",&dato);
	}
	return;
}

void recorre (puntero xp){
	
	printf("\n Listado de datos \n");
	while (xp != NULL){
		printf("     %d \n",xp->nro);
		xp = xp->sig;
	}
}

void proceso(puntero xp, int v, int n){

    if(xp == NULL)
        printf("\n El numero no está en la lista");
    else if (xp->nro == v) {
        xp->nro = n;
        return;
    } else proceso (xp->sig, v, n);
}

/*Algoritmo principal*/
int main() {
	setlocale (LC_CTYPE, "Spanish");
    puntero cabeza;
    int viejo, nuevo;
    cabeza = NULL;

    insertar(cabeza);
    recorre(cabeza);
    printf(" Ingrese el valor a modificar : ");
    scanf("%d", &viejo);
    printf(" Ingrese el nuevo valor : ");
    scanf("%d", &nuevo);
    proceso(cabeza,viejo,nuevo);
    recorre(cabeza);
    
    getch();
}

/*
4
2
6
0
2
8
*/
