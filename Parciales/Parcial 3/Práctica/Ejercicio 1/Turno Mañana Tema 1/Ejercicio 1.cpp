/*Parcial 3 Turno Mañana Tema 1*/
/*Ejercicio 1
Se tiene un archivo "DATOS.DAT" con la informacion del caudal de agua de 5 rios. De cada rio se tiene registrado: 
caudal de agua, codigo de rio (1...5),número de mes en que se hizo la medición (1...12).
Se pide que usando funciones para cada item, resuelva lo siguiente:
1) Ingresar un código de mes y mostrar en que mes se hizo medición.
2) Generar un arreglo dinámico con el código de rio y número de mes para aquellos ríos con un caudal mayor a 10m3.
3) Usando el arreglo generado, indicar cuantos ríos fueron medidos en el mes 3. Hacer una función recursiva que devuelva
este resultado.
4) Eliminar el arreglo generado. */
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>

typedef struct{   //Estructura que hace referencia al archivo que se crea
    int caud, cod, mes;
}dato;

struct rios{     //Estructura que hace referencia al arreglo dinámico
    int codigo, mesA;
};
typedef struct rios rio; 

/*Esto no se hace en el ejercicio. Es sólo para crear el archivo con el que hay que trabajar*/
void carga(FILE *arch){
    dato a;
    int codi;

	printf(" Ingrese: \n");
	printf(" Código de rio (termina con '0'): "); scanf("%d", &codi);
    while (codi != 0) {
        a.cod = codi;
        printf(" Mes: "); scanf("%d", &a.mes);
        printf(" Caudal : ");  scanf("%d", &a.caud);
        fwrite(&a, sizeof(a), 1, arch);
        printf("\n Código de rio (termina con '0'): "); scanf("%d", &codi);
    }
}

/*Esto no se hace en el ejercicio. Es sólo para crear el archivo con el que hay que trabajar*/
void mostrar1(FILE *arch){
    dato a;
    
	rewind(arch);
    printf("\n\n   Lista creada: \n\n");
    printf(" Caudal    Río   Mes\n");
    while (fread(&a, sizeof(a), 1, arch)){
        printf("   %d        %d     %d \n", a.caud, a.cod, a.mes);
    }

}

/*1) Ingresar un código de río y mostrar en que mes se hizo medición.*/
void mostrar(FILE *ar){
    dato a;
    int mes;
    
    rewind(ar);
    printf("\n\n Ingrese un código de río para saber en que mes se midió: ");
    scanf("%d", &mes);
    while (fread(&a, sizeof(a), 1, ar)){
        if(a.cod == mes){
            printf("\n      %d \n", a.mes);
        }
    }
}

//Recorre para asignar memoria
void cuenta(FILE *ar, int &cant){
    dato a;
    rewind(ar);
    
    while (fread(&a, sizeof(a), 1, ar)){
        if(a.caud > 10){
            cant++;
        }
    }
}

/*2) Generar un arreglo dinámico con el código de río y número de mes para aquellos ríos con un caudal mayor a 10m3.*/
void genera(FILE *archi, rios *ar, int cant){
    int i;
    dato a;
    
    rewind(archi);
    fread(&ar, sizeof(ar), 1, archi);
    while (i < cant){
        if (a.caud > 10){
            ar[i].codigo = a.cod;
            ar[i].mesA = a.mes;
        }
        i++;
        fread(&ar, sizeof(ar), 1, archi);
    }    
} 

void mostrar2(rio *ar,int cant){
    int i = 0;
    
    printf("\n Arreglo generado: \n");
    while (i < cant){
        printf(" %d  %d \n",ar[i].codigo, ar[i].mesA);
        i++;
    }    
}


/*3) Usando el arreglo generado, indicar cuantos ríos fueron medidos en el mes 3. Hacer una función recursiva que devuelva
este resultado.*/
void indica(rio *arr, int cant, int &c, int i){
	
    if(i<cant){
        if(arr[i].mesA == 3){
            c++;
        }
    	indica(arr, cant, c, i+1);
    }
}

int main(){
	setlocale (LC_CTYPE , "Spanish");
    FILE *archi;
    
    if((archi = fopen("DATOS.dat", "w+")) == NULL){
        printf("Error al intentar abrir el archivo. \n");
    }
    else{
        int cant = 0, cantidadRios = 0;
        rio *arreglo;
        carga(archi);
    	mostrar1(archi);
        mostrar(archi);
        cuenta(archi, cant);
        arreglo = (rio*) malloc (sizeof(struct rios)*cant);
        genera(archi, arreglo, cant);
        mostrar2(arreglo, cant);
        indica(arreglo, cant, cantidadRios, 0);
        printf("\n\n Cantidad de rios que fueron medidos en el mes 3: %d \n", cantidadRios);
        free(arreglo);  //4) Eliminar el arreglo generado.
    }
    fclose(archi);
    printf("\n\n FIN DEL PROGRAMA \n\n");
    getch();
}

/*
rio  mes   caudal
3
3
15
2
1
16
1
3
12
2
3
3
4
9
2
5
3
2
0
*/
