


#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#define N 6

typedef char cadena[30];
typedef struct {
	cadena nombre;
	int dni;
	int os;
	int edad;
	char sexo;
} paciente;

struct nodo {
	paciente dato;
	struct nodo *sig;
	};
typedef struct nodo *puntero;

typedef struct {
cadena nombre;
	int cant;
} obra;


void inicia (obra ob[N]){
for (int i=0;i<N;i++){
	ob[i].cant=0;
	printf ("obra social numero %d \n",i+1);
	fflush (stdin);
	gets (ob[i].nombre);
}
}
void crear (puntero &xp){
xp=NULL;
}
void insertar (puntero &xp,obra ob[N]){
puntero nuevo;
int num;
printf (" ingrese obra social. 0 para finalizar \n");
scanf ("%d",&num);
while (num){
	nuevo=(puntero)malloc(sizeof(struct nodo));
	nuevo->dato.os = num;
	ob[num-1].cant++;
	printf ("ingrese nombre \n");
	fflush (stdin);
	gets (nuevo->dato.nombre);
	printf ("ingrese dni \n");
	scanf ("%d",&nuevo->dato.dni);
	printf ("ingrese edad \n");
	scanf ("%d",&nuevo->dato.edad);
	printf ("ingrese sexo \n");
	fflush (stdin);
	scanf ("%c",&nuevo->dato.sexo);
	nuevo->sig=xp;
	xp=nuevo;
	printf ("ingrese obra social. 0 para finalizar \n");
	scanf ("%d",&num);
}
}
int total (puntero &xp,int &aux, int cont){
if (xp!=NULL){
	if ((xp->dato.sexo=='F')&&(xp->dato.edad>=50)){
		aux++;
	} 
	total (xp->sig,aux,cont+1);
}else
return cont;
}
void cambio (puntero &xp,int num){
int nuevo;
while ((xp!=NULL)&&(xp->dato.dni!=num)){
	xp=xp->sig;
}
if (xp==NULL){
	printf ("\n el documento no se encuentra en la lista");
}else{
 printf ("ingrese numero nueva obra social \n");
	scanf ("%d",&nuevo);	
	xp->dato.os=nuevo;
}
}
void mostrar (obra ob[N]){
for (int i=0;i<N;i++){
	printf ("\n obra social numero %d", i+1);
	printf ("\n cantidad de inscriptos %d",ob[i].cant);
}
}
int main (){
	puntero cab;
	obra ob[N];
	int aux=0,elem,cont=0;
	inicia (ob);
	crear (cab);
	insertar (cab,ob);
	printf ("\n total pacientes atendidos %d", total(cab,aux,cont));
	printf ("\n mujeres mayores de 50 %d", aux);
	printf ("\n ingrese dni a a cambiar");
	scanf ("%d",&elem);
	cambio (cab,elem);
	mostrar (ob);
	
	getch();
}



