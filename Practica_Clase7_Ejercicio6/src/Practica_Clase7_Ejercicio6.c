/*
 ============================================================================
 Name        : Practica_Clase7_Ejercicio6.c
 Author      : Damriel
 Version     : Clase 7 - Ejercicio 6
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 EJERCICIO 6:
 Hacer un programa con el siguiente menu:
 1) Ingresar nuevo nombre (no acepta nombres repetidos).
 2) Listar todos los nombres.
 3) Ordenar por orden alfabetico.
 4) Borrar nombre (se ingresa el nombre y si se encuentra se elimina de la lista).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define SIZENOMBRES 21
#define QTY_NOMBRES 10

int inicializarArray(char array[], int sizeArray);
int imprimirArray(char array[], int sizeArray);

int main(void) {
	setbuf(stdout,NULL); //ESTO VA SIEMPRE EN WINDOWS
	int opcion;
	char listaNombres[SIZENOMBRES][QTY_NOMBRES];

	inicializarArray(listaNombres[SIZENOMBRES], QTY_NOMBRES); //carga un '@' en todos los espacios del array nombres[]

	do
	{
		if(!utn_getIntLimited(&opcion, "*** MENU PRINCIPAL ***\n"
									   "1-Ingresar nuevo nombre\n"
									   "2-Listar los nombres\n"
									   "3-Ordenar alfabeticamente\n"
									   "4-Borar nombre\n"
									   "5-Salir\n"
									   "Elija una opcion: ","La opcion ingresada no es valida.\n",1,5,10))
		{
			switch(opcion)
			{
				case 1:
					//Funcion cargar nombre
					break;
				case 2:
					imprimirArray(listaNombres[SIZENOMBRES], QTY_NOMBRES);
					break;
				case 3:
					//Funcion Ordenar nombres
					break;
				case 4:
					//Funcion borrar nombre
					break;
			}
		}
	}while(opcion!=5);
	printf("Hasta la proxima!");
	return EXIT_SUCCESS;
}


int inicializarArray(char array[], int qtyArray)
{
	int i;
	if(array!=NULL && qtyArray>0)
	{
		for(i=0;i<qtyArray;i++)
		{
			strncpy(&array[i],"EMPTY",qtyArray);
		}
	}
	return 0;
}

int imprimirArray(char array[], int qtyArray)
{
	int i;
	if(array!=NULL && qtyArray>0)
	{
		for(i=0;i<qtyArray;i++)
		{
			printf("%s\n",&array[i]);
		}
	}
	return 0;
}



