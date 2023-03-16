/*Práctica Operativa
Una Clínica procesa la información de los servicios que brinda.
Por cada paciente que se atiende, se registra su nombre, DNI, código de Obra social (1..6) y para un estudio estadístico
también se registra su edad y sexo. Además, se conoce el nombre de las 6 obras sociales con las que la clínica trabaja.
Utilizando estructuras adecuadas y funciones óptimas
a) Cargar en una lista la información de los pacientes.
b) Realizar una función recursiva que devuelva al principal el total de pacientes atendidos y cantidad de mujeres
mayores de 50 años. Hacer una sola función donde un resultado debe ser calculado con la función y el otro con un
parámetro.
c) Ingresar un DNI por teclado y si se encuentra cambiar su código de Obra Social leyendo uno nuevo por teclado.
d) Generar a partir de la lista un arreglo que contenga el nombre de cada Obra Social y la cantidad de pacientes
atendidos por la misma. Mostrar la información almacenada en el arreglo.*/

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

