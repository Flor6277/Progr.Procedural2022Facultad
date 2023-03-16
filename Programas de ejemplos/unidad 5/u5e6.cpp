#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<conio.h>
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
void crear (pais &xp){
	xp.esp=NULL;
}
void insertar(pais &xp,cad xn){
	especies nuevo;
	nuevo=(especies)malloc(sizeof(nodo));
	strcpy(nuevo->datos.nomb,xn);
	printf("\nIngrese nombre cientifico ");
	fflush(stdin);
	gets(nuevo->datos.nomcen);
	fflush(stdin);
	printf("\nIngrese reino ");
	fflush(stdin);
	gets(nuevo->datos.reino);
	fflush(stdin);
	printf("\nIngrese cantidad de ejemplares ");
	scanf("%d",&nuevo->datos.cant);	
	nuevo->sig=xp.esp;
	xp.esp=nuevo;
}
void cargapais(pais &a,cad name){

	if(stricmp(name,"FIN")!=0){
	insertar(a,name);	
	printf("\nIngrese un nombre de especie, finalice con FIN ");
	fflush(stdin);
	gets(name);
	fflush(stdin);
	cargapais(a,name);	
	}else return;
}
int cuenta(pais a[],int &cont2,int j){
	static int cont1=0;
	if(a[j].esp!=NULL){
		if(stricmp(a[j].esp->datos.reino,"flora")==0){
			cont1++;
			a[j].esp=a[j].esp->sig;
			cuenta(a,cont2,j);
		}else if(stricmp(a[j].esp->datos.reino,"fauna")==0){
			cont2++;
			a[j].esp=a[j].esp->sig;
			cuenta(a,cont2,j);
		}
	}else return(cont1);
}
void recorre(pais a){
	if(a.esp!=NULL){
		printf("\nNombre: %s",a.esp->datos.nomb);
		printf("\nNombre cientifico: %s",a.esp->datos.nomcen);
		printf("\nReino: %s",a.esp->datos.reino);
		printf("\nCantidad de ejemplares: %d",a.esp->datos.cant);
		a.esp=a.esp->sig;
		recorre(a);
	}else return;
}
void buscapet(pais &a){
	static especies p;
	p=(especies)malloc(sizeof(especies));
	p=a.esp;
	if(a.esp!=NULL){
		if(stricmp(a.esp->datos.nomb,"Petiribi")==0){
			a.esp->datos.cant+=200;
		}else p=p->sig;
		buscapet(a);
	}else return;
}
void sumapet(pais a,int &c){
	if(a.esp!=NULL){
		if(stricmp(a.esp->datos.nomb,"Petiribi")==0){
			c+=a.esp->datos.cant;
		}else sumapet(a,c);
	}else return;
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
		crear(arr[i]);
	}
	for(i=0;i<N;i++){
		printf("\nPais: %s",arr[i].nombre);
		printf("\nIngrese un nombre de especie, finalice con FIN ");
		fflush(stdin);
		gets(n);
		fflush(stdin);
		cargapais(arr[i],n);
	}
	recorre(arr[0]);
	printf("\nIngrese un pais ");
	fflush(stdin);
	gets(n);
	fflush(stdin);
	i=0;
	while((i<N)&&(stricmp(n,arr[i].nombre))!=0){
		i++;
	}
	if(i<N){
		c1=cuenta(arr,c2,i);
		printf("\nCantidad de animales de la flora en %s: %d",n,c1);
		printf("\nCantidad de animales de la fauna en %s: %d",n,c2);
	}else printf("\nEl pais buscado no existe");
	buscapet(arr[1]);
	for(i=0;i<2;i++){
		sumapet(arr[i],contpet);
	}
	printf("\nCantidad de ejemplares del Petiribi en Argentina y Brasil: %d",contpet);
}
/*
Enchico Colorado
Parapiptadenia Rigida
Flora
15
Jacaranda
Jacaranda Mimosifolia
Flora
3
Pindo
Syagrus Romanzoffiana
Flora
6
fin
fin
fin
*/


