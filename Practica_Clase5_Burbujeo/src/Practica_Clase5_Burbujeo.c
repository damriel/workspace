/*
 ============================================================================
 Name        : Practica_Clase5_Burbujeo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define SIZEEDADES 9

int printArrayInt(int* pArray, int limite);

int ordenarArrayInt(int* pArray, int limite);

int main(void) {
	int edades[SIZEEDADES] = {54, 26, 93, 17, 77, 31, 44, 55, 27};
	int respuesta;

	printArrayInt(edades, SIZEEDADES);

	respuesta = ordenarArrayInt(edades, SIZEEDADES);
	if(respuesta>0)
	{
		printf("\n    Iteraciones: %d\n\n",respuesta);
	}

	printArrayInt(edades, SIZEEDADES);

	respuesta = ordenarArrayInt(edades, SIZEEDADES);
	if(respuesta>0)
	{
		printf("\n    Iteraciones: %d\n\n",respuesta);
	}

	return EXIT_SUCCESS;
}

/**
 * \brief Imprime a modo de DEBUG la informacion de un array de enteros
 * \param pArray Es el puntero al array a ser ordenado
 * \param limite Es la longitud del array
 * \return 0 si OK o -1 para indicar un error
 *
 */
int printArrayInt(int* pArray, int limite)
{
	int retorno=-1;
	int i;
	if(pArray!=NULL && limite>=0)
	{
		retorno=0;
		for(i=0; i<limite; i++)
		{
			printf("[DEBUG]  Indice: %d - Valor: %d\n", i, pArray[i]);
		}
	}
	return retorno;
}

/**
 * \brief Ordena un array de enteros de manera descendente
 * \param pArray Es el puntero al array a ser ordenado
 * \param limite Es la longitud del array
 * \return Cantidad de iteraciones necesarias para ordenar si OK o -1 para indicar un error
 *
 */
int ordenarArrayInt(int* pArray, int limite)
{
	int retorno=-1;
	int flagSwap;
	int i;
	int contador=0;
	int buffer;
	int nuevoLimite;

	if(pArray!=NULL && limite>=0)
	{
		nuevoLimite=limite-1;
		do
		{
			flagSwap=0;
			for(i=0; i<nuevoLimite; i++)
			{
				if(pArray[i]<pArray[i+1])
				{
					flagSwap=1;
					buffer=pArray[i];
					pArray[i]=pArray[i+1];
					pArray[i+1]=buffer;
				}
				contador++;
			}
			nuevoLimite--;
		}while(flagSwap);
		retorno=contador;
	}
	return retorno;
}
