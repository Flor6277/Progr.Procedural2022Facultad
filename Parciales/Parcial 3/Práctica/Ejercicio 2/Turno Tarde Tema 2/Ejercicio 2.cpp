/*Parcial 3 Tema 2 Turno Tarde*/
/* Ejercicio 2
Un banco procesa el archivo "TAJETAS.DAT" con la informaci�n de las tarjetas de cr�dito otorgadas a sus clientes. De cada
tarjeta ha registrado: n�mero de tarjeta, nombre de cliente y cupo. El archivo est� ordenado secuencialmente por c�digo
del n�mero 1000.
Se pide realizar un programa �ptimo que a trav�s del uso de funciones responda a las siguientes solicitudes:
1) Agregar la informaci�n de una nueva tarjeta otorgada.
2) Generar una lista enlazada con punteros con los n�meros de tarjetas y nombre de cliente cuyo cupo es menor a $500.000
3) Ingresar un n�mero de tarjeta y modificar el nombre del cliente en la lista generada.
4) Genere un nuevo archivo con la informacion de la lista. */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>

typedef char cadena[40];
typedef struct{                //Estructura que hace referencia al archivo que se crea
	cadena nomb;
	int cod;
	float cupo;	
}cliente;

struct nodo{    
	int codi;          //Estructura que hace referencia a la lista que se crea
    cadena nombre;
    struct nodo * sig;
};
typedef struct nodo *puntero;

typedef struct{    
	int cod2;        //Estructura que hace referencia al segundo archivo que se crea
    cadena nombre2;
}cliente2;

/*Esto no se hace en el ejercicio. Es s�lo para crear el archivo con el que hay que trabajar*/
void carga1(FILE *arch){                //esta funci�n sirve para generar un archivo.
    cliente dato;
   	cadena cliente;
   	fpos_t x;
   	int codi;
	
	printf(" Ingrese: \n");
	fflush(stdin);
    printf(" Nombre del cliente: ");  
	gets(cliente);
    while (stricmp(cliente,"fin") != 0) {
    	strcpy(dato.nomb,cliente);
    	fseek(arch,0,SEEK_END);  
		fgetpos(arch,&x);
		codi = (int)(x/sizeof(cliente)) + 1000;
		printf(" C�digo asignado para %s: %d \n",cliente,codi);
		dato.cod = codi;
        printf(" Cupo: ");  
		scanf("%f", &dato.cupo);            
        fwrite(&dato, sizeof(dato), 1, arch);
       	fflush(stdin);
   		printf("\n Nombre del cliente (termina con 'fin'): ");  
		gets(cliente);
    }
}

/*Esto no se hace en el ejercicio. Es s�lo para crear el archivo con el que hay que trabajar*/
void mostrar1(FILE *archi){                 //esta funci�n sirve para mostrar un archivo creado.
    cliente dato;
    
	rewind(archi);
    printf("\n\n      Lista : \n\n");
    printf(" C�digo     Cliente      Cupo ($)\n");
    while (fread(&dato, sizeof(dato), 1, archi)){
        printf("  %d      %s    %.2f  \n", dato.cod, dato.nomb, dato.cupo);
    }
}

//1) Agregar la informaci�n de una nueva tarjeta otorgada.
void agrega(FILE *archi){                 //esta funci�n sirve para agregar un dato a un archivo.
    cliente a;
    fpos_t x;
    fseek(archi, 0, SEEK_END);
    fgetpos(archi, &x);
    
    printf("\n Ingrese: \n");
    fflush(stdin);
    printf(" Cliente: ");  
    gets(a.nomb);
	a.cod = (int)(x/sizeof(a) + 1000);
    printf(" C�digo nuevo asignado a la tarjeta: %d \n", a.cod);
    printf(" Cupo: ");  
    scanf("%f", &a.cupo);
    fwrite(&a, sizeof(a), 1, archi);
}

//2) Generar una lista enlazada con punteros con los n�meros de tarjetas y nombre de cliente cuyo cupo es menor a $500.000
void cargaLista(FILE *archi, puntero &xp){        //esta funci�n sirve para cargar los datos a una lista desde el archivo.
    cliente a;
    
    rewind(archi);
    while (fread(&a, sizeof(a), 1, archi)){
        if(a.cupo < 500000){
            puntero nuevo;
            nuevo = (puntero) malloc (sizeof(struct nodo));
            strcpy(nuevo->nombre, a.nomb);
            nuevo->codi = a.cod;
            nuevo->sig = xp;
            xp = nuevo;
        }
    }
}

//3) Ingresar un n�mero de tarjeta y modificar el nombre del cliente en la lista generada.
void modificaCliente(puntero xp, int codi){              //esta funci�n sirve para modificar un dato en la lista.	

    if (xp != NULL){
    	if(codi == xp->codi){
    		fflush(stdin);
			printf(" Ingrese el nuevo nombre: "); 
			gets(xp->nombre);
			xp = xp->sig;
		} else modificaCliente(xp->sig,codi);
	} else printf(" El n�mero de tarjeta ingresado no existe. \n");
}

//4) Genere un nuevo archivo con la informaci�n de la lista.
 void genera2(FILE *archi2, puntero &xp){  //esta funci�n sirve para copiar los datos de una lista en el archivo.
    cliente2 d;
    
    while (xp != NULL){
        d.cod2 = xp->codi;
        strcpy(d.nombre2,xp->nombre);
        fwrite(&xp, sizeof(xp), 1, archi2);
        xp = xp->sig;
    }
}  

int main(){       //Algoritmo principal
	setlocale (LC_CTYPE, "Spanish");
    FILE *archivo1;
    FILE *archivo2;
    puntero cab = NULL;
    int codi;
    
    if((archivo1 = fopen("TAJETAS.dat", "w+")) == NULL){
        printf(" Error al intentar abrir el archivo. ");
    } else {
    	printf("\n A continuaci�n se crea el archivo TITULOS.dat: \n");
    	carga1(archivo1);  
		mostrar1(archivo1);  	
        agrega(archivo1);
        cargaLista(archivo1,cab);
        printf("\n Ingrese un n�mero de tarjeta para modificar el nombre del cliente: ");  
    	scanf("%d", &codi);
        modificaCliente(cab,codi);
    }
    fclose(archivo1);
    
    if((archivo2 = fopen("TAJETAS2.dat", "w+")) == NULL){
        printf("Error al intentar abrir el archivo.");
    } else {
        genera2(archivo2,cab);
    }
    fclose(archivo2);
    
    printf("\n\n FIN DEL PROGRAMA \n\n");
    getch();
}

/*Nombre(a partir del 1000)   Cupo   
cliente1
90000
cliente2
450000
cliente3
8000
cliente4
99000
fin
cliente5
90000
1003
CLIENTE4
*/
