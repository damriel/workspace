/*
 * Alumno.c
 *
 *  Created on: 27 ago. 2020
 *      Author: BiT_SOLUCIONES_iT
 */
#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"

int imprimirArrayAlumnos(Alumno* pArray, int limite)
{
	int retorno=-1;
	int i;

	if(pArray!=NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			if(!pArray[i].isEmpty)
			{
				printf("Nombre: %s - Legajo: %d - Altura: %f\n", pArray[i].nombre, pArray[i].legajo, pArray[i].altura);
			}
		}
		retorno=0;
	}

	return retorno;
}

int inicializarArrayAlumnos(Alumno* pArray, int limite)
{
	int retorno=-1;
	int i;

	if(pArray!=NULL && limite>0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i].isEmpty=1;
		}
		retorno=0;
	}

	return retorno;
}
