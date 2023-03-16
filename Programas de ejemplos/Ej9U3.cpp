/* Ejercicio 9
Una empresa de seguros procesa la información de las ventas que han realizado sus 10 promotores. De cada uno de
los 10 promotores se conoce el código de sector donde trabaja (número entre 30 y 37) codificado: 30: Moto - 31:
Auto - 32: Camioneta - 33: Camión - 34: Ómnibus de Corta distancia - 35: Ómnibus de larga distancia - 36: Combis de
pasajeros - 37: taxis.
De cada seguro (son 3 tipos de seguros distintos) se conoce el tipo (una letra entre “A” y
“C”), el nombre y su precio. Los tipos de seguro se codifican: “A”: Seguro contra terceros, “B”: Seguro de Incendio y
“C”: Seguro Total.
Nota: Leer la información que se pide, y de acuerdo a eso, ¿Qué estructura es la más adecuada para el
almacenamiento de los datos?
Se pide realizar un programa que permita (utilizando Menú de opciones):
a) Ingresar las ventas de seguros realizadas. Por cada venta se ingresa número de promotor (de 1...10) y tipo de
seguro(“A”…“C”). Las ventas no traen ningún orden específico y termina el ingreso con número de promotor
igual a 0.
b) Ingresar un tipo de seguro e indicar en qué sector se lo vende más y cuantos promotores tiene ese sector.
c) Dado un número de sector, indicar cuál es el seguro que más se consume.
d) Indicar para cada tipo de seguro, el nombre y el importe total de venta. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define P 10
#define S 3

const char tipos[3] = {'A', 'B', 'C'};
const char tiposM[3] = {'a', 'b', 'c'};
const char nomT[3][50] = {"Seguro contra terceros", "Seguro de Incendio", "Seguro Total"};

typedef struct Seg
{
    int cantp;
    int cods;
    float precio;
}seg;

int ind (char a) {
    for (int i=0; i<S; i++){
        if (a == tipos[i]){
         return i;
        } else if (a == tiposM[i]){
        	return i;
		}
    }
    return (-5);
}

void cerear(seg a[S][P], int &i, int &j){
    if (j==P){j=0; i+=1; cerear(a, i, j);}
    if (i==S){return;}
    a[i][j].cantp=0;
    a[i][j].cods=0;
    j+=1;
    cerear(a, i, j);
}

void precarga(seg a[S][P], int &i, int &j){
    float aux;
    int aux1;
    for(i=0; i<S; i++){
       printf("Ingrese el Importe del seguro %c \n", tipos[i]);
       scanf("%f", &aux);
       for (j=0; j<P ; j++)
       { 
        a[i][j].precio = aux;
       }
    }

    for(j=0; j<P; j++){
       printf("Ingrese el numero de sector del promotor %d \n", j+1);
       scanf("%d", &aux1);
       for (i=0; i<S; i++)
       {
       a[i][j].cods= aux1;
       }
    }
}

void mostrar (seg a[S][P], int &i, int &j){
	printf("\n");
	for (i=0;i<S;i++){
   	printf("%s\n", nomT[i]);
    for (j=0;j<P;j++)
    {
    printf("El importe es %2.f y el sector %d, con la cantidad de %d \n", a[i][j].precio, a[i][j].cods, a[i][j].cantp);
    
    }
   printf("\n");
   }
}


void carga (seg a[S][P], int x){
    int cant;
    char aux1;
    fflush(stdin);
        printf("Ingrese el tipo del sector \n");
        scanf("%c", &aux1);
    fflush(stdin);
        printf("Ingrese la cantidad vendida \n");
        scanf("%d", &cant);
        a[ind(aux1)][x].cantp+=cant;
}

void indicar(seg a[S][P], int x){
    int max= 0, aux, count=0;
  for (int i = 0; i<P; i++){
    if (a[x][i].cantp > max){
      aux = a[x][i].cods;
      max = a[x][i].cantp;
    }
  }
  for (int j=0; j<P; j++){
     if (aux == a[x][j].cods){
        count +=1;
     }
  }
  if (max != 0){
  
  printf("El sector mas vendido es %d y la cantidad promotores de ese sector es %d \n", aux, count);
  } else {
  	printf("No se encontro un sector que haya presentado mas ventas de seguros \n");
  }
}

 int  Buscar (seg a[S][P], int b[S]){
    int sector, acum=0;
    printf("Numero de sector  \n");  
    scanf("%d", &sector);
    for(int j=0; j<S; j++){            
      for(int i =0; i<P; i++){          
        if(sector == a[j][i].cods){    
           acum += a[j][i].cantp;      
        }
     }
     b[j] = acum;
     acum =0;
   }
  return (sector);
}

void  Mostrar1 (int b[S], int &s){
       int max= 0, aux;
  for (int i = 0; i<S; i++){
    if (b[i] > max){
      aux = i;
      max = b[i];
    }
  }
  printf("El seguro que mas se consume es el tipo: %c con %d vendidos en el sector %d", tipos[aux], b[aux], s);
  printf("\n");
}

void  IndicarT (seg a[S][P], int &i, int &j){
    int acum = 0;
    printf("\n");
    printf("\n");
    for(i=0; i<S; i++){
        for(j=0; j<P; j++){
            acum += a[i][j].cantp;
        }
        printf("Para el tipo de seguro %c, tiene el nombre: %s, con un importe total vendido %.2f \n", tipos[i], nomT[i], (acum*a[i][0].precio));
        acum = 0;
    }
}

int main()
{
	seg a[S][P];
    int i=0, j=0, nump, b[S], aux, control;
    char sec;
    i=0; j=0;
    cerear(a, i, j);
    fflush(stdin);
    i=0; j=0;
    for (i = 0; i<S; i++){
        b[i] = 0;
    }
    precarga(a, i, j);
	
	fflush(stdin);
	printf("\n");
	printf("\n");
    printf("Seleccione la accion: \n");
    printf("1 Para cargar \n");
    printf("2 Para Mostrar el arreglo \n");
    printf("3 Para indicar el sector que pose mas ventas \n");
    printf("4 Para el seguro mas consumido \n");
    printf("5 Para indicar para cada seguro sus importe total \n");
    printf("6 Para Resetear y Precargar \n");
    scanf("%d", &control);
    do
    {
    	switch(control)
    	{
    		case 1:
    			printf("\n");
    			printf("\n");
    			fflush(stdin);
    			printf("Ingrese el numero del promotor \n");
    			scanf("%d", &nump);
    				do
    				{   
        				switch (nump)
        				{
       						 case 1:
            					carga(a, 0);
            					break;
       						 case 2:
           						carga(a, 1);
            					break;
       						 case 3:
            					carga(a, 2);
            					break;
        					case 4:
           						 carga(a, 3);
           						 break;
        					case 5:
            					carga(a, 4);
            					break;
        					case 6:
            					carga(a, 5);
           					    break; 
        					case 7:
           						carga(a, 6);
            					break;   
        					case 8:
            					carga(a, 7);
            					break;    
        					case 9:
            					carga(a, 8);
           						break;    
        					case 10:
            					carga(a, 9);
           						break;    
        					default: 
             					printf("El numero del promotor no se encuentra\n");
            					break;
        					} 
    					printf("Ingrese el numero del promotor o termine con 0\n");
    					scanf("%d", &nump);
    				} while (nump != 0);
    			printf("\n");
    			break;
        
        	case 2:
        		mostrar(a, i, j);
    			printf("\n");
       			break;
             
            case 3: 
				fflush(stdin);
				printf("\n");
	            printf("\n");
    			printf("Tipo de sector (A, B , C) \n");
    			scanf("%c", &sec);
    				do
   					{   
        				switch (sec)
        				{
       						 case 'a':
            					indicar(a, 0);
            					break;
       						 case 'A':
            					indicar(a, 0);
            					break;  
      						 case 'b':
            					indicar(a, 1);
           						break; 
        					 case 'B':
           						 indicar(a, 1);
            					 break; 
       						 case 'c':
           						 indicar(a, 2);
           						 break;
        					 case 'C':
           						 indicar(a, 2);
           						 break;                 
        					 default: 
             					 printf("El tipo del ingresado no se encuentra \n");
           						 break;
       					 } 
    					 fflush(stdin);
    					 printf("Tipo de sector (A, B , C) o termine con 1\n");
    					 scanf("%c", &sec);
    				} while (sec != '1');
            	break;
            	
            	case 4:
            		 printf("\n");
    				 printf("\n");
    				 aux = Buscar(a, b);
    				 Mostrar1(b, aux);
            		break;
            		
                case 5:
                	IndicarT(a, i, j);
                	break;
                	
                case 6:
                	 i=0; j=0;
    				 cerear(a, i, j);
    				 fflush(stdin);
    				 i=0; j=0;
    				 for (i = 0; i<S; i++){
        				b[i] = 0;
    				 }
    				 precarga(a, i, j);
		}
		fflush(stdin);
		printf("\n");
	    printf("\n");
   		printf("Seleccione la accion: \n");
    	printf("1 Para cargar \n");
    	printf("2 Para Mostrar el arreglo \n");
    	printf("3 Para indicar el sector que pose mas ventas \n");
    	printf("4 Para el seguro mas consumido \n");
    	printf("5 Para indicar para cada seguro sus importe total \n");
    	printf("6 Para Resetear y Precargar \n");
    	printf("0 Para finalizar el programa \n");
    	scanf("%d", &control);
	}while (control != 0);
	printf("\n");
	printf("\n");
	printf(" Alumnos: Eduardo Guaquinchai \n");
	printf("          Matias Aguero \n");
	printf("\n");
	printf("Programa Finalizado \n");
    return 0;
}
