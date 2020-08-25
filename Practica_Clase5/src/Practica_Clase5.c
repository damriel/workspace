/*
 ============================================================================
 Name        : Practica_Clase5.c
 Author      : Damriel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define SIZEEDADES 5

//EJERCICIO: Pedirle al usuario 5 edades y luego imprimir las 5 edades.
//           Definir un array de 5 posiciones y usar la funcion "utn_" para pedir los valores

void imprimirArray(int listaDeEdades[], int sizeArray);

int calcularPromedio(int listaDeEdades[], int sizeArray, float* pPromedio);

int main(void) {
	setbuf(stdout,NULL); //ESTO VA SIEMPRE EN WINDOWS
	int edades[SIZEEDADES];
	int i;
	float promedio;

	for(i=0; i<SIZEEDADES; i++)
	{
		if(utn_getIntLimited(&edades[i], "Ingrese edad: ", "Error. La edad debe ser entre 1 y 120.\n", 1, 120, 3)==-1)
		{
			printf("\nSe acabaron los intentos.");
			edades[i] = 0;
		}
	}

	imprimirArray(edades, SIZEEDADES);

	if(calcularPromedio(edades, SIZEEDADES, &promedio)==0)
	{
		printf("\nEl promedio es: %f",promedio);
	}
	else
	{
		printf("No se pudo calcular el promedio.");
	}

	return EXIT_SUCCESS;
}

void imprimirArray(int listaDeEdades[], int sizeArray)
{
	int i;

	for(i=0; i<sizeArray; i++)
	{
		printf("%d ",listaDeEdades[i]);
	}
}

//EJERCICIO: Hacer una funcion que calcule el promedio de los valores del array que recibe y me devuelva el promedio. (no imprimir por consola)

int calcularPromedio(int listaDeEdades[], int sizeArray, float* pPromedio)
{
	int acumulador=0;
	int retorno=-1;
	int i;

	if(pPromedio!=NULL && sizeArray>0 && listaDeEdades!=NULL)
	{
		for(i=0; i<sizeArray; i++)
		{
			acumulador+=listaDeEdades[i];
		}
		*pPromedio = (float)acumulador/sizeArray;
		retorno=0;
	}
	return retorno;
}


