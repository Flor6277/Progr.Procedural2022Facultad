/*Hacer tabla para seguros/sectores,
arreglo de promotores que almacene cada sector,
registro de seguros con tipo,nombre y precio*/

#include <stdio.h> /* printf scanf gets puts */
#include <stdlib.h> /* rand, srand*/
#include <string.h>

#define N 3
#define M 10
#define Z 7

struct seguros{
    char tipo;
    char nombre [30];
    float precio;

};

void cerear(int T[N][Z]){
    int i,j;
        for (i=0;i<N;i++){
            for(j=0;j<Z;j++){
                T[i][j]=0;
            }
        }
}

void carga_sector(int p[M]){
    int i,sector;
    for(i=0;i<M;i++){
        printf("Ingrese sector del promotor %i (30..37): ",i+1);
        fflush(stdin);
        scanf("%i",&sector);
            while((sector<30)||(sector>37)){
                printf("El sector no existe, ingrese sector del promotor %i nuevamente. (30..37): ",i+1);
                fflush(stdin);
                scanf("%i",&sector);
              }
        p[i]=sector-30;
    }
}

void carga_datos(seguros s[N]){
    int i;
    for(i=0;i<N;i++){
        printf("Ingrese tipo de seguro (a,b,c): ");
        fflush(stdin);
        scanf("%c",&s[i].tipo);
        printf("Ingrese nombre de seguro: ");
        fflush(stdin);
        gets(s[i].nombre);
        printf("Ingrese precio del seguro: ");
        fflush(stdin);
        scanf("%f",&s[i].precio);
    }
}

void carga_ventas(seguros s[N], int p[M], int T[N][Z]){
    int i,j,sector,tipo;
    printf("Ingrese numero de promotor (Finalizar carga con 0): ");
    scanf("%i",&sector);
    fflush(stdin);
        while(sector!=0){
            printf("Ingrese tipo de seguro: ");
            scanf("%c",&tipo);
            fflush(stdin);
            switch(tipo){
                case 'a':
				T[0][p[sector-1]]=T[0][p[sector-1]]+1;
				break;
                case 'b':
				T[1][p[sector-1]]=T[1][p[sector-1]]+1;
				break;
                case 'c':
				T[2][p[sector-1]]=T[2][p[sector-1]]+1;
				break;
            }
            printf("Ingrese numero de promotor (Finalizar carga con 0): ");
            scanf("%i",&sector);
            fflush(stdin);
        }
}

void mostrar (int T[N][Z])
{
    printf("TABLA \n");
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<Z;j++)
        {
            printf("%i ",T[i][j]); //M[%d][%d]
        }
        printf("\n");
    }
}

int maximo(int T[N][Z], int tipo){
    int max,j,max_ind;
    max=T[tipo][0];
    max_ind=0;
    for(j=1;j<Z;j++){
        if(T[tipo][j]>max){
            max=T[tipo][j];
            max_ind=j;
        }
    }
    return(max_ind);
}

int cant_prom(int p[M], int T[N][Z],int tipo){
    int i,cant,sector;
    cant=0;
    sector=maximo(T,tipo);
    for(i=0;i<M;i++){
        if(p[i]==sector){
            cant=cant+1;
        }
    }
    return(cant);
}

void sector_mayor(seguros s[N], int p[M], int T[N][Z]){
    int i,j,tipo;
        printf("Ingrese seguro a buscar: ");
        scanf("%c",&tipo);
        fflush(stdin);
        switch(tipo){
                case 'a':
				printf("El sector con mas cantidad de seguros a es el %i\n",maximo(T,0)+30);
				printf("La cantidad de promotores del sector es: %i\n",cant_prom(p,T,0));
				break;
                case 'b':
				printf("El sector con mas cantidad de seguros b es el %i\n",maximo(T,1)+30);
				printf("La cantidad de promotores del sector es: %i",cant_prom(p,T,1));
				break;
                case 'c':
				printf("El sector con mas cantidad de seguros c es el %i\n",maximo(T,2)+30);
				printf("La cantidad de promotores del sector es: %i",cant_prom(p,T,2));
				break;
            }
}

void mas_consumido(int p[M], int T[N][Z]){
    int i,sector,max,max_indice;
    max=T[0][0];
    printf("Ingrese numero de sector: ");
    scanf("%i",&sector);
    fflush(stdin);
        for(i=0;i<N;i++){
            if(T[i][sector-30]>max){
                max=T[i][sector-30];
                max_indice=i;
            }
        }
    switch(max_indice){
        case 0:
            printf("El seguro mas consumido es el A\n");
            break;
        case 1:
            printf("El seguro mas consumido es el B\n");
            break;
        case 2:
            printf("El seguro mas consumido es el C\n");
            break;
    }
}

void total_venta(seguros s[N],int T[N][Z]){
    int i,j;
    int acum=0;
        for(i=0; i<N; i++){
            for(j=0; j<Z; j++){
            acum += T[i][j];
        }
        puts(s[i].nombre);
        printf("Importe total vendido %.2f \n",(acum*s[i].precio));
        acum = 0;
    }
}


int menu()
{
	int d;
	printf("Elija una opcion: \n");
    printf("1 - cargar datos. \n");
    printf("2 - carga sector de promotor. \n");
    printf("3 - cargar ventas. \n");
    printf("4 - Inciso B  \n");
    printf("5 - Inciso C  \n");
    printf("6 - Inciso D \n");
    printf("7 - mostrar tabla \n");
    printf("0 - salir/terminar ejecucion. \n");
    scanf("%d",&d);
    fflush(stdin);
    return d;
}

int main()
{
	/*Declaraciones*/
	seguros s[N];
	int p[M];
	int T[N][Z];
	int op;
	cerear(T);
	/*Inicializaciones*/
	//cerear(a);
	/*Programa*/
	do
	{
		op=menu();
		switch(op)
		{
			case 0: break;
			case 1:{
				carga_datos(s);
				break;
			}
			case 2:{
				carga_sector(p);
				break;
			}
			break;
			case 3:{
				carga_ventas(s,p,T);
				break;
			}

			case 4:{
			    sector_mayor(s,p,T);
			    break;
            }
            case 5:{
			    mas_consumido(p,T);
			    break;
            }
            case 6:{
				total_venta(s,T);
				break;
			}
            case 7:{
				mostrar(T);
				break;
			}
			case 99: break;
		}
	}
	while(op!=0);
}


