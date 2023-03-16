#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define N 3
typedef char cad[50];
struct animal{
	cad nomb;
	cad nomcen;
	cad reino;
	int cant;
};
struct pais{
	cad nombre;
	struct nodo *esp;
};
struct nodo{
	animal datos;
	struct nodo *sig;
};
typedef nodo *especies;

void insertar(especies &xp,cad xn){
	especies nuevo;
	nuevo=(especies)malloc(sizeof(nodo));
	nuevo->sig=NULL;
	strcpy(nuevo->datos.nomb,xn);
	printf("\nIngrese nombre cientifico ");
	fflush(stdin);
	scanf("%s",&nuevo->datos.nomcen);
	fflush(stdin);
	printf("\nIngrese reino ");
	fflush(stdin);
	scanf("%s",&nuevo->datos.reino);
	fflush(stdin);
	printf("\nIngrese cantidad de ejemplares ");
	scanf("%d",&nuevo->datos.cant);	
	nuevo->sig=xp;
	xp=nuevo;
	
}

int cuenta(especies xp,int &cont2,int cont1){
	if(xp!=NULL){
		if(stricmp(xp->datos.reino,"flora")==0){
			cont1++;
			xp=xp->sig;
			cuenta(xp,cont2,cont1);
		}else if(stricmp(xp->datos.reino,"fauna")==0){
			cont2++;
			xp=xp->sig;
			cuenta(xp,cont2,cont1);
		}
	}else return(cont1);
}

void buscapet(especies xp){
	if(xp!=NULL){
		if(stricmp(xp->datos.nomb,"Petiribi")==0){
			xp->datos.cant+=200;
		}else{
			buscapet(xp->sig);
		}
	}else return;
}

int sumapet(especies xp,int c){
	if(xp!=NULL){
		if(stricmp(xp->datos.nomb,"Petiribi")==0){
			c+=xp->datos.cant;
		}else sumapet(xp->sig,c);
	}else return c;
}
int main(){
	int i,c1,c2=0,contpet=0;
	pais arr[N];
	cad n;
	
	for(i=0;i<N;i++){
		printf("\nIngrese el nombre del pais %d ",i+1);
		fflush(stdin);
		gets(arr[i].nombre);
		fflush(stdin);
		arr[i].esp=NULL;
	}
	
	for(i=0;i<N;i++){
		printf("\nPais: %s",arr[i].nombre);
		printf("\nIngrese un nombre de especie, finalice con FIN ");
		fflush(stdin);
		gets(n);
		fflush(stdin);
		while(stricmp(n,"FIN")!=0){
			insertar(arr[i].esp,n);	
			printf("\nIngrese un nombre de especie, finalice con FIN ");
			fflush(stdin);
			gets(n);
			fflush(stdin);
		}	
	}
	printf("\nIngrese un pais ");
	fflush(stdin);
	gets(n);
	fflush(stdin);
	i=0;
	while((i<N)&&(stricmp(n,arr[i].nombre))!=0){
		i++;
	}
	if(i<N){
		c1=cuenta(arr[i].esp,c2,0);
		printf("\nCantidad de especies de la flora en %s: %d",n,c1);
		printf("\nCantidad de especies de la fauna en %s: %d",n,c2);
	}else printf("\nEl pais buscado no existe");
	buscapet(arr[1].esp);
	for(i=0;i<2;i++){
		contpet+=sumapet(arr[i].esp,0);
	}
	printf("\nCantidad de ejemplares del Petiribi en Argentina y Brasil: %d",contpet);
}
/*
enchico 
parapiptadenia 
flora
15
jacaranda
jacaranda 
flora
3
pindo
syagrus 
flora
6
tigre
trigitus
fauna
4
fugazzeta
fugus mozza
fauna
1
petiribi
pete
flora
100
fin
petiribi
pete
flora
181
fin
fin
*/


