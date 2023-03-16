/*Ordenamiento de listas en forma ascendente*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>

typedef struct{
	int edad;
	char nombre[40];
}persona;

struct nodo{
	persona nro;
	struct nodo *sig;
};
typedef struct nodo *puntero;

void inicia(puntero &xp){	
	xp=NULL;
}
void carga(puntero &xp){
	
	puntero nuevo;
	int xnum;
	
	printf("Ingresar edad\n");
	scanf("%d",&xnum);
	while(xnum != 0){
		nuevo=(puntero)malloc(sizeof(struct nodo));
		nuevo->nro.edad=xnum;
		printf("Ingrese nombre\n");
		scanf("%s",nuevo->nro.nombre);
		nuevo->sig=xp;
		xp=nuevo;
		printf("Ingrese edad,finalice con cero\n");
		scanf("%d",&xnum);	
	}
	return;
}

void ordena(puntero &xp){
	
	puntero k,p,cota;
	int aux;
	char aux_nom[40];
	
	cota=NULL;
	k=NULL;
	while(k!=xp){
		
		k = xp;
		p = xp;
		
		while(p->sig != cota){
			if(p->nro.edad > p->sig->nro.edad){	
				aux=p->sig->nro.edad;
				p->sig->nro.edad= p->nro.edad;
				p->nro.edad=aux;
				strcpy(aux_nom,p->sig->nro.nombre);
				strcpy(p->sig->nro.nombre,p->nro.nombre);
				strcpy(p->nro.nombre,aux_nom);
				k=p;
			}
			p=p->sig;
		}
		cota=k->sig;
	}
	return;
}

void recorre(puntero xp){
	
	printf("-----------\n");
	
	if(xp!=NULL){
		
		printf("Edad: %d\n",xp->nro.edad);
		printf("Nombre: %s\n",xp->nro.nombre);
		printf("\n");
		recorre(xp->sig);	
	}
	return;
}

int main(){
	setlocale (LC_CTYPE, "Spanish");
	puntero cabeza;
	
	inicia(cabeza);
	carga(cabeza);
	ordena(cabeza);
	recorre(cabeza);
	
	getch();
}

/*
18
marcos
26
karen
25
mari
29
noel
27
flor
28
popi
45
agus
5
pedro
9
luis
21
juan
0
*/
