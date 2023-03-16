#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#define CANT_TUTORIAL 10

struct nodo
{
	long int dni;
	struct nodo *sig;
};

typedef struct nodo *puntero;

typedef struct
{
	char titulo[41];
	puntero inscripto;
}tutorial;

int Menu()
{
	int i;
	printf("\n \xDA");
	for(i=1; i<=76; i++)
		printf("\xC4");
	printf("\xBF\n \xB3");
	for(i=1; i<=29; i++)
		printf(" ");
	printf("ESCOJA UNA OPCI\xE0N");
	for(i=1; i<=30; i++)
		printf(" ");
	printf("\xB3\n \xB3   1 - Cargar datos de tutorial.");
	for(i=1; i<=44; i++)
		printf(" ");
	printf("\xB3\n \xB3   2 - Registrar incripciones.");
	for(i=1; i<=46; i++)
		printf(" ");
	printf("\xB3\n \xB3   3 - Eliminar inscripci\xA2n.");
	for(i=1; i<=48; i++)
		printf(" ");
	printf("\xB3\n \xB3   4 - Mostrar t\xA1tulo y cantidad de inscriptos de un tutorial.");
	for(i=1; i<=14; i++)
		printf(" ");
	printf("\xB3\n \xB3   5 - Informar el/los tutoriales en los que se anot\xA2 una persona.");
	for(i=1; i<=10; i++)
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

void Crear(tutorial xcong[CANT_TUTORIAL], int i)
{
	if(i < CANT_TUTORIAL)
	{
		xcong[i].inscripto = NULL;
		Crear(xcong, i+1);
	}
}

void Cargar(tutorial xcong[CANT_TUTORIAL])
{
	int num;
	printf("\n  -Ingrese el n\xA3mero de tutorial: ");
	scanf("%d", &num);
	if(num > 0 && num <= CANT_TUTORIAL)
	{
		printf("  -Digite el t\xA1tulo del tutorial: ");
		fflush(stdin);
		gets(xcong[num-1].titulo);
		Cargar(xcong);
	}
	else
		return;
}

void Registrar(tutorial xcong[CANT_TUTORIAL])
{
	long int dni;
	printf("\n  -Ingrese el DNI del inscripto (finaliza con 0): ");
	scanf("%ld", &dni);
	if(dni != 0)
	{
		int num;
		printf("  -Ingrese el N\xA7 de tutorial al que asistir\xA0: ");
		scanf("%d", &num);
		puntero nuevo = (puntero)malloc(sizeof(struct nodo));
		nuevo->dni = dni;
		nuevo->sig = xcong[num-1].inscripto;
		xcong[num-1].inscripto = nuevo;
		Registrar(xcong);
	}
	else
		return;
}

void Eliminar(puntero &inscripto, puntero aux, long int xdni)
{
	if(inscripto != NULL)
	{
		if(xdni == inscripto->dni)
		{
			if(aux != NULL)
				aux->sig = inscripto->sig;
			else
				aux = inscripto->sig;
			free(inscripto);
			inscripto = aux;
			return;
		}
		else
			Eliminar(inscripto->sig, inscripto, xdni);
	}
	else
		printf("\n  El DNI ingresado no fue encontrado.");
}

void Mostrar(puntero inscripto, char titulo[41], int cant)
{
	if(inscripto != NULL)
		Mostrar(inscripto->sig, titulo, cant+1);
	else
		printf("\n  Tutorial \"%s\" con %d inscriptos.", titulo, cant);
}

void Buscar(tutorial xcong[CANT_TUTORIAL], int i, long int xdni)
{
	if(i < CANT_TUTORIAL)
	{
		Buscar(xcong, i+1, xdni);
		puntero aux = xcong[i].inscripto;
		while(aux != NULL)
		{
			if(aux->dni == xdni)
				printf("    Tutorial N\xA7 %d \"%s\".\n", i+1, xcong[i].titulo);
			aux = aux->sig;
		}
	}
	else
		printf("\n  Tutoriales en los que se inscribi\xA2:\n");
}

void Liberar(tutorial xcong[CANT_TUTORIAL], int i)
{
	if(i < CANT_TUTORIAL)
	{
		while(xcong[i].inscripto != NULL)
			Eliminar(xcong[i].inscripto, NULL, xcong[i].inscripto->dni);
		Liberar(xcong, i+1);
	}
}

main(void)
{
	SetConsoleTitle("Ejercicio 7 (Pr\xA0\x63tico 5)");
	int opcion, num;
	long int dni;
	tutorial congreso[CANT_TUTORIAL];
	Crear(congreso, 0);
	do
	{
		opcion = Menu();
		switch(opcion)
		{
			case 1: Cargar(congreso);
					break;
					
			case 2: Registrar(congreso);
					break;

			case 3: printf("\n  -Ingrese el DNI del inscripto a eliminar (0 para terminar): ");
					scanf("%ld", &dni);
					if(dni != 0)
					{
						printf("\n  -Indique el N\xA7 de tutorial en el que se inscribi\xA2: ");
						scanf("%d", &num);
						Eliminar(congreso[num-1].inscripto, NULL, dni);
					}
					break;

			case 4: printf("\n  -Digite cualquier n\xA3mero de tutorial: ");
					scanf("%d", &num);
					Mostrar(congreso[num-1].inscripto, congreso[num-1].titulo, 0);
					break;
					
			case 5: printf("\n  -Ingrese el DNI de la persona: ");
					scanf("%ld", &dni);
					Buscar(congreso, 0, dni);
					break;
					
			case 0:	Liberar(congreso, 0);
					break;
					
			default: if(opcion != 0)
						printf("     Opci\xA2n inv\xA0lida.\n\n");
					 break;
		}
	}while(opcion != 0);
}
