#include <stdio.h>
#include <conio.h>
#define N 6

void lenguajes(){
	
	printf("\n Lenguajes de programacion \n");
	printf("\n 1 - JavaScript \n");
	printf(" 2 - HTML \n");
	printf(" 3 - CSS \n");
	printf(" 4 - Java \n");
	printf(" 5 - Python \n");
	printf(" 6 - C \n");
	return;
}

void cereo(int arr[N], int inf, int sup){
    if(sup >= inf){ //caso base 
        arr[inf] = 0;
        cereo(arr,inf+1,sup);
    }else return;
}

void carga(int arr[N],int i){
    if ((i) && (i < 7)){
        arr[i-1]++;
        printf("Ingrese el lenguaje elegido (finaliza en 0) ");
        scanf("%d",&i);
        return(carga(arr,i));
    }
    else return;        
}

void menos4mil(int arr[N],int inf, int sup){
    if(sup>=inf){
        if(arr[inf]<4/*4000*/){
            printf("\nel lenguaje %d tiene menos de 4 mil encuestados ",inf+1);
            return menos4mil(arr,inf+1,sup);
        }else return menos4mil(arr,inf+1,sup);
    }else return;
}

int masel(int arr[N],int inf, int sup,int max){
    static int i;
    if(sup>=inf){
        if(arr[inf]>max){
            max=arr[inf];
            i=inf;
            return (masel(arr,inf+1,sup,max));
        }else return (masel(arr,inf+1,sup,max));
    }else return(i);
}

int menos5mas9(int arr[N],int inf, int sup,int cont5,int &cont9){
    if(sup>=inf){
        if(arr[inf]<5/*4000*/){
            cont5++;
            return menos5mas9(arr,inf+1,sup,cont5,cont9);
        }else if(arr[inf]>9/*9000*/){
            cont9++;
            return menos5mas9(arr,inf+1,sup,cont5,cont9);
        }
        else return menos5mas9(arr,inf+1,sup,cont5,cont9);
    }else return(cont5);
}

int totalEncuestados(int a[N],int inf,int sup, int xt){
    if(inf<=sup){
       xt+=a[inf];
       return totalEncuestados(a,inf+1,sup,xt);
    } else return xt;
}

int main(){
    int arr[N], Len, mayA9 = 0;

    lenguajes();
    cereo(arr,0,N-1);
    printf("\nIngrese el lenguaje elegido (finaliza en 0) ");
    scanf("%d",&Len);
    carga(arr,Len);
    menos4mil(arr,0,N-1);
    printf("\nEl lenguaje mas elegido fue el %d \n", masel(arr,0,N-1,0)+1);
    printf("\nEl total de encuestas realizadas fue de %d \n",totalEncuestados(arr,0,N-1,0));
    printf("\n %d lenguajes fueron elegidos por menos de 5 mil encuestados \n",menos5mas9(arr,0,N-1,0,mayA9));
    printf("\n %d lenguajes fueron elegidos por mas de 9 mil encuestados \n",mayA9);
    
    getch();
}
