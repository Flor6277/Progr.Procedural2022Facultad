#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct nodo{
	int valor;
	struct nodo *sig;
}; typedef struct nodo *puntero;

struct lista {
	char *nombre;
	puntero s;
	struct lista *sg;
}; typedef struct lista *pun;

void cerea (pun &a){
	a = NULL;
}

void recorre (pun b, pun k, pun a){
	if (k != NULL){
		a = k;
		k = k->sg;
		return recorre(b,k,a);
	}
	a->sg = b;
  	b->sg = NULL;
}

void recorre2 (puntero b, puntero k, puntero a){
	if (k != NULL){
		a = k;
		k = k->sig;
		return recorre2(b,k,a);
	}
	a->sig = b;
  	b->sig = NULL;
}

void CargaNodo (pun a){
	puntero nuevo, k, anterior;
	int num;
	printf ("Ingrese el valor para un nodo, de la lista %s \n", a->nombre);
	scanf("%d", &num);
	while (num != -1){
		nuevo = (puntero) malloc (sizeof(struct nodo));
		nuevo->valor = num;
		if(a->s == NULL){
			nuevo->sig = NULL;
			a->s = nuevo;
		}else {
			k = a->s;
			recorre2(nuevo, k, anterior);
		}
		printf ("Ingrese el valor para un nodo, de la lista %s o para terminar con -1\n", a->nombre);
		scanf("%d", &num);
	}
}

void carga (pun &a){
	char b[30];
	int l;
	pun nuevo, anterior, k;
	printf("Ingrese el nombre de la lista \n");
	gets(b);
	fflush(stdin);
	while(stricmp(b,"fin")!=0){
		nuevo = (pun) malloc(sizeof(struct lista));
		l= strlen(b);
		nuevo->nombre = (char*) malloc(sizeof(char)*l);
		strcpy(nuevo->nombre,b);
		if(a == NULL){
			nuevo->sg = NULL;
	     	a = nuevo;
		} else {
			k = a;
			recorre(nuevo,k,anterior);
		}
		nuevo->s = NULL;
		CargaNodo(nuevo);
		fflush(stdin);
		printf("Ingrese el nombre de la lista o termine con fin\n");
		gets(b);
		fflush(stdin);
	}
}

void mostrar (pun a, puntero p){
	printf("\n");
	while (a != NULL){
		fflush(stdin);
		printf("Lista: %s \n", a->nombre);
		printf("\n");
		p = a->s;
		while (p != NULL){
			printf("Valor: %d \n", p->valor);
			p = p->sig;
			printf("\n");
		}
	  	a = a->sg;
    }
}


int main (){
	pun a;	puntero p;
	cerea(a);
	carga(a);
	mostrar(a, p);
}
