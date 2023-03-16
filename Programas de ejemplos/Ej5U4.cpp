#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Generar(int &N){
   N = rand()%20;
}
 
int cerear (int a[], int &i, int &N){
  if (i ==  N){
    return(0);
  }
  a[i]=0;
  i+=1;
  cerear(a,i,N);
}

int mostrar (int a[], int &i, int &N){
  if (i ==  N){
    return(0);
  }
  printf("POSICION %d, valor %d \n", i+1, a[i]);
  i+=1;
  mostrar(a,i,N);
}

int  carga (int a[], int &i, int &N){
  if (i ==  N){
    return(0);
  }
  a[i] = rand()%200-100;
  i+=1;
  carga(a,i,N);
}

int promedio (int a[], int &i, int &N, int &prom){
	if (i ==  N){
    return(0);
  }
  prom += a[i];
  i+=1;
  promedio(a, i, N, prom);
}

int carga(int a[],int &i,int &N,int b[],int &j, int &prom){
	if (i ==  N){
    return(0);
  }
   if (prom <= a[i]){
   	 b[j] = a[i];
     j+=1;
   }
   i+=1;
  carga(a,i,N,b,j, prom);
}
 
int Indicar (int a[], int &i, int &N, int &prom, int &c, int &c2){
	if (i ==  N){
    return(0);
  }  
    if (prom == a[i]){
   	c +=1;
   } else if (prom < a[i]) {
   	c2+=1;
   }
    i+=1;
   Indicar(a,i,N, prom, c, c2); 
}

int buscar (int a[], int &i, int &N, int &prom, int &aux){
	if (i ==  N){
    return(0);
  }  
    if (prom == a[i]){
     	printf("Se encontro el numero buscado en la posicion %d \n", i+1);
     	aux = 5;
     	i = N;
 	} else {
 		i+=1;
	}
	buscar(a,i, N, prom, aux);
}

void ordenar (int arr[], int &N, int &inf, int &sup){ 	
	int t[N];
	int x,piv,m,n;
	if (inf < sup){
		x=(inf+sup)/2;
		piv=arr[x];
		 	for( x= inf;x<=sup;x++)
				t[x]=arr[x];
				m=inf; n=sup;
			for(x=inf; x<= sup; x++)
				if (t[x] < piv){
				arr[m]=t[x];
				m=m+1;
			} else if (t[x] > piv){
				arr[n]=t[x];
				n=n-1;
			}
			for( x=m;x<=n;x++)
			arr[x]=piv;
			m-=1;
			n+=1;
			ordenar(arr, N, inf , m);
	     	ordenar(arr, N, n , sup);
		}
	return;
}

int main(){
    fflush(stdout);
    srand(time(NULL));
    int N;
    Generar(N);
    printf("%d \n", N);
    printf("\n");
    int a[N], i = 0, b[N], j=0, prom = 0, M=0, count = 0, count2=0, num, aux = 1, inf = 0, sup;
    cerear(a, i, N);
    i=0;
    mostrar(a,i,N);
    i=0;
    carga(a,i,N);
    i=0;
    printf("\n");
    printf("Carga aleatoria \n");
    mostrar(a,i,N);
    i=0;
    promedio(a, i, N, prom);
    prom = prom / N;
    printf("\n");
    printf("Promedio %d \n", prom);
    i=0;
    carga(a,i,N,b,j, prom);
    M=j;
    j=0;
    printf("\n");
    printf("Carga subarreglo \n");
    mostrar(b,j, M);
    j=0;
    Indicar(b,j, M, prom, count, count2);
    printf("\n");
    printf("La cantidad de componentes igual al promedio son: %d y las mayores  al promedio son: %d \n", count, count2);
    j=0;
    printf("\n");
    printf("Ingrese el numero a buscar \n");
    scanf("%d", &num);
    buscar(b,j, M, num, aux);
    if(aux != 5){
    	printf("El numero buscado no se encuentra en el sub arreglo \n");
	}
    j=0;
    aux = 1 ;
    sup = M;
	ordenar(b, M, inf, sup);
    j=0;
    printf("\n");
    printf("Subarreglo  Ordenado\n");
    mostrar(b,j, M);
	j=0;
    printf("\n");
    printf("Busqueda ordenada \n");
    
    buscar(b,j, M, num, aux);
    if(aux != 5){
    	printf("El numero buscado no se encuentra en el sub arreglo \n");
	}
}


