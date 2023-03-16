#include <stdio.h>
#include <malloc.h>
#include <windows.h>

struct alumno
{
	char nombre[41];
	char carrera[5]; // LCC LSI TUPW
	struct alumno *sig;
};
typedef struct alumno *puntero_alu;

struct libro
{
	int codigo;
	puntero_alu alumnos;
	struct libro *sig;
};
typedef struct libro *puntero_lib;

void Cargar(puntero_lib &xcab, const char texto[])
{
	int codigo;
	printf("\n  -Ingrese el c\xA2\x64igo del %slibro (finaliza con 0): ", texto);
	scanf("%d", &codigo);
	if(codigo != 0)
	{
		puntero_lib nuevo = (puntero_lib)malloc(sizeof(struct libro));
		nuevo->codigo = codigo;
		nuevo->alumnos = NULL;
		nuevo->sig = xcab;
		xcab = nuevo;
		Cargar(xcab, texto);
	}
	return;
}

int Menu()
{
		int i;
	printf("\n\n \xDA");
	for(i=1; i<=76; i++)
		printf("\xC4");
	printf("\xBF\n \xB3");
	for(i=1; i<=29; i++)
		printf(" ");
	printf("ESCOJA UNA OPCI\xE0N");
	for(i=1; i<=30; i++)
		printf(" ");
	printf("\xB3\n \xB3   1 - Agregar alumno/a a la cola de espera.");
	for(i=1; i<=32; i++)
		printf(" ");
	printf("\xB3\n \xB3   2 - Ingresar nuevo libro para pr\x82stamo.");
	for(i=1; i<=34; i++)
		printf(" ");
	printf("\xB3\n \xB3   3 - Procesar pr\x82stamo de libro.");
	for(i=1; i<=42; i++)
		printf(" ");
	printf("\xB3\n \xB3   4 - Mostrar alumnos/as de una carrera indicada en espera de un libro.");
	for(i=1; i<=4; i++)
		printf(" ");
	printf("\xB3\n \xB3");
	for(i=1; i<=76; i++)
		printf(" ");
	printf("\xB3\n \xB3   0 - Salir.");
	for(i=1; i<=63; i++)
		printf(" ");
	printf("\xB3\n \xC0");
	for(i=1; i<=76; i++)
		printf("\xC4");
	printf("\xD9\n     Opci\xA2n: ");
	scanf("%d", &i);
	return i;
}

void Agregar(puntero_lib xcab)
{
	int codigo;
	printf("\n  -Introduzca el c\xA2\x64igo del libro (0 para finalizar): ");
	scanf("%d", &codigo);
	if(codigo != 0)
	{
		puntero_lib aux = xcab;
		int i = 0;
		while(aux != NULL && i==0)
			if(aux->codigo != codigo)
				aux = aux->sig;
			else
				i = 1;
		if(aux == NULL)
			printf("   C\xA2\x64igo de libro no encontrado.");
		else
		{
			puntero_alu nuevo = (puntero_alu)malloc(sizeof(struct alumno));
			printf("  -Nombre del alumno/a: ");
			fflush(stdin);
			gets(nuevo->nombre);
			printf("  -Carrera: ");
			fflush(stdin);
			gets(nuevo->carrera);
			nuevo->sig = aux->alumnos;
			aux->alumnos = nuevo;
		}
		Agregar(xcab);
	}
	return;
}

void Eliminar(puntero_lib xcab, int xcod)
{
	if(xcab != NULL)
	{
		if(xcab->codigo == xcod)
		{
			puntero_alu anterior = NULL, aux = xcab->alumnos;
			if(aux != NULL)
			{
				while(aux->sig != NULL)
				{
					anterior = aux;
					aux = aux->sig;
				}
				printf("\n   Se prestar\xA0 el libro a %s perteneciente a la carrera %s", aux->nombre, aux->carrera);
				free(aux);
				if(anterior != NULL)
					anterior->sig = NULL;
				else
					xcab->alumnos = NULL;
			}
			else
				printf("\n   No hay alumnos/as en espera del libro.");
		}
		else
			Eliminar(xcab->sig, xcod);
	}
	else
		return;
}

void Mostrar(puntero_lib xcab, int xcod, char xcarr[5], puntero_alu aux)
{
	if(xcab != NULL)
	{
		if(xcab->codigo == xcod)
		{
			if(aux != NULL)
			{
				if(strcmp(aux->carrera, xcarr) == 0)
				{
					Mostrar(xcab, xcod, xcarr, aux->sig);
					printf("\n     \xFA%s.", aux->nombre);
				}
				else
					Mostrar(xcab, xcod, xcarr, aux->sig);
			}
			else
				printf("\n  Alumnos en lista de espera:");
		}
		else if(xcab->sig == NULL)
			Mostrar(xcab->sig, xcod, xcarr, NULL);
		else
			Mostrar(xcab->sig, xcod, xcarr, xcab->sig->alumnos);
	}
}

void Limpiar(puntero_lib xcab)
{
	if(xcab != NULL)
	{
		puntero_alu aux = xcab->alumnos;
		while(aux != NULL)
		{
			aux = aux->sig;
			free(xcab->alumnos);
			xcab->alumnos = aux;
		}
		Limpiar(xcab->sig);
		free(xcab);
	}
	else
		return;
}

main(void)
{
	SetConsoleTitle("Ejercicio 9 (Pr\xA0\x63tico 5)");
	int opcion, codigo;
	puntero_lib cabeza = NULL;
	Cargar(cabeza, "");
	do
	{
		opcion = Menu();
		switch(opcion)
		{
			case 1: Agregar(cabeza);
					break;
					
			case 2: Cargar(cabeza, "nuevo ");
					break;
					
			case 3:	if(cabeza != NULL)
					{
						printf("\n  -Digite el c\xA2\x64igo del libro devuelto: ");
						scanf("%d", &codigo);
						Eliminar(cabeza, codigo);
					}
					else
						printf("\n   No hay libros cargados.");
					break;
					
			case 4:	if(cabeza != NULL)
					{
						printf("\n  -Ingrese el c\xA2\x64igo del libro: ");
						scanf("%d", &codigo);
						char carrera[5];
						printf("  -Escriba la carrera: ");
						fflush(stdin);
						gets(carrera);
						Mostrar(cabeza, codigo, carrera, cabeza->alumnos);
					}
					else
						printf("\n   No hay libros cargados.");
					break;
					
			case 0:	Limpiar(cabeza);
					break;
		
			default: printf("     Opci\xA2n inv\xA0lida.\n\n");
					 break;
		}
	}while(opcion != 0);
}
