/*
 ============================================================================
 Name        : Practica_Clase7_Ejercicio1.c
 Author      : Damriel
 Version     : Clase 7 - Ejercicio 1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Escribir la funcion calcularMayor(). La funcion rebe recibir dos numeros Int y devolver por referencia el numero mayor.
 La funcion debe retornar 1 si encontro un mayor o un 0 si ambos numeros son iguales.
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int calcularMayor(int* pResultado, int numero1, int numero2);

int main(void) {
	setbuf(stdout,NULL); //ESTO VA SIEMPRE EN WINDOWS
	int resultado;
	int num1, num2;

	utn_getIntSimple(&num1,"Ingrese el primer numero: ","Error. Lo que ingresaste no es un numero.\n");
	utn_getIntSimple(&num2,"Ingrese el segundo numero: ","Error. Lo que ingresaste no es un numero.\n");

	if(calcularMayor(&resultado,num1,num2)==0)
	{
		printf("Los numeros son iguales.\n");
	}
	else
	{
		printf("El mayor es: %d\n",resultado);
	}

	return EXIT_SUCCESS;
}

int calcularMayor(int* pResultado, int numero1, int numero2)
{
	int retorno=0;
	if(pResultado!=NULL)
	{
		if(numero1>numero2)
		{
			*pResultado=numero1;
			retorno=1;
		}
		else if(numero2>numero1)
		{
			*pResultado=numero2;
			retorno=1;
		}
	}
	return retorno;
}










