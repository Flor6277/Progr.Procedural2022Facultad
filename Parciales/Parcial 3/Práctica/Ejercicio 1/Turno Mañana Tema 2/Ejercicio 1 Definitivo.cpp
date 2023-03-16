/*Parcial 3 Turno Mañana Tema 2*/
/*Ejercicio 1
Se tiene un archivo "DATOS.DAT" con la informacion del caudal de agua de 5 rios. De cada rio se tiene registrado: 
caudal de agua, codigo de rio (1...5),número de mes en que se hizo la medición (1...12).
Se pide que usando funciones para cada item, resuelva lo siguiente:
1) Ingresar un código de mes y mostrar los códigos de rio que se midieron en esa fecha.
2) Generar un arreglo dinámico con el código de rio y caudal para aquellos rios medidos entre los meses 6 y 12.
3) Usando el arreglo generado, indicar cuantos rios tuvieron un caudal menor a 3 mm cúbicos, hacer una funcion 
recursiva que devuelva este resultado.
4) Eliminar el arreglo generado. 
*/
#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>

typedef struct{   //Estructura que hace referencia al archivo que se crea
    int caud, cod, mes;
}dato;

struct rios{  //Estructura que hace referencia al arreglo dinámico
    int cod, cau;
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

/*1) Ingresar un código de mes y mostrar los códigos de rio que se midieron en esa fecha.*/
void mostrar(FILE *ar){
    dato a;
    int codi;
    
    rewind(ar);
    printf("\n\n Ingrese un código de mes para saber los rios que se midieron en ese mes: ");
    scanf("%d", &codi);
    while (fread(&a, sizeof(a), 1, ar)){
        if(a.mes == codi){
            printf("       %d \n", a.cod);
        }
    }
}

//Recorre para asignar memoria
void cuenta(FILE *ar, int &cant){
    dato a;
    rewind(ar);
    
    while (fread(&a, sizeof(a), 1, ar)){
        if(a.mes >= 6 && a.mes <= 12){
            cant++;
        }
    }
}

/*2) Generar un arreglo dinámico con el código de rio y caudal para aquellos rios medidos entre los meses 6 y 12.*/
void genera(FILE *archi, rio *arr, int cant){
    int i;
    dato a;
    
    rewind(archi);
    fread(&arr, sizeof(arr), 1, archi);
    while (i < cant){
        if ((a.mes >= 6) && (a.mes <= 12)){
            arr[i].cod = a.cod;
            arr[i].cau = a.caud;
        }
        i++;
        fread(&arr, sizeof(arr), 1, archi);
    }    
} 

/*3) Usando el arreglo generado, indicar cuantos rios tuvieron un caudal menor a 3 mm cúbicos, hacer una funcion 
recursiva que devuelva este resultado.*/
void indica(rio *arr, int cant, int &c, int i){
    if(i<cant){
        if(arr[i].cau < 3){
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
        indica(arreglo, cant, cantidadRios, 0);
        printf("\n\nCantidad de rios que tuvieron caudal menor a 3mm cubicos: %d \n", cantidadRios);
        free(arreglo);  //4) Eliminar el arreglo generado.
    }
    fclose(archi);
    printf("\n\n FIN DEL PROGRAMA \n\n");
    getch();
}

/*
rio  mes   caudal
5
6
2
2
1
5
1
9
2
2
5
3
4
9
2
5
9
2
0
9
*/
