//Ejemplo de eliminar datos de un archivo

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

typedef char cadena[20];
typedef struct {
	char nombre[30];
	int cuenta;
} cliente;

/*Esto no se hace en el ejercicio. Es sólo para crear el archivo con el que hay que trabajar*/
void carga1(FILE *arch){                //esta función sirve para generar un archivo.
    cliente dato;
   	cadena nomb;
	
	printf(" Ingrese: \n");
	fflush(stdin);
    printf(" Nombre del cliente (termina con 'fin'): ");  
	gets(nomb);
    while (stricmp(nomb,"fin") != 0) {
    	strcpy(dato.nombre,nomb);
        printf(" N° de cuenta: ");  
		scanf("%d", &dato.cuenta);            
        fwrite(&dato, sizeof(dato), 1, arch);
       	fflush(stdin);
    	printf("\n Nombre del cliente (termina con 'fin'): ");  
		gets(nomb);
    }
}

/*Esto no se hace en el ejercicio. Es sólo para crear el archivo con el que hay que trabajar*/
void mostrar1(FILE *archi){                 //esta función sirve para mostrar un archivo creado.
    cliente dato;
    
	rewind(archi);
    printf("\n\n      Lista : \n\n");
    printf(" N° DE CUENTA     NOMBRE DEL CLIENTE \n");
    while (fread(&dato, sizeof(dato), 1, archi)){
        printf("     %d            %s        \n", dato.cuenta, dato.nombre);
    }
}

void marcar(FILE *xarchi){
	cliente c;   
	int nro,b;
	
  	printf("\n Ingrese un número de cuenta a eliminar: "); 
  	scanf("%d",&nro);
	while (nro!=0) {
  		b = 0;
	    fseek(xarchi, 0, SEEK_SET);
	    while((b == 0) && fread(&c,sizeof(c),1,xarchi))
        	if(nro==c.cuenta) 
        		b=1;
			if (b == 1){
		    	fseek(xarchi,-sizeof(c),SEEK_CUR);
            	c.cuenta = -1;
            	fwrite(&c,sizeof(c),1,xarchi);    
            	printf(" Cliente: %s  fue marcado para borrarse \n",c.nombre);
  	    	} else  printf("\n La cuenta no existe");
        printf("\n Ingrese un número de cuenta a eliminar: ");      
        scanf("%d",&nro);
    }
}

void compactar(FILE *xarchi,FILE *xauxi){
  	cliente c;
  	rewind(xarchi);
  	fseek(xarchi, 0, SEEK_SET);
  
  	while(fread(&c,sizeof(c),1,xarchi)){
	    if (c.cuenta != -1) {
	    	fwrite(&c,sizeof(c),1,xauxi);
		} 
	}
}
	
int main() {
	setlocale (LC_CTYPE, "Spanish");
	FILE *archi, *auxi;
	
	if ((archi = fopen("clientes.txt","w+")) == NULL){
		printf("Error.") ;
	} else {
		carga1(archi);
		mostrar1(archi);
        marcar(archi); 
        auxi = fopen("auxiliar.txt","w+");
        compactar(archi,auxi); 
        fclose(archi);
		mostrar1(auxi); 
		fclose(auxi);
        remove("clientes.txt"); 
        rename("auxiliar.txt","clientes.txt"); 
    }
    printf("\n\n FIN DEL PROGRAMA \n\n");
    getch();
}

/*
cliente1
1523
cliente2
1524
cliente3
1525
cliente4
1526
cliente5
1527
cliente6
1528
fin
1524
1528
1523
*/
