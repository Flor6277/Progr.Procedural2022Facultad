


#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define N 6 //obras sociales


typedef struct{ 
	char nombre[40];
	int dni,codigo,edad;
	
} pacientes;

struct nodo{
	pacientes dato;
	struct nodo *sig;
};

typedef struct nodo *puntero;


void crear(puntero &xp){
	
	xp=NULL;
}

void carga(puntero &xp){
	
	puntero nuevo;
	int cod;
	
	printf("Ingrese codigo de obra social(1-6)\n");
	scanf("%d",&cod);
	
	while(cod!=0){
		
		nuevo=(puntero)malloc(sizeof(struct nodo));
		printf("Ingrese nombre del paciente\n");
		scanf("%s",nuevo->dato.nombre);
		printf("Ingrese el dni\n");
		scanf("%d",&nuevo->dato.dni);
		printf("Ingrese la edad\n");
		scanf("%d",&nuevo->dato.edad);
		nuevo->dato.codigo=cod; //guardo el num de obra social
		xp=nuevo;
		xp->sig=NULL;
		printf("Ingrese codigo de obra social(1-6),finalice con cero\n");
		scanf("%d",&cod);
		
	}
}

void recorre(puntero &xp){
	
	printf("listado\n");
	while(xp!=NULL){
		
		printf("%s\n",xp->dato.nombre);
		printf("%d\n",xp->dato.dni);
		printf("%d\n",xp->dato.edad);
		printf("%d\n",xp->dato.codigo);
		xp=xp->sig;
	}
	
	return;
}
int main(){
	
	puntero cabeza;
	
	carga(cabeza);
	recorre(cabeza);
	
	return 0;
}

/*
Lote de prueba
3
florencia
37647311
29
5
mariana
39456254
25
0

*/
