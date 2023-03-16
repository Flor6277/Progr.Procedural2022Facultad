/*Pr�ctica Operativa
Una Cl�nica procesa la informaci�n de los servicios que brinda.
Por cada paciente que se atiende, se registra su nombre, DNI, c�digo de Obra social (1..6) y para un estudio estad�stico
tambi�n se registra su edad y sexo. Adem�s, se conoce el nombre de las 6 obras sociales con las que la cl�nica trabaja.
Utilizando estructuras adecuadas y funciones �ptimas
a) Cargar en una lista la informaci�n de los pacientes.
b) Realizar una funci�n recursiva que devuelva al principal el total de pacientes atendidos y cantidad de mujeres
mayores de 50 a�os. Hacer una sola funci�n donde un resultado debe ser calculado con la funci�n y el otro con un
par�metro.
c) Ingresar un DNI por teclado y si se encuentra cambiar su c�digo de Obra Social leyendo uno nuevo por teclado.
d) Generar a partir de la lista un arreglo que contenga el nombre de cada Obra Social y la cantidad de pacientes
atendidos por la misma. Mostrar la informaci�n almacenada en el arreglo.*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

typedef char cadena[20];
struct nodo{
	cadena nombPaciente;
	int cod,DNI,edad;
	cadena sexo;
	struct nodo *sig;
}; typedef struct nodo *puntero;

struct arreglo{
	int OS;
    puntero siguiente;
};

void crear(puntero &xp){
	xp = NULL;
}

