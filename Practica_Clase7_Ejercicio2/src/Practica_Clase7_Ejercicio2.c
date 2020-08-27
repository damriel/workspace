/*
 ============================================================================
 Name        : Practica_Clase7_Ejercicio2.c
 Author      : Damriel
 Version     : Clase 7 - Ejercicio 2 (EJERCICIOS 3 Y 4 FUERON DE COMPLETAR LA FUNCION getFloat)
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Crear un programa que permita registrar el valor de temperatura maxima de cada dia de un mes.
 Definir un array de floats de 31 posiciones. Cada posicion corresponderá a un dia del mes.
 Hacer un menu con dos opciones, 1-Imprimir Array / 2-Cargar Array.
 Al elegir la opcion 1 se imprimirá el indice y el valor de cada posicion del array.
 Al elegir la opcion 2 que le pida al usuario que el numero del dia (1 a 31) y luego un valor de temperatura.
 Almacenar el valor en el indice correspondiente. Ambas opciones deben volver al menu principal.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define TEMPSIZE 31

int imprimirArray(float* temperaturas, int sizeArray);
int cargarArray(float* array, int sizeArray);

int main(void) {
	setbuf(stdout,NULL); //ESTO VA SIEMPRE EN WINDOWS
	int opcion;
	float temperaturas[TEMPSIZE]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	do
	{
		if(!utn_getIntLimited(&opcion,"*** MENU PRINCIPAL ***\n1-Imprimir array.\n2-Cargar array.\n3-Salir.\nElija una opcion: ","Error. La opcion ingresada no es valida.\n",1,3,5))
		{
			switch(opcion)
			{
				case 1:
					imprimirArray(temperaturas,TEMPSIZE); //FUNCION IMPRIMIR ARRAY
					break;
				case 2:
					if(cargarArray(temperaturas,TEMPSIZE)) //FUNCION CARGAR ARRAY
					{
						printf("Se cargaron los datos exitosamente!\n\n");
					}
					else
					{
						printf("No se pudieron cargar correctamente los datos.\n");
					}
					break;
			}
		}
	}while(opcion!=3);
	printf("Hasta la proxima!");
	return EXIT_SUCCESS;
}

int imprimirArray(float* array, int sizeArray)
{
	int i;

	for(i=0;i<sizeArray;i++)
	{
		printf("Dia: %d | Temperatura: %.2f\n",i+1,array[i]);
	}
	printf("Se a impreso el array existosamente!\n\n");
	return 1;
}

int cargarArray(float* array, int sizeArray)
{
	int retorno=0;
	int dia;
	float temperatura;
	if(!utn_getIntLimited(&dia,"Ingrese el numero del dia: ","Error.\n",1,31,2) && !utn_getFloatLimited(&temperatura,"Ingrese la temperatura: ","Error.\n",-40,50,2))
	{
		array[dia-1]=temperatura;
		retorno = 1;
	}
	return retorno;
}
