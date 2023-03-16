/*Ejemplo 2*/

#include <stdio.h>
#include <string.h>
int main(){
	char texto[200];
	FILE *archi;
	archi = fopen("Ejemplo2.txt","r");
	if (archi != NULL){
		printf("\n TEXTO INGRESADO \n ");
		while(!feof(archi)){
			fgets(texto,200, archi);
			puts(texto);
		}
		fclose(archi);
	}
}
