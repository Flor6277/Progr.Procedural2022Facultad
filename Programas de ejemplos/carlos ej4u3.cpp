/*Ejercicio 4 unidad 3 carlos*/
#include<stdio.h>
#include<math.h>
#include<conio.h>
#define N 3

typedef struct{
int cod,cantUV;
float precioU,importeTT;
}productos;

void cereo(productos xprod[N]){
int i;
for(i=0;i<N;i++){
xprod[i].precioU=0;
xprod[i].cod=0;
xprod[i].cantUV=0;
xprod[i].importeTT=0;
}
return;
}

void cargaP(productos pro[N]){
int codi;
float precio;
printf("Ingrese el codigo del producto: (finaliza con 0)");
fflush(stdin);
scanf("%d",&codi);
while(codi!=0){
printf("Ingrese el precio unitario del producto: ");
fflush(stdin);
scanf("%f",&pro[codi-100].precioU);
printf("\nIngrese el codigo del producto: ");
fflush(stdin);
scanf("%d",&codi);
}
return;
}

void ventas(productos xp[N]){
int codigo,cant;
float acum=0;
printf("Ingrese un codigo: ");
fflush(stdin);
scanf("%d",&codigo);
while(codigo!=0){
printf("Ingrese la cantidad de unidades vendidas: ");
fflush(stdin);
scanf("%d",&cant);
xp[codigo-1].cantUV+=cant;
acum=xp[codigo-1].precioU*cant;
xp[codigo-1].importeTT+=acum;
printf("\nIngrese un codigo: ");
fflush(stdin);
scanf("%d",&codigo);
}
return;
}

void totalVendido(productos produ[N]){
int i,cont=0;
printf("\n\n");
for(i=0;i<N;i++){
printf("Cantidad de unidades vendidas del producto %d --> %d\n",i+1,produ[i].cantUV);
if((produ[i].cantUV > 20)&&(produ[i].cantUV < 50)){
cont++;
}
}
printf("\nCantidad de productos con unidades entre 20 y 50: %d",cont);
return;
}

int codMayorImporte(productos p[N],float *v1,int *v2){
int i,aux;
float max=0;
printf("\n\n");
for(i=0;i<N;i++){
if(max < p[i].importeTT){
max=p[i].importeTT;
aux=i;
*v1=max;
*v2=p[i].cantUV;
}
}
return(aux);
}

main(void){
productos produ[N];
int M,var2=0;
float var1=0;

cereo(produ);
cargaP(produ);
ventas(produ);
totalVendido(produ);
M=codMayorImporte(produ,&var1,&var2);

printf("\nCodigo con mayor importe: %d",M+1);
printf("\nImporte recaudado por el cod %d: $%.2f",M+1,var1);
printf("\nCantidad de unidades vendidas del cod %d: %d",M+1,var2);

getch();
}
