/*Parcial 3 Tema 1 Turno Ma�ana*/
/* Ejercicio 2
Una sala de cines procesa diariamente el archivo "TITULOS.DAT". Este archivo almacena la informaci�n de cada pel�cula proyectada:
C�digo de pel�cula, T�tulo, Director y Cantidad de personas que la vieron. El archivo est� ordenado en forma secuencial por c�digo 
a partir del n�mero 200.
Se pide realizar un programa �ptimo que a trav�s del uso de funciones responda a las siguientes solicitudes:
1) Ingresar un c�digo de pel�cula y modificar el director.
2) Generar una lista enlazada con punteros con los c�digos de pel�cula y t�tulo que fueron vista por m�s de 500 personas.
3) Ingresar un c�digo de pel�cula y eliminarlo de la lista.
4) Genere un nuevo archivo con la informacion de la lista. */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>
#include <conio.h>

typedef char cadena[40];
typedef struct{                //Estructura que hace referencia al archivo que se crea
	cadena tit, dire;
	int cod, cantPer;	
}cine;

struct nodo{                //Estructura que hace referencia a la lista que se crea
    int codi; 
    cadena titu;
    struct nodo * sig;
};
typedef struct nodo *puntero;

typedef struct{            //Estructura que hace referencia al segundo archivo que se crea
    int cod2;
    cadena titu2;
}cine2;

/*Esto no se hace en el ejercicio. Es s�lo para crear el archivo con el que hay que trabajar*/
void carga1(FILE *arch){                //esta funci�n sirve para generar un archivo.
    cine dato;
   	cadena titulo;
   	fpos_t x;
   	int codi;
	
	printf(" Ingrese: \n");
	fflush(stdin);
    printf(" T�tulo (termina con 'fin'): ");  
	gets(titulo);
    while (stricmp(titulo,"fin") != 0) {
    	strcpy(dato.tit,titulo);
    	fseek(arch,0,SEEK_END);  
		fgetpos(arch,&x);
		codi = (int)(x/sizeof(cine)) + 200;
		printf(" C�digo asignado para %s: %d \n",titulo,codi);
		dato.cod = codi;
        fflush(stdin);
        printf(" Director: "); gets(dato.dire);
        printf(" Cantidad de personas que la vieron: ");  
		scanf("%d", &dato.cantPer);            
        fwrite(&dato, sizeof(dato), 1, arch);
       	fflush(stdin);
    	printf("\n T�tulo (termina con 'fin'): ");  
		gets(titulo);
    }
}

/*Esto no se hace en el ejercicio. Es s�lo para crear el archivo con el que hay que trabajar*/
void mostrar1(FILE *archi){                 //esta funci�n sirve para mostrar un archivo creado.
    cine dato;
    
	rewind(archi);
    printf("\n\n      Lista : \n\n");
    printf(" C�digo    T�tulo      Director      Cant. de personas\n");
    while (fread(&dato, sizeof(dato), 1, archi)){
        printf("   %d     %s        %s           %d  \n", dato.cod, dato.tit, dato.dire, dato.cantPer);
    }
}

//1) Ingresar un c�digo de pel�cula y modificar el director.
void modificaDirector(FILE *archi){                 //esta funci�n sirve para modificar un dato en el archivo.
    cine a;
    int codi;

    printf("\n Ingrese un c�digo de pel�cula para modificar su director: ");  
    scanf("%d", &codi);
    fseek(archi,(codi-200)*sizeof(a), SEEK_SET);    //Se ubica el puntero de nuevo
    fread(&a, sizeof(a), 1, archi);
    fflush(stdin);
	printf(" Ingrese el nuevo director: "); 
	gets(a.dire);
	fseek(archi,(codi-200)*sizeof(a), SEEK_SET);    //Se ubica el puntero de nuevo
	fwrite(&a, sizeof(a), 1, archi);
}

//2) Generar una lista enlazada con punteros con los c�digos de pel�cula y t�tulo que fueron vista por m�s de 500 personas.
void cargaLista(FILE *archi, puntero &xp){        //esta funci�n sirve para cargar los datos a una lista desde el archivo.
    cine a;
    
    rewind(archi);
    while (fread(&a, sizeof(a), 1, archi)){
        if(a.cantPer > 500){
            puntero nuevo;
            nuevo = (puntero) malloc (sizeof(struct nodo));
            nuevo->codi = a.cod;
            strcpy(nuevo->titu, a.tit);
            nuevo->sig = xp;
            xp = nuevo;
        }
    }
}

//3) Ingresar un c�digo de pel�cula y eliminarlo de la lista.
void elimina(puntero &xp){                  //esta funci�n sirve para eliminar un nodo de una lista.
    puntero p, ant;
    int codigo;

	printf("\n Ingrese el c�digo de una pel�cula para eliminarlo: ");
	scanf("%d", &codigo);
    if(xp->codi == codigo){
        p = xp;
        xp = xp->sig;
        free(p);
        printf("\n Pel�cula eliminada con �xito. \n");
    } else {
        p = xp;
        ant = xp;
        while ((p != NULL) && (p->codi != codigo)){
            ant = p;
            p = p->sig;
        }
        if(p != NULL){
            ant->sig = p->sig;
            free(p);
            printf("\n Pel�cula eliminada con �xito. \n");
        } else printf("\n La pel�cula no se encontr� en la lista \n");
    }
}

//4) Genere un nuevo archivo con la informaci�n de la lista.
 void genera2(FILE *archi2, puntero &xp){  //esta funci�n sirve para copiar los datos de una lista en el archivo.
    cine2 d;
    
    while (xp != NULL){
        d.cod2 = xp->codi;
        strcpy(d.titu2,xp->titu);
        fwrite(&xp, sizeof(xp), 1, archi2);
        xp = xp->sig;
    }
}  

int main(){       //Algoritmo principal
	setlocale (LC_CTYPE, "Spanish");
    FILE *archivo1;
    FILE *archivo2;
    puntero cab = NULL;
    
    if((archivo1 = fopen("TITULOS.dat", "w+")) == NULL){
        printf(" Error al intentar abrir el archivo. ");
    } else {
    	printf("\n A continuaci�n se crea el archivo TITULOS.dat: \n");
    	carga1(archivo1);  
		mostrar1(archivo1);  	
        modificaDirector(archivo1);
        cargaLista(archivo1,cab);
        elimina(cab);
    }
    fclose(archivo1);
    
    if((archivo2 = fopen("TITULOS2.dat", "w+")) == NULL){
        printf("Error al intentar abrir el archivo.");
    }
    else{
        genera2(archivo2,cab);
    }
    fclose(archivo2);
    
    printf("\n\n FIN DEL PROGRAMA \n\n");
    getch();
}

/*C�digo de pel�cula(a partir del 100)   T�tulo    Director    Cantidad de personas que la vieron
peli1
dire1
900
peli2
dire2
450
peli3
dire3
800
peli4
dire4
990
fin
201
DIRE2
203
*/
