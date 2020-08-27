/*
 ============================================================================
 Name        : Practica_Clase7_Ejercicio5.c
 Author      : Damriel
 Version     : Clase 7 - Ejercicio 5
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO 5:
 a) Realizar un programa que pida 5 numeros int al usuario y los almacene en un array.
    Luego ejecutar la funcion borrarImpares() pasandole el array y que debera reemplazar los numeros impares por cero.

 b) Luego imprimir el array para chequear el funcionamiento.

 c) Ordenar el array de menor a mayor y volver a imprimirlo.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define SIZENUMEROS 5

int inicializarArray(int array[], int sizeArray);
int imprimirArray(int array[], int sizeArray);
int borrarImpares(int array[], int sizeArray);
int ordenarArrayInt(int array[], int sizeArray);

int main(void) {
	setbuf(stdout,NULL); //PONER SIEMPRE EN WINDOWS
	int numeros[SIZENUMEROS];

	inicializarArray(numeros, SIZENUMEROS);
	printf("\nArray original:\n");
	imprimirArray(numeros, SIZENUMEROS);
	printf("\n\n");
	borrarImpares(numeros, SIZENUMEROS);
	printf("Array sin Impares:\n");
	imprimirArray(numeros, SIZENUMEROS);
	printf("\n\n");
	ordenarArrayInt(numeros, SIZENUMEROS);
	printf("Array Ordenado:\n");
	imprimirArray(numeros, SIZENUMEROS);

	return EXIT_SUCCESS;
}

int inicializarArray(int array[], int sizeArray)
{
	int i;
	if(array!=NULL && sizeArray>0)
	{
		for(i=0;i<sizeArray;i++)
		{
			utn_getIntSimple(&array[i],"Ingresar numero: ","Error.\n");
		}
	}
	return 0;
}

int imprimirArray(int array[], int sizeArray)
{
	int i;
	if(array!=NULL && sizeArray>0)
	{
		for(i=0;i<sizeArray;i++)
		{
			printf("%d\n",array[i]);
		}
	}
	return 0;
}

int borrarImpares(int array[], int sizeArray)
{
	int i;
	if(array!=NULL && sizeArray>0)
	{
		for(i=0;i<sizeArray;i++)
		{
			if(array[i]%2!=0)
			{
				array[i]=0;
			}
		}
	}
	return 0;
}

int ordenarArrayInt(int array[], int sizeArray)
{
	int i;
	int flagSwap;
	int bufferInt;
	int nuevoSize;

	if(array!=NULL && sizeArray>0)
	{
		nuevoSize=sizeArray-1;
		do
		{
			flagSwap=0;
			for(i=0;i<nuevoSize;i++)
			{
				if(array[i]>array[i+1])
				{
					flagSwap=1;
					bufferInt = array[i];
					array[i] = array[i+1];
					array[i+1] = bufferInt;
				}
			}
			nuevoSize--;
		}while(flagSwap);
	}
	return 0;
}
