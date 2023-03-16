#include<stdio.h>
#include<malloc.h>


struct nodo{
	int nro;
	struct nodo *sig;	
};
typedef nodo *puntero;

void crear(puntero &xp){ //dirección de memoria apunta a NULL
	
	xp=NULL;
	
	return;
}

void carga(puntero &xp){ 

int xnum;
puntero nuevo;

	printf("Ingresar un numero entero positivo\n");
	scanf("%d",&xnum);
	
	while(xnum!=0){
		
		nuevo=(puntero)malloc(sizeof(struct nodo));
		nuevo->nro=xnum;
		nuevo->sig=xp;
		xp=nuevo;
		
		printf("Ingresar un numero entero positivo\n");
		scanf("%d",&xnum);
	}

	return;
}

void ordenar(puntero &xp){
	
	puntero k,cota,p;
	int aux;
	
	cota=NULL;
	k=NULL;
	
	while(k!=xp){
		
		k=xp;
		p=xp;
		
			while(p->sig!=cota){
				
				if(p->nro > p->sig->nro){
					
					aux=p->sig->nro;
					p->sig->nro=p->nro;
					p->nro=aux;
					k=p;
				}
				p=p->sig;
			}
			cota=k->sig;
	}
	return;
}


void mostrar(puntero &xp){
	
	if(xp!=NULL){
		
		printf("%d\n",xp->nro);
	
		mostrar(xp->sig);
	} 
	return;

}

void par(puntero &xp){
	
	if(xp!=NULL){
		if(xp->sig !=NULL){
			xp=xp->sig;
			par(xp);
		} else if((xp->nro) % 2 == 0){
			
			printf("El ultimo numero si es par\n");
		} else{
			
			printf("El ultimo numero no es par\n");
		}
	}
	return;
}

int main(){
	
	puntero cabeza;
		
	crear(cabeza);
	carga(cabeza);
	ordenar(cabeza);
	mostrar(cabeza);
	par(cabeza);


	
	return 0;
}



