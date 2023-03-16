/*Ejemplo
El siguiente ejemplo genera un archivo de textos Mi_texto.txt. Para esto, se ingresa un texto por teclado y 
se supone que cada línea ingresada no supera los 200 caracteres.*/

#include <stdio.h>
#include <string.h>


int main(){
	char texto[200];
	FILE *archi;
	
	archi = fopen ("Ejemplo1.doc","w");
	printf("Ingrese el texto a almacenar en el archivo: \n\n\n");
	if (archi != NULL){
		gets(texto);
	while(stricmp(texto,"FIN")){
		fputs(texto,archi);
		gets(texto);
	}
	fclose(archi);
	}
	printf("\n\n  FIN DEL PROGRAMA   \n");
}
/*
Hola como estas?? todo bien ? tantos asdlaknsdlanfdlskdnfasdf
safdlknasdfkansdfljsf
fin
*/
