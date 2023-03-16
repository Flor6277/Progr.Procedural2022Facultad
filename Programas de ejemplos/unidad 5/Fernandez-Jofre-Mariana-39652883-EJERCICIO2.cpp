#include<stdio.h>
#include<malloc.h>

//ejercicio 2
/*Fernandez Jofre Mariana
DNI: 39.652.883
Registro: 21386
Carrera: TUPW
*/

typedef struct{
	
	int cod;
	float precio;
	
} productos;

struct nodo{
	
	productos dato;
	struct nodo *sig;
};

typedef struct nodo *puntero;

void crear(puntero &xp){
	
	xp=NULL;
	
	return;
}

void carga(puntero &xp){
	
	puntero nuevo;
	int xcod;
	
	printf("Ingrese el codigo del producto\n");
	scanf("%d",&xcod);
	
		while(xcod!= -1){
			nuevo=(puntero)malloc(sizeof(struct nodo));
			nuevo->dato.cod=xcod;
			printf("Ingrese precio\n");
			scanf("%f",&nuevo->dato.precio);
			nuevo->sig=xp;
			xp=nuevo;
			
			printf("Ingrese el codigo del producto, finalice con -1\n");
			scanf("%d",&xcod);
		}
	
}

void mostrar(puntero &xp){
	
	printf("----------------\n");
	
	if(xp!=NULL){
		
	
		printf("Codigo del producto: %d\n",xp->dato.cod);
		printf("Precio del producto: %2.f\n",xp->dato.precio);
	
		printf("\n");
		mostrar(xp->sig);
	} 
	return;

}

int maximo(puntero &xp){
	
	float max;
	int max_cod;
	max=0;
	
	while(xp!=NULL){
		
		if(xp->dato.precio > max){
			
			max= xp->dato.precio;
			max_cod=xp->dato.cod;
			puntero(xp);
		}
		xp=xp->sig;
	} 
		
		return max_cod;
	
}

/*int maximo(puntero &xp){
	int caro;
	float max=0;
	while(xp!=NULL){
		if(xp->imp > max){
			max= xp->imp;
			caro=xp->codig;
		}
		xp=xp->sig;
	}
		return(caro);	
}*/

int main(){
	
	puntero cabeza;
	int cod_max;
	
	crear(cabeza);
	carga(cabeza);
	mostrar(cabeza);
	
	cod_max= maximo(cabeza);
	
	printf("El codigo del producto mas caro es: %d\n",cod_max);
	
	return 0;
}

