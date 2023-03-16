#include<stdio.h>
#include<malloc.h>
#define N 2

typedef struct{
	int doc;
	float monto;
}adjudicatario;

void cargaAdj(adjudicatario *A,int x,int c){
	if(x<c){
		printf("\n");
		printf("Ingrese DNI: ");
		fflush(stdin);
		scanf("%d",&A[x].doc);
		printf("Ingrese monto adeudado: ");
		fflush(stdin);
		scanf("%f",&A[x].monto);
		cargaAdj(A,x+1,c);
	}else{
		return;
	}
}

void ingresoDNI(adjudicatario *AA,int xC,int i,int D){

	if(i<xC) {
		if(D == AA[i].doc){
				printf("\nNumero del plan del documento %d: %d",AA[i].doc,i+1);
				printf("\nMonto adeudado del documento %d: $%.2f",AA[i].doc,AA[i].monto);
			}else{
				printf("\nDocumento no encontrado.");
			}
			ingresoDNI(AA,xC,i+1,D);
	} else return;
}

int main(){
	adjudicatario *ad;
	int i,dni,cant;
	
	for(i=0;i<N;i++){
		printf("Ingrese la cantidad de adjudicatarios del plan %d: ",i+1);
		fflush(stdin);
		scanf("%d",&cant);
		ad=(adjudicatario*)malloc(cant*sizeof(adjudicatario));
		cargaAdj(ad,0,cant);
		printf("\n");
	}
	
	printf("\nIngrese un dni: ");
	fflush(stdin);
	scanf("%d",&dni);
	
	ingresoDNI(ad,cant,N,dni);
	
	
	free(ad);
	
	return 0;
}
