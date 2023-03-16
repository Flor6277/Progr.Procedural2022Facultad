/*Parcial 3 Tema 2 Turno Mañana*/
/* Ejercicio 1 
Se tiene un archivo "DATOS.DAT" con la informacion del caudal de agua de 5 rios. De cada rio se tiene registrado: 
caudal de agua, codigo de rio (1...5),número de mes en que se hizo la medición (1...12).
Se pide que usando funciones para cada item, resuelva lo siguiente:
1) Ingresar un código de mes y mostrar los códigos de rio que se midieron en esa fecha.
2) Generar un arreglo dinámico con el código de rio y caudal para aquellos rios medidos entre los meses 6 y 12.
3) Usando el arreglo generado, indicar cuantos rios tuvieron un caudal menor a 3 mm cúbicos, hacer una funcion 
recursiva que devuelva este resultado.
4) Eliminar el arreglo generado. */

#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>

typedef struct {
	float caudal;
	int cod,mes;	
}rio;

typedef struct{
	int codigo;
	float caud;
}arr;

/*Item a  Ingresar un codigo de mes y mostrar los códigos de rio que se midieron en esa fecha.*/
void mostrar(FILE *archi){
	rio dato;
	int codigo;
	
	printf(" Ingrese un mes (1..12) para saber que rios tuvo registros ahí: ");
	scanf("%d",&codigo);
	rewind(archi);
	while (fread(&dato,sizeof(dato),1,archi) != 0) {
		if (codigo == dato.mes) {
			printf(" Código: %d \n",dato.cod);
		}
	}
}

void recorre(FILE *archi, int &comp){
	rio dato;
	rewind(archi);
	
	while (fread(&dato,sizeof(dato),1,archi)){
		if ((dato.mes>= 6) && (dato.mes <= 12)){
			comp++;
		}
	}
}

/*Item b Generar un arreglo dinámico con el código de rio y caudal para aquellos rios medidos entre los meses 6 y 12*/
void cargaArregloD(FILE *archi,arr *a, int &co){
	rio dato;
	int i = 0;
	
	rewind(archi);
	fread(&dato,sizeof(dato),1,archi);
	while(i<co){
		if ((dato.mes >= 6) && (dato.mes <= 12)){
			a[i].codigo = dato.cod;
			a[i].caud = dato.caudal;
		}
		i++;
		fread(&dato,sizeof(dato),1,archi);
	}
	
}

// Sólo se usa para mostrar el arreglo generado
void muestra1(arr *a, int &xc){
	
	printf("\n\n Arreglo generado: \n");
	printf(" Código -  Caudal \n");
	for(int i=0; i<xc; i++){
		printf("   %d        %.1f \n", a[i].codigo, a[i].caud);
	}
}


/*Item c  Usando el arreglo generado, indicar cuantos rios tuvieron un caudal menor a 3 m cubicos, hacer una funcion 
recursiva que devuelva este resultado.  */
void contar3(arr *a, int &xc, int &cont,int i){
	
	if (i < xc) {
		if(a[i].caud < 3){
			cont++;
		}
		contar3(a,xc,cont,i+1);
	} else return;
}


/*Item d  Eliminar el arreglo generado.  */
void eliminarArreglo(arr *a,int &c){
	
	for(int i = 0; i<c; i++){
		free(a);
	}
}


/* Algoritmo principal*/
int main(){	
	setlocale (LC_CTYPE, "Spanish");						
	FILE *archivo;
	arr *a;
	int cant = 0,cont = 0;
	
	if ((archivo = fopen("DATOS.dat","r")) == NULL){
		printf("\n Error al intentar abrir el archivo \n");
	} else {
		mostrar(archivo);
		recorre(archivo,cant);
		a = (arr*) malloc (sizeof(arr)*cant);
		printf("\n Memoria asignada al arreglo dinámico. \n");
		cargaArregloD(archivo,a,cant);
		muestra1(a,cant);
		contar3(a,cant,cont,0);
		printf("\n\n Cantidad de rios con caudal menor a 3 mm3: %d \n",cont);
		eliminarArreglo(a,cont);	
	}
	fclose(archivo);
	printf("\n\n fin del programa \n");
	getch();
}
