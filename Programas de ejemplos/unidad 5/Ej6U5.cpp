#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct nodo{
	char *nom;
	char *nomc;
	char *reino;
	int cant;
	struct nodo *sig;
}; typedef struct nodo *puntero;

struct pais{
	char *Npais;
	char *Continente;
    puntero s;
};

void carga (pais *d, int j){
	char b[30], a[30];
	int l;
	fflush(stdin);
	for(int i=0; i<j; i++){
		d[i].s = NULL;
		printf("Ingrese nombre del pais: %d \n", i+1);
		gets(b);
		fflush(stdin);
		l = strlen(b);
		d[i].Npais = (char*) malloc(sizeof(char)*l);
		strcpy(d[i].Npais, strupr(b));
		printf("Ingrese el continente para el pais: %s \n", d[i].Npais);
		gets(b);
		fflush(stdin);
	
		l = strlen(b);
		d[i].Continente = (char*) malloc(sizeof(char)*l);
		strcpy(d[i].Continente, strupr(b));
   }
   	system("cls");
}

void recorre (puntero &b, puntero k, puntero a){
 if (k != NULL){
  	a = k;
    k = k->sig;
    return recorre (b,k,a);
  }
  a->sig = b;
  b->sig = NULL;
}

int encontrar (puntero p, int i, char b[30], int e){
	if(p != NULL){
		if (strcmp(p->nom,strupr(b)) != 0){
			e = 0;
		} else {
			return (e + 1);
		}
	      p = p->sig;
		return encontrar(p,i,b,e);
	}	 
}

void insertar (pais *d, int j){
	puntero nuevo, p, k, anterior;
	int l, ban=0, e = 0;
	char b[30];
		for(int i=0; i<j; i++){
		fflush(stdin);
        printf("Ingrese el nombre de la especie para el pais %s \n", d[i].Npais);
        gets(b);
        fflush(stdin);
		while(strcmp(strupr(b),"FIN") != 0){
			fflush(stdin);
			p = d[i].s;
        	e = encontrar(p,i,b, e);
			if (e == 0 ){
			nuevo = (puntero) malloc (sizeof(struct nodo));
        	l = strlen(b);
        	nuevo->nom = (char*) malloc (l*sizeof(char));
        	strcpy(nuevo->nom, strupr(b));
        	fflush(stdin);
        	printf("Ingrese el nombre cientico de la especie para el pais %s \n", d[i].Npais);
         	gets(b);
        	fflush(stdin);
        	l = strlen(b);	
			nuevo->nomc = (char*) malloc (l*sizeof(char));
        	strcpy(nuevo->nomc,strupr(b));
        	fflush(stdin);
        	printf("Ingrese el reino de la especie para el pais %s \n", d[i].Npais);
        	gets(b);
            fflush(stdin);
            ban=0;
				while (ban == 0){
           			 if (strcmp(strupr(b),"FAUNA") == 0 || strcmp(strupr(b),"ANIMAL") == 0 || strcmp(strupr(b),"VEGETAL") == 0 || strcmp(strupr(b),"FLORA") == 0){
						ban = 1;
        				l = strlen(b);
						nuevo->reino = (char*) malloc (l*sizeof(char));
        				strcpy(nuevo->reino,strupr(b));
        				fflush(stdin);	
					 } else {
						printf("El reino de la especie ingresado no corresponde a los adecuados \n");
						printf("Ingrese el reino de la especie para el pais %s \n", d[i].Npais);
        				gets(b);
            			fflush(stdin);	
					}
				}
        	printf("Ingrese la cantidad de la especie para el pais %s \n", d[i].Npais);
        	scanf("%d", &nuevo->cant);
        		if (d[i].s == NULL){
        			nuevo->sig = NULL;
        			d[i].s = nuevo;
				} else if (d[i].s != NULL) {
					k = d[i].s;
		        	recorre(nuevo, k, anterior);
				}
	    	fflush(stdin);
			printf("Ingrese el nombre del animal para el pais %s o termine con fin \n",  d[i].Npais);
        	gets(b);
        	fflush(stdin);
		    } else {
		    	fflush(stdin);
				printf("El nombre de la especie: %s, para el pais: %s,  ya fue registrado \n",b ,d[i].Npais);
				printf("Ingrese el nombre del animal para el pais %s o termine con fin \n",  d[i].Npais);
       		 	gets(b);
        		fflush(stdin);
			}
		}	
		system("cls");
	}
}

void mostrar (pais *d, int j, puntero p){
		for(int i=0; i<j; i++){
			p = d[i].s;
			printf("Pais: %s \n", d[i].Npais);
			printf("Continente: %s \n", d[i].Continente);
			printf("\n");
			printf("\n");
			while (p != NULL){
				printf("Nom especie: %s \n", p->nom);
				printf("Nom especifico: %s \n", p->nomc);
				printf("Reino: %s \n", p->reino);
				printf("Cantida: %d \n", p->cant);
				p = p->sig;
			}
	     	Sleep(3000);
			system("cls");
		}
}

int calculo (puntero n, int &c, int cf){
	if (n != NULL) {
		if (strcmp(n->reino, "FLORA") == 0 || strcmp(n->reino, "VEGETAL") == 0) {
		cf = cf + n->cant;
		} else {
		c = c + n->cant;
		}
	n = n->sig;
	calculo (n,c,cf);
    } else {
	return (cf);
	}  
}

void incrementa (puntero n){
	if (n != NULL){
			if (strcmp(n->nom, "PETIRIBI") == 0){
			  n->cant =  n->cant + 200;	
			}
	n = n->sig;
	incrementa(n);
	}
}

void indicar (puntero n, int &count){
	if (n != NULL){
		if (strcmp(n->nom, "PETIRIBI") == 0){
			  count =  n->cant + count;	
			}
	n = n->sig;
	indicar(n, count);
	}
	return ;
}

int main (){
	pais *p;
	puntero n;
	char b[15];
	int cf=0, cfa=0, d, ban = 0;
	printf("Ingrese la cantidad de paises \n");
	scanf("%d", &d);
	p = (pais*) malloc(sizeof(struct pais)*d);
	carga(p, d);
	insertar(p, d);
	mostrar(p, d, n);
	printf("Ingrese el nombre del pais \n");
	gets(b);
	fflush(stdin);
	while(strcmp(strupr(b),"FIN")){
		ban = 0;
	 	cf=0; cfa=0;
		for(int i=0; i<d; i++){
			if(strcmp(strupr(b),p[i].Npais)==0){
				n = p[i].s;
				cfa = calculo(n,cf,cfa);
				printf("La cantidad de flora para el pais %s, es: %d \n", p[i].Npais, cfa);
				printf("La cantidad de fauna para el pais %s, es: %d \n", p[i].Npais, cf);	
				ban = 1;
			}
		}	
		if(ban == 0){
			printf("El nombre del pais ingresado no fue encontrado \n");
		}	
		Sleep(3000);
		system("cls");
	  	printf("Ingrese el nombre del pais o termine con fin \n");
		gets(b);
		fflush(stdin);
	}
		Sleep(3000);
		system("cls");
		
	for(int i=0; i<d; i++){
			if(strcmp(p[i].Npais,"BRASIL")==0){
				n = p[i].s;
				incrementa(n);
			}	
	}
	int c = 0;
	for(int i=0; i<d; i++){
			if(strcmp(p[i].Npais,"BRASIL")==0  || strcmp(p[i].Npais,"ARGENTINA")==0) {
				n = p[i].s;
			indicar(n, c);
			}	
	}
	printf("La cantidad de petiribi en Argentina y Brazil es: %d \n", c);
}
