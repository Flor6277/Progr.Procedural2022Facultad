#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 3 // salas o areas tematicas
#define M 2 //turnos

struct salas{
	
	char nombre[40];
	int cupo; //determina la cantidad de alumnos que se acepta para esa sala
};

struct turnos{
	
	int cant; //cantidad de alumnos inscriptos en ese turno
};

void iniciar(struct salas xs[N],struct turnos xt[M]){
	
	int i;
	
	for(i=0;i<N;i++){
		
		printf("Ingresar el nombre del area %d\n",i+1);
		scanf("%s",xs[i].nombre);
		printf("Ingresar el cupo maximo permitido\n");
		scanf("%d",&xs[i].cupo);
	}
	
	for(i=0;i<M;i++){
		
		xt[i].cant=0;
	}
	
	return;
}

//en la busqueda encuentro la posicion del area la cual ingrese su nombre
int busqueda(struct salas xs[N], char xnombre[40]){
	
	int i;
	i=0;
	while( (i<N) && (strcmp(xs[i].nombre,xnombre) !=0 ) ){
		
		i=i+1;
	}
	
		if(i<N){
			return(i);
		} else{
			return(-1);
		}
}


void carga(struct salas xs[N],struct turnos xt[M]){
	
	char xn[40],na[40]; // xn nombre del alumno, na nombre del alumno
	int nt,pos; //numero de turno al que quiere asistir el alumno
	
	printf("Ingresar el nombre del alumno\n");
	scanf("%s",xn);
	
	while( strcmp(xn,"fin") !=0){
		
			printf("Ingresar el nombre del area a la que quiere asistir\n");
			scanf("%s",na);
		
		pos=busqueda(xs,na);
		
		if(pos!=-1){
			
			printf("Ingresar el numero de turno (1-4) \n");
			scanf("%d",&nt);
		
			xt[nt-1].cant= xt[nt-1].cant + 1;
		} else{
			
			printf("Nombre incorrecto\n");
		}
		
		if(xt[nt-1].cant <= xs[pos].cupo){
			
			printf("El alumno %s pudo inscribirse al area %s turno %d\n",xn,xs[pos].nombre,nt);
			
		} else{
			
			printf("No se pudo inscribir el alumno, no hay vacantes\n");
		}

		printf("Ingresar el nombre del alumno,finalice con fin\n");
		scanf("%s",xn);

	}
	
	
	return;
}

void mostrar(struct salas xs[N],struct turnos xt[M]){
	
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			
			printf("Sala %d turno %d, tiene %d alumnos\n",i+1,j+1,xt[j].cant);
		}
	}
	return;
}
int main(){
	
	struct salas s[N];
	struct turnos t[M];
	
	iniciar(s,t);
	carga(s,t);
	mostrar(s,t);
	return 0;
}
